
# sudo raspi-config   // 进入后打开摄像头、SSH
sudo apt update
sudo apt upgrade
sudo rpi-update

#安装OpenCV的相关工具
sudo apt install build-essential cmake git pkg-config -y

#安装OpenCV的图像工具包
sudo apt install libjpeg8-dev -y
sudo apt install libtiff5-dev -y
sudo aptinstall libjasper-dev -y
sudo apt install libpng12-dev -y

#安装视频I/O包
sudo apt install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev -y

#安装gtk2.0和优化函数包

sudo apt install libgtk2.0-dev -y
sudo apt install libatlas-base-dev gfortran -y