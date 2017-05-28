RSpec.describe '2_9' do
  describe 'exec' do
    include_context 'exec', '2_9'

    it { expect(stdout).to be_empty }
    it { expect(stderr).to be_empty }
    it { expect(status.exitstatus).to eq 0 }
  end
end
