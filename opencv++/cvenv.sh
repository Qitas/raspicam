
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

# 下载OpenCV
wget -O opencv-3.4.3.zip https://github.com/Itseez/opencv/archive/3.4.3.zip
# 解压OpenCV
unzip opencv-3.4.3.zip
# 下载OpenCV_contrib
wget -O opencv_contrib-3.4.3.zip https://github.com/Itseez/opencv_contrib/archive/3.4.3.zip
# 解压OpenCV_contrib库：
unzip opencv_contrib-3.4.3.zip

cd opencv-3.4.3
# 新建release文件夹
mkdir release
# 进入release文件夹
cd release

sudo cmake -D CMAKE_BUILD_TYPE=RELEASE \
    -D CMAKE_INSTALL_PREFIX=/usr/local \
    -D OPENCV_EXTRA_MODULES_PATH=~/opencv_contrib-3.4.3/modules \
    -D INSTALL_PYTHON_EXAMPLES=ON \
    -D BUILD_EXAMPLES=ON ..

# 编译，以管理员身份，否则容易出错
sudo make
# 安装
sudo make install
# 更新动态链接库
sudo ldconfig