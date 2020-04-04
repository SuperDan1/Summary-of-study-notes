# vagrant教程

## 简介

* Vagrant 是一个用来构建和管理虚拟机环境的工具。Vagrant 有着易于使用的工作流，并且专注于自动化，降低了开发者搭建环境的时间，提高了生产力。解决了“在我的机器上可以工作”的问题。
* Vagrant 是为了方便的实现虚拟化环境而设计的，使用 Ruby 开发，基于 VirtualBox 等虚拟机管理软件的接口，提供了一个可配置、轻量级的便携式虚拟开发环境。使用 Vagrant 可以很方便的就建立起来一个虚拟环境，而且可以模拟多台虚拟机，这样我们平时还可以在开发机模拟分布式系统。
* 团队新员工加入，常常会遇到花一天甚至更多时间来从头搭建完整的开发环境，而有了Vagrant，只需要直接将已经打包好的 package（里面包括开发工具，代码库，配置好的服务器等）拿过来就可以工作了，这对于提升工作效率非常有帮助。

### 为什么选择 Vagrant

Vagrant 提供了一个易于配置，可重复使用，兼容的环境，通过一个单一的工作流程来控制，帮助你和团队最大化生产力和灵活性。
为了实现 Vagrant 的魔力，Vagrant 站在了巨人的肩膀上。虚拟机的配置基于 VirtualBox，VMware，AWS 或者其他提供商。然后一些配置工具，比如 shell 脚本，Chef 或者 Puppet 可以自动化地在虚拟机安装并配置软件。

### 对于开发者人员

如果你是一个开发者，Vagrant 将在一个一次性的、一致的环境中隔离依赖项及其配置，而不会影响你习惯使用的任何工具(编辑器、浏览器、调试器等)。一旦你或者其他人创建了一个 Vagrantfile，你只需要执行 vagrant up 所有的东西就自动安装和配置了。你团队中的其他成员使用同一个配置文件来创建开发环境，因此不管你工作在 Linux，MacOS X 还是 Windows， 所有团队的成员都可以在统一的环境环境中运行代码，这样就可以避免“在我的机器上可以工作”的问题。

### 对于运维人员

如果你是一个运维工程师或者 DevOps 工程师，Vagrant 给予你一个一次性的环境来开发和测试基础架构管理脚本。你可以使用本地虚拟机（比如 VirtualBox 或者 VMware）马上测试一些东西，比如 shell 脚本，Chef cookbooks，Puppet 模块等。然后，你可以用同样的配置在远程云上，比如 AWS 或者 RackSpace，来测试这些脚本。抛弃之前自定义脚本来回收 EC2 实例吧，停止使用 SSH 在各种机器之间跳来跳去，请开始使用 Vagrant 来给你的工作带来更多便利。

## 基本使用

* 新建目录，作为`vagrant`的根目录

* 导入`box`文件

  ```bash
  vagrant box add box_name box_address
  ```

* 初始化`box`，在根目录下自动生成`Vagrantfile`文件

  ```bash
  vagrant init
  ```

* 启动`box`

  ```bash
  vagrant up
  ```

* 连接虚拟机

  ```bash
  vagrant ssh hostname
  ```

* 查看 Vagrant 共享目录
  进入虚拟机后执行 `df -h` 可以看到 Vagrant 默认把宿主机 `Vagrantfile` 所在的目录和虚拟机的 `/vagrant` 目录共享，可以通过 `ls /vagrant/` 查看该目录内容，内容和宿主机对应目录一致。

## Vagrant 配置文件浅析

> 执行初始化后会在当前目录生成 `Vagrantfile` 文件，这个文件是非常重要的，一般给别人共享自己的环境时都是提供一个` Vagrantfile `和一个 `box` 文件，这样就可以很轻松地将环境共享给别人，别人能得到一模一样的统一的环境，这就是使用 Vagrant 的好处。

