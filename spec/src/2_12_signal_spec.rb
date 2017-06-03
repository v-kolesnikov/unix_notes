RSpec.describe '2_12_signal' do
  describe 'exec' do
    include_context 'spawn', '2_12_signal'

    let(:signals) { %w[SIGINT SIGUSR2 SIGUSR1] }

    before do
      spawn
      sleep(0.01)
      signals.each do |signal|
        Process.kill(signal, pid)
        sleep(0.01)
      end
    end

    it { expect(stdout.read).to eq "Received signal SIGINT 2\n" }
    it { expect(stderr.read).to be_empty }
    it { expect(status).to be_signaled }
    it { expect(Signal.signame(status.termsig)).to eq 'USR1' }
  end
end
