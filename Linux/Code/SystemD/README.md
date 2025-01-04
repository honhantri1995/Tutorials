# Installation
## Install systemd dev libs
```
# On Debian/Ubuntu
$ sudo apt-get install libsystemd-dev
# On Fedora
$ sudo dnf install systemd-devel
# On CentOS/RHEL
$ sudo yum install systemd-devel
```

## Compile code
Way 1: With g++ command
```
$ g++ *.cpp -o myservice -lsystemd
```

Way 2: With CMake
Use the CMakeLists.txt available.

## Create myservice.service file
Create a myservice.service file in /etc/systemd/system directory

# Usage
- To check log:
$ journalctl -x -u myservice -f -p 0..7

- To start our program with systemd without rebooting:
$ sudo systemctl start myservice

- To make systemd apply new changes for myservice.service after the file is modified:
$ sudo systemctl daemon-reload
$ sudo systemctl restart myservice

# Limitations
- Have to copy the "myservice" binary file to /usr/bin for the code to work correctly
  (I granded all permissions, but failed)

- Can redirect StandardOut/StandardError to "journal", but cannot redirect to a file, e.g.:
	StandardOutput=file:/home/centos/myservice.log
	StandardError=file:/home/centos/myservice.log
  (I granded all permissions, but failed)