Vagrantfile 主要包括三个方面的配置，虚拟机的配置、SSH配置、Vagrant 的一些基础配置。Vagrant 是使用 Ruby 开发的，所以它的配置语法也是 Ruby 的，对于没有学过 Ruby 的朋友也没关系，根据例子模仿下就会了。
修改完配置后需要执行 vagrant reload 重启 VM 使其配置生效。

* box 名称设置

  ```bash
  config.vm.box = "base"
  ```

  上面这配置展示了 Vagrant 要去启用那个box作为系统，也就是前面我们输入 vagrant init <本地 box 名称>时所指定的 box，如果沒有输入 box 名称的话，那么默认就是 base。

* VM 相关配置
  VirtualBox 提供了 VBoxManage 这个命令行工具，可以让我们设定 VM，用`modifyvm`这个命令让我们可以设定 VM 的名称和内存大小等等，这里说的名称指的是在 VirtualBox 中显示的名称，我们也可以在 Vagrantfile 中进行设定；调用 VBoxManage 的 modifyvm 的命令，内存为 1024 MB。

  ```bash
  config.vm.provider "virtualbox" do |v|
    v.customize ["modifyvm", :id,  "--memory", "1024"]
  end
  ```

* 网络设置
    Vagrant 有两种方式来进行网络连接，一种是 host-only (主机模式)，这种模式下所有的虚拟系统是可以互相通信的，但虚拟系统和真实的网络是被隔离开的，虚拟机和宿主机是可以互相通信的，相当于两台机器通过双绞线互联。另一种是Bridge(桥接模式)，该模式下的 VM 就像是局域网中的一台独立的主机，可以和局域网中的任何一台机器通信，这种情况下需要手动给 VM 配 IP 地址，子网掩码等。我们一般选择 host-only 模式，配置如下：
    
    ```bash
    config.vm.network :private_network, ip: "11.11.11.11"
    1
    ```
    
* hostname 设置
  
    ```bash
    config.vm.hostname = "kubernetes"
    ```
    
* 不显示界面
  
    ```bash
    v.gui = false
    ```
    
* 端口转发
  对宿主机器上 8080 端口的访问请求 forward 到虚拟机的 80 端口的服务上：
  
  ```bash
  config.vm.network :forwarded_port, guest: 80, host: 8080
  ```

## Vagrant 常用命令清单

* 添加box `vagrant box add `
* 初始化 box `vagrant init` 
* 启动虚拟机 `vagrant up` 
* 登录虚拟机 `vagrant ssh` 
* 列出 Vagrant 当前 box 列表 `vagrant box list` 
* 删除相应的 box `vagrant box remove` 
* 停止当前正在运行的虚拟机并销毁所有创建的资源 `vagrant destroy` 
* 关机 `vagrant halt` 
* 把当前的运行的虚拟机环境进行打包为 box 文件 `vagrant package --base hostname –-output output.box` 
* 安装卸载插件 `vagrant plugin` 
* 重新启动虚拟机，重新载入配置文件 `vagrant reload` 
* 恢复被挂起的状态 `vagrant resume` 
* 获取当前虚拟机的状态 `vagrant status` 
* 挂起当前的虚拟机 `vagrant suspend` 
* 查看当前 vagrant 管理的所有 vm 信息 `vagrant global-status` 

# 搭建Ceph集群环境

## 配置环境，新建镜像

* vagrant启动一个虚拟机——`Centos7-standard`镜像

  ```bash
  vagrant up ceph-node1 
  ```

* 检查虚拟机状态

  ```
  vagrant status
  ```

* 登陆机器，查看主机名

  ```bash
  vagrant ssh ceph-node1
  ip addr show
  sudo fdisk -l
  exit
  ```
