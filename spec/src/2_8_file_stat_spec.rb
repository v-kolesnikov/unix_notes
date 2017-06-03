RSpec.describe '2_8_file_stat' do
  describe 'exec' do
    include_context 'exec', '2_8_file_stat'

    let(:args) { %w[src/2_8_file_stat.c] }
    let(:stat) { File.stat('src/2_8_file_stat.c') }

    it do
      expect(stdout).to eq(<<~EOF)
        type = Normal file
        perm = 100644
        inode = #{stat.ino}
        nlink = #{stat.nlink}
        dev = (#{stat.dev_major}, #{stat.dev_minor})
        UID = #{stat.uid}
        GID = #{stat.gid}
        rdev = (#{stat.rdev_major}, #{stat.rdev_minor})
        size = #{stat.size}
        atime = #{stat.atime.strftime('%a %b %e %T %Y')}
        mtime = #{stat.mtime.strftime('%a %b %e %T %Y')}
        ctime = #{stat.ctime.strftime('%a %b %e %T %Y')}
      EOF
    end

    it { expect(stderr).to be_empty }
    it { expect(status.exitstatus).to eq 0 }
  end
end
