RSpec.describe '2_7_file_mode' do
  describe 'exec' do
    include_context 'exec', '2_7_file_mode'

    after { FileUtils.rm('my_file') }

    let(:login) { Etc.getlogin }
    let(:group) { Etc.getgrgid.name }

    it { expect(stdout).to match(<<~EOF) }
      -rwx------ *1 #{login} *#{group} *0 .* my_file
      -rws------ *1 #{login} *#{group} *0 .* my_file
      -rwx-----t *1 #{login} *#{group} *0 .* my_file
      -rwx--s--- *1 #{login} *#{group} *0 .* my_file
    EOF

    it { expect(stderr).to be_empty }
    it { expect(status.exitstatus).to eq 0 }
  end
end
