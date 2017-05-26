require 'open3'

RSpec.shared_context 'exec' do
  let(:args) { [] }

  let(:exec) do
    Open3.capture3("#{BIN_ROOT}/#{bin}", *args)
  end

  let(:stdout) { exec[0] }
  let(:stderr) { exec[1] }
  let(:status) { exec[2] }
end
