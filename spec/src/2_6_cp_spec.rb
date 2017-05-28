RSpec.describe '2_6_cp' do
  describe 'exec' do
    include_context 'exec', '2_6_cp'

    context 'without arguments' do
      it_behaves_like 'exec silently' do
        let(:exitstatus) { 255 }
      end
    end

    context 'with text file as argument' do
      before do
        File.open('testfile', 'w') { |file| file.write 'Test data' }
        exec
      end

      let(:args) { %w[testfile testfile_copy] }
      let(:copy) { File.open('testfile_copy') }

      it { expect(copy.read).to eq 'Test data' }

      it_behaves_like 'exec silently'

      after { FileUtils.rm %w[testfile testfile_copy] }
    end
  end
end
