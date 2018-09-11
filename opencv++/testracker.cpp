#include <opencv2/opencv.hpp>
#include <opencv2/video.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/tracking/tracker.hpp>

using namespace cv;

void draw_rectangle(int event, int x, int y, int flags, void*);
Mat firstFrame;
Point previousPoint, currentPoint;
Rect2d bbox;
int main(int argc, char *argv[])
{
    VideoCapture capture;
    Mat frame;
    //frame = capture.open("/home/xiaorun/moving-object-detection/1.mp4");
      frame=capture.open(0);
    if(!capture.isOpened())
    {
        printf("can not open ...\n");
        return -1;
    }
    //获取视频的第一帧,并框选目标
    capture.read(firstFrame);
    if(!firstFrame.empty())
    {
        namedWindow("output", WINDOW_AUTOSIZE);
        imshow("output", firstFrame);
        setMouseCallback("output", draw_rectangle, 0);
        waitKey();
    }
    //使用TrackerMIL跟踪
    //Ptr<TrackerMIL> tracker= TrackerMIL::create();
    //Ptr<TrackerTLD> tracker= TrackerTLD::create();
    // Ptr<TrackerKCF> tracker = TrackerKCF::create();
    // Ptr<TrackerMedianFlow> tracker = TrackerMedianFlow::create();
      Ptr<TrackerBoosting> tracker= TrackerBoosting::create();
    capture.read(frame);
    tracker->init(frame,bbox);
    namedWindow("output", WINDOW_AUTOSIZE);
    while (capture.read(frame))
    {
        tracker->update(frame,bbox);
        rectangle(frame,bbox, Scalar(255, 0, 0), 2, 1);
        imshow("output", frame);
        if(waitKey(20)=='q')
        return 0;
    }
    capture.release();
    destroyWindow("output");
    return 0;
}

//框选目标
void draw_rectangle(int event, int x, int y, int flags, void*)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        previousPoint = Point(x, y);
    }
    else if (event == EVENT_MOUSEMOVE && (flags&EVENT_FLAG_LBUTTON))
    {
        Mat tmp;
        firstFrame.copyTo(tmp);
        currentPoint = Point(x, y);
        rectangle(tmp, previousPoint, currentPoint, Scalar(0, 255, 0, 0), 1, 8, 0);
        imshow("output", tmp);
    }
    else if (event == EVENT_LBUTTONUP)
    {
        bbox.x = previousPoint.x;
        bbox.y = previousPoint.y;
        bbox.width = abs(previousPoint.x-currentPoint.x);
        bbox.height =  abs(previousPoint.y-currentPoint.y);
    }
    else if (event == EVENT_RBUTTONUP)
    {
        destroyWindow("output");
    }
}