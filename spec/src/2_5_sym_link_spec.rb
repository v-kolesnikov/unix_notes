RSpec.describe '2_5_sym_link' do
  describe 'exec' do
    include_context 'exec', '2_5_sym_link'

    context 'without arguments' do
      it_behaves_like 'exec silently' do
        let(:exitstatus) { 255 }
      end
    end

    context 'with symlink path as argument' do
      before do
        File.open('testfile', 'w') do |file|
          file.write 'Test data'
        end
        FileUtils.ln_s('testfile', 'testfile_link', force: true)
      end

      let(:args) { %w[testfile_link] }

      it { expect(stdout).to eq <<~EOF }
        Read symbolic link
        Symbolic link:
         testfile
        Read file
        Target file:
         Test data
      EOF

      it { expect(stderr).to be_empty }
      it { expect(status.exitstatus).to eq 0 }

      after { FileUtils.rm %w[testfile testfile_link] }
    end
  end
end
