RSpec.describe '2_7_file_mode' do
  describe 'exec' do
    include_context 'exec', '2_7_file_mode'

    after { FileUtils.rm('my_file') }

    it { expect(stdout).to match(<<~EOF) }
      -rwx------ .* my_file
      -rws------ .* my_file
      -rwx-----t .* my_file
      -rwx--s--- .* my_file
    EOF

    it { expect(stderr).to be_empty }
    it { expect(status.exitstatus).to eq 0 }
  end
end