* 在操作系统防火墙内启动Ceph monitor、OSD以及MDS所需要的端口，在所有虚拟机上执行以下命令

  ```bash
  firewall-cmd --zone=public --add-port=6789/tcp --permanent
  firewall-cmd --zone=public --add-port=6800-7100/tcp --permanent
  firewall-cmd --reload
  firewall-cmd --zone=public --list-all
  
  # 也可以关闭防火墙
  # 查看防火墙状态
  systemctl status firewalld
  # 停止防火墙
  systemctl stop firewalld
  # 关闭开机自启
  systemctl disable firewalld
  # 查看firewalld服务的状态，已经是“disabled”，表明已经不是开机自启了
  systemctl list-unit-files | grep firewalld
  ```

* 在所有虚拟机上禁用SELINUX

  ```bash
  vim /etc/selinux/config
  # 修改文件中设置SELINUX=disabled
  ```

* 在所有ceph结点上添加ceph版本库并更新yum

  ```bash
  vim /etc/yum.repos.d/ceph.repo
  
  
  [Ceph]
  name=Ceph packages for $basearch
  baseurl=http://mirrors.aliyun.com/ceph/rpm-mimic/el7/$basearch
  enabled=1
  gpgcheck=1
  type=rpm-md
  gpgkey=https://mirrors.aliyun.com/ceph/keys/release.asc
  
  [Ceph-noarch]
  name=Ceph noarch packages
  baseurl=http://mirrors.aliyun.com/ceph/rpm-mimic/el7/noarch
  enabled=1
  gpgcheck=1
  type=rpm-md
  gpgkey=https://mirrors.aliyun.com/ceph/keys/release.asc
  
  [ceph-source]
  name=Ceph source packages
  baseurl=http://mirrors.aliyun.com/ceph/rpm-mimic/el7/SRPMS
  enabled=1
  gpgcheck=1
  type=rpm-md
  gpgkey=https://mirrors.aliyun.com/ceph/keys/release.asc
  
  rm -rf /etc/yum.repos.d/epel*
  wget -O /etc/yum.repos.d/epel.repo http://mirrors.aliyun.com/repo/epel-7.repo
  yum clean all && yum makecache fast && yum update -y && yum autoremove -y
  ```
  
* 在所有虚拟机上安装并配置ntp服务

  ```bash
  yum install ntp ntpdate -y
  # 读取时间
  timedatectl
  # 设置时区
  timedatectl set-timezone Asia/Shanghai
  # 与NTP服务器同步
  timedatectl set-ntp yes //yes或者no
  # 将硬件时钟调整为与本地时钟一致
  timedatectl set-local-rtc 1
  # 硬件时间设置成 UTC
  timedatectl set-local-rtc 1
  systemctl restart ntpdate.service
  systemctl restart ntpd.service
  systemctl enable ntpdate.service
  systemctl enable ntpd.service
  ```
  
* vagrant管理了一个官方的keypair, 预先放在box中一个公钥，私钥被vagrant管理着。vagrant up的时候，第一次登录虚拟机就是使用这个官方提供的keypair.
当登录入虚拟机前，vagrant在宿主机生成一个新的keypair, 然后将虚拟机中的公钥替换为新的这个，然后私钥放在宿主机。
  之所以有这个替换公钥的过程。是为了安全考虑，如果都使用官方的公钥，那么虚拟机可以被其他人登录。很不安全。
  
  ```bash
   # 将官网提供的公钥写入虚拟机中
   wget https://raw.githubusercontent.com/mitchellh/vagrant/master/keys/vagrant.pub -O   /home/vagrant/.ssh/authorized_keys
   chmod go-w /home/vagrant/.ssh/authorized_keys
  ```
  
* 关机，并打包

  ```bash
  vagrant halt
  vagrant package --base ceph-node1 --output Centos7-modify.box
  ```

## 搭建集群

### 开启虚拟机并设置

* 开启三台ceph-node结点，一台client结点

  ```bash
  vagrant up ceph-node1 ceph-node2 ceph-node3 client-node1
  ```

* 为ceph-node1配置ssh

  ```bash
  vagrant ssh ceph-node1
  su
  ssh-keygen
  ssh-copy-id root@ceph-node2
  ssh-copy-id root@ceph-node3
  ssh-copy-id root@client-node1
  ```

