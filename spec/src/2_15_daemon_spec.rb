RSpec.describe '2_15_daemon' do
  describe 'exec' do
    let(:pid_file) { '/tmp/daemon_skeleton.pid' }
    let(:fork_pid) { Integer(File.read(pid_file)) }

    include_context 'spawn', '2_15_daemon' do
      let(:args) { [pid_file] }
    end

    before do
      spawn
      sleep(0.01)
    end

    after do
      Process.kill('SIGTERM', fork_pid)
      FileUtils.rm(pid_file)
    end

    it 'success finished' do
      expect(status).to be_exited
      expect(status).to be_success
    end

    it 'create a new process' do
      expect { Process.kill(0, fork_pid) }.not_to raise_exception
    end

    it_behaves_like 'daemon' do
      subject(:pid) { fork_pid }
    end
  end
end
