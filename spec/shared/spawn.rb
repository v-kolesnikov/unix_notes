require 'open3'

RSpec.shared_context 'spawn' do |bin|
  let(:args) { [] }

  let(:spawn) do
    Open3.popen3(ENV, "#{BIN_ROOT}/#{bin}", *args)
  end

  let(:stdin)  { spawn[0] }
  let(:stdout) { spawn[1] }
  let(:stderr) { spawn[2] }
  let(:thread) { spawn[3] }
  let(:status) { thread.value }
  let(:pid) { thread.pid }
end
