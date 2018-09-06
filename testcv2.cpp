#include <iostream> 
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
using namespace std;
using namespace cv;
int main()
{
	VideoCapture cap(0);           //打开摄像头
	//VideoCapture cap("***.avi"); // 如果要打开本地视频采用  
	if(!cap.isOpened())
	{
		cout<<"fail to open!"<<endl;
		return -1;     //检测一下摄像头是否打开
	}  
	Mat frame; 
	while(1){
		cap>>frame;        //读取当前帧
		// 此处可添加图像处理算法，对图像进行处理，当然了，我们可以不做任何操作，只打开一下摄像头
		imshow("Qitas OpenCV CAM", frame);    //显示一下
		if(waitKey(20) >=0) break;       // 等待按键，跳出循环
	}
	return 0;
}