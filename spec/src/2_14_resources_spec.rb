RSpec.describe '2_14_resources' do
  describe 'exec' do
    include_context 'exec', '2_14_resources'

    it { expect(stdout).to match(<<~EOF) }
      RLIMIT_CORE     .*
      RLIMIT_CPU      .*
      RLIMIT_DATA     .*
      RLIMIT_FSIZE    .*
      RLIMIT_NOFILE   .*
      RLIMIT_STACK    .*
      (RLIMIT_NPROC.*)?(\nRLIMIT_RSS.*)?(\nRLIMIT_MEMLOCK.*)?(\nRLIMIT_VMEM.*)?
    EOF

    it { expect(stderr).to be_empty }
    it { expect(status.exitstatus).to eq 0 }
  end
end
