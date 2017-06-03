RSpec.shared_examples 'daemon' do
  subject(:pid) { Process.pid }

  let(:gid) { Process.getpgid pid }
  let(:sid) { Process.getsid  pid }

  it 'has gid same as pid' do
    expect(gid).to eq pid
  end

  it 'has sid same as pid' do
    expect(sid).to eq pid
  end
end
