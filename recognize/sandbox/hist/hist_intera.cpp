#include "iostream"
#include "cv.h"
#include "highgui.h"
#include "math.h"

using namespace std;

void mouseHandler(int event, int x, int y, int flags, void* param)
{
    IplImage *img0, *img1;
    img0 = (IplImage*)param;
    img1 = cvCreateImage(cvSize(img0->width, img0->height), img0->depth, img0->nChannels);
    cvCopy(img0, img1, NULL);

    CvFont font;
    uchar* ptr;
    char label[20];
    char label2[20];

    cvInitFont(&font, CV_FONT_HERSHEY_PLAIN, 1, 1, 0, 1, 1);    //初始化字体

    if(event == CV_EVENT_LBUTTONDOWN)
    {
        //读取像素
        ptr = cvPtr2D(img0, y, x, NULL);

        sprintf(label, "Grey Level:%d", ptr[0]);
        sprintf(label2, "Pixel: (%d, %d)", x, y);
        //调整显示位置
        if(img0->width - x <= 180 || img0->height - y <= 20)
        {
    cvRectangle(img1, cvPoint(x-180, y-40), cvPoint(x-10, y-10), CV_RGB(255, 0, 0), CV_FILLED, 8, 0);
    cvPutText(img1, label, cvPoint(x-180, y-30), &font, CV_RGB(255, 255, 255));
    cvPutText(img1, label2, cvPoint(x-180, y-10), &font, CV_RGB(255, 255, 255));
        }
        else
        {
    cvRectangle(img1, cvPoint(x+10, y-12), cvPoint(x+180, y+20), CV_RGB(255, 0, 0), CV_FILLED, 8, 0);
    cvPutText(img1, label, cvPoint(x+10, y), &font, CV_RGB(255, 255, 255));
    cvPutText(img1, label2, cvPoint(x+10, y+20), &font, CV_RGB(255, 255, 255));
        }
        //以鼠标为中心画点
        CvPoint centerPoint;
        centerPoint.x = x;
        centerPoint.y = y;
        cvCircle(img1, centerPoint, 3, CV_RGB(0, 0, 0), 1, 8, 3);

        cvShowImage("img", img1);
    }
}
int main()
{
    int exit = 0;
    int c;
    IplImage* img;
    img = cvLoadImage("input.jpg", 1);
    //img = cvLoadImage("hotel201.pgm", 1);
    assert(img);

    if(img->nChannels != 1) //判断是否为灰度图像，若不是，先转换为灰度图像
    {
        //转换为灰度图像
        IplImage* gray = cvCreateImage(cvGetSize(img), img->depth, 1); 
        cvCvtColor(img, gray, CV_BGR2GRAY); 
    }
    cvNamedWindow("img", 1);
    cvSetMouseCallback("img", mouseHandler, (void*)img);
    cvShowImage("img", img);
    //检测键盘输入，按Q键退出程序
    while(!exit)
    {
        c = cvWaitKey(0);
        switch(c)
        {
        case 'q':
            exit = 1;
            break;
        default:
            continue;
        }
    }
    cvDestroyAllWindows();
    cvReleaseImage(&img);
    return 0;
}
