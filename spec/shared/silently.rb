RSpec.shared_examples 'exec silently' do
  let(:exitstatus) { 0 }
  it { expect(stdout).to be_empty }
  it { expect(stderr).to be_empty }
  it { expect(status.exitstatus).to eq exitstatus }
end
