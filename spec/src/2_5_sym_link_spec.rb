RSpec.describe '2_5_sym_link' do
  describe 'exec' do
    include_context 'exec' do
      let(:bin) { '2_5_sym_link' }
    end

    context 'without arguments' do
      it { expect(stdout).to be_empty }
      it { expect(stderr).to be_empty }
      it { expect(status.exitstatus).to eq 255 }
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