* 在ceph-node1上创建ceph集群

  ```bash
  yum install ceph-deploy python-setuptools -y
  mkdir /etc/ceph
  cd /etc/ceph
  ceph-deploy new ceph-node1
  ceph-deploy install ceph-node1 ceph-node2 ceph-node3 client-node1
  ceph-deploy admin ceph-node2 ceph-node3
  ```

* 查看ceph版本

  ```bash
  ceph -v
  ```

* 在`ceph-node1`上创建第一个`Ceph Monitor`

  ```bash
  ceph-deploy mon create-initial
  ```

* 检查集群健康

  ```bash
  ceph -s
  ceph health
  ```

### 创建OSD

* 检查OSD节点上所有可用的磁盘

  ```bash
  ceph-deploy disk list ceph-node1 
  ceph-deploy disk list ceph-node2 
  ceph-deploy disk list ceph-node3
  ```

* 使用zap选项删除所有osd节点上的分区

  ```bash
  ceph-deploy disk zap ceph-node1 /dev/sdb /dev/sdc /dev/sdd
  ceph-deploy disk zap ceph-node2 /dev/sdb /dev/sdc /dev/sdd
  ceph-deploy disk zap ceph-node3 /dev/sdb /dev/sdc /dev/sdd
  ```

* osd create子命令首先会准备磁盘，即默认地现用xfs文件系统格式化磁盘，然后会激活磁盘的第一、二个分区，分别作为数据分区和日志分区

  ```bash
  ceph-deploy osd create --data /dev/sdb ceph-node1
  
  ceph-deploy osd create --data /dev/sdc ceph-node1
  
  ceph-deploy osd create --data /dev/sdd ceph-node1
  
  ceph-deploy osd create --data /dev/sdb ceph-node2
  
  ceph-deploy osd create --data /dev/sdc ceph-node2
  
  ceph-deploy osd create --data /dev/sdd ceph-node2
  
  ceph-deploy osd create --data /dev/sdb ceph-node3
  
  ceph-deploy osd create --data /dev/sdc ceph-node3
  
  ceph-deploy osd create --data /dev/sdd ceph-node3
  ```

* 在ceph-node1上将公共网络地址添加到文件，同步cconfig

  ```bash
  vim /etc/ceph/ceph.conf
  public network = 192.168.1.0/24
  ceph-deploy --overwrite-conf config push ceph-node2 ceph-node3
  ```

* 使用`ceph-deploy`在ceph-node2、ceph-node3上创建一个monitor

  ```bash
  ceph-deploy mon create ceph-node2 
  ceph-deploy mon create ceph-node3
  ```

* 查看Ceph集群状态

  ```bash
  ceph -s
  ceph mon stat
  ```


### 基本命令

* 检查Ceph的安装状态

  ```bash
  ceph -s
  ```

* 观察集群健康状况

  ```bash
  ceph -w
  ```

* 导出Ceph monitor信息

  ```bash
  ceph mon dump
  ```

* 检查集群使用情况

  ```bash
  ceph df
  ```

* 检查Ceph monitor、OSD、PG状态

  ```bash
  ceph mon stat
  ceph odf stat
  ceph pg stat
  ```

* 列表PG

  ```bash
  ceph pg dump
  ```

* 列表Ceph存储池

  ```bash
  ceph osd lspools
  ```

* 查看OSD
  ```bash
  ceph-deploy osd list ceph-node1
  ```

* 检查Ceph monitor仲裁状态

  ```bash
  ceph quorum_status --format json-pretty
  ```

* 检查OSD的CRUSH map

  ```bash
  ceph osd tree
  ```

* 列表集群的认证秘钥

  ```bash
  ceph auth list
  ```

### 操作集群 
* 创建mgr结点

  ```bash
  ceph-deploy mgr create ceph-node1
  ```

* 创建存储池

  ```bash
  ceph osd pool create mypool 64 64
  ceph osd pool ls
  rados lspools
  ```

