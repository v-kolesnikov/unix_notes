RSpec.describe '2_6_cp' do
  describe 'exec' do
    include_context 'exec' do
      let(:bin) { '2_6_cp' }
    end

    context 'without arguments' do
      it { expect(stdout).to be_empty }
      it { expect(stderr).to be_empty }
      it { expect(status.exitstatus).to eq 255 }
    end

    context 'with text file as argument' do
      before do
        File.open('testfile', 'w') { |file| file.write 'Test data' }
        exec
      end

      let(:args) { %w[testfile testfile_copy] }
      let(:copy) { File.open('testfile_copy') }

      it { expect(stdout).to be_empty }
      it { expect(stderr).to be_empty }
      it { expect(status.exitstatus).to eq 0 }
      it { expect(copy.read).to eq 'Test data' }

      after { FileUtils.rm %w[testfile testfile_copy] }
    end
  end
end
