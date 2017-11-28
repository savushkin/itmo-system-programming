VAGRANT_ROOT = File.dirname(File.expand_path(__FILE__))

Vagrant.configure("2") do |config|
  config.vm.box = "savushkin/freebsd-10.3-lab"
  config.vm.box_version = "1.0"

  config.ssh.shell = "sh"
  config.vm.base_mac = "08002704B948"
  config.vm.hostname = "lab"

  config.vm.network "private_network", type: "dhcp"
  config.vm.synced_folder File.join(VAGRANT_ROOT, "usr/src"), "/usr/src", type: "nfs" # or "rsync"
  config.vm.synced_folder File.join(VAGRANT_ROOT, "usr/obj"), "/usr/obj", type: "nfs" # or "rsync"
  config.vm.synced_folder VAGRANT_ROOT, "/vagrant", disabled: true

  config.vm.provider "virtualbox" do |vb|
     vb.gui = false
     vb.memory = "8192"
     vb.cpus = 2
  end
end