* 存储池添加支持的应用

  ```bash
  # 可以支持rbd、cephfs、rgw
  ceph osd pool application enable mypool rbd  --yes-i-really-mean-it
  ```

* 上传一个文件

  ```shell
  rados put issue /etc/issue --pool=mypool
  ```

* 获取一个文件

  ```shell
  #issue是对象的ID
  #my_issue是outfile，即输出文件名字
  #-p指定存储池
  rados get issue my_issue -p mypool
  ```

# 使用块存储

## 配置Ceph客户端

* 将Ceph配置文件复制到client-node1，确保推送到的ceph.conf文件的权限是644 

  ```bash
  ceph-deploy --overwrite-conf config push client-node1
  ```

* 客户机需要Ceph秘钥去访问Ceph集群。Ceph创建了一个默认用户`client.admin`，有足够的权限去访问Ceph集群，不建议把`client.admin`共享到所有其他客户端结点

  * 创建一个新的Ceph用户去访问特定的存储池：创建Ceph用户`client.rbd`，拥有访问rbd存储池的权限

    ```bash
    ceph auth get-or-create client.rbd mon 'allow r' osd 'allow class-read object_prefix rbd_children, allow rwx pool=rbd'
    ```

  * 为`client.rbd`用户添加秘钥，并推送到客户端

    ```bash
    ceph auth get-or-create client.rbd | ssh root@client-node1 tee /etc/ceph/ceph.client.rbd.keyring
    ```

  * 客户端通过提供用户名和秘钥检查Ceph集群状态

    ```bash
    cat /etc/ceph/ceph.client.rbd.keyring >> /etc/ceph/keyring
    ceph -s --name client.rbd
    ```

## 创建Ceph块设备

* 创建一个1024MB大小的RADOS块设备，取名为rbd1

  ```bash
  # 保存块设备镜像的默认存储池是"rbd"
  ceph osd pool create rbd 512
  rbd create rbd1 --size 1024 --name client.rbd
  # rbd pool init <pool-name>
  ```

* 检查rbd镜像的细节

  ```bash
  rbd --image rbd1 info --name client.rbd
  ```

## 映射Ceph块设备

* 映射块设备到`client-node1`

  ```bash
  rbd map --image rbd1 --name client.rbd
  ```

* 检查被映射的块设备

  ```bash
  rbd showmapped --name client.rbd
  ```

* 要使用这个快设备，我们需要创建并挂载一个文件系统

  ```bash
  fdisk -l /dev/rbd0
  mkfs.xfs /dev/rbd0
  mkdir /mnt/ceph-disk0
  mount /dev/rbd0 /mnt/ceph-disk0
  df -h /mnt/ceph-disk0
  ```

* 将数据写入块设备来进行检测

  ```bash
  dd if=/dev/zero of=/mnt/ceph-disk0/file0 count=100 bs=1M
  ```

* 要在机器重启后映射改块设备，需要在系统启动中添加init-rbdmap脚本，并且将Ceph用户和keying详细信息添加到rbdmap，最后更新/etc/fstab文件

  ```bash
  wget https://raw.githubusercontent.com/ksingh7/ceph-cookbook/master/rbdmap -O /etc/init.d/rbd.map
  # 在rbd.map中#!/bin/bash下添加以下两行
  #chkconfig: 2345 80 90
  #description:auto_run
  chmod +x /etc/init.d/rbd.map
  echo "rbd/rbd1 id=rbd,keyring=AQBSsIReiixqIBAA6O5rh/fBysy4RCTqqTFyrA==" >> /etc/ceph/rbdmap
  systemctl enable rbd.map
  ```

## 调整Ceph RBD大小

* 之前创建的RBD镜像大小为1GB，现在调整到2GB

  ```bash
  rbd resize --size 2048 --image rbd1 --name client.rbd
  ```

## Openstack

  



ceph auth get-or-create client.rbd mon 'allow r' osd 'allow class-read object_prefix rbd_children, allow rwx pool=rbd'



