#include <iostream>  
#include <vector>  
  
#include <opencv2/core/core.hpp>  
#include <opencv2/features2d/features2d.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/calib3d/calib3d.hpp>  
  
using namespace std;  
using namespace cv;  
  
  
  
int main()  
{  
    VideoCapture cap(0);  
    if (!cap.isOpened())  
    {  
        return -1;  
    }  
    namedWindow("result");  
    namedWindow("frame");  
    Mat frame;  
    Mat result, tmp;  
    Mat Y, Cr, Cb;  
    vector<Mat> channels;  
    bool stop = false;  
    while (!stop)  
    {  
  
        cap >> frame;                     //读取视频帧  
        frame.copyTo(tmp);                  //拷贝备份  
        /*转换颜色空间并分割颜色通道*/  
        cvtColor(tmp, tmp, CV_BGR2YCrCb);     
        split(tmp, channels);  
        Y = channels.at(0);  
        Cr = channels.at(1);  
        Cb = channels.at(2);  
      
        result.create(frame.rows, frame.cols, CV_8UC1);  
  
        /*遍历图像，将符合阈值范围的像素设置为255，其余为0*/  
        for (int j = 1; j < Y.rows - 1; j++)  
        {  
            uchar* currentCr = Cr.ptr< uchar>(j);  
            uchar* currentCb = Cb.ptr< uchar>(j);  
            uchar* current = result.ptr< uchar>(j);  
            for (int i = 1; i < Y.cols - 1; i++)  
            {  
                if ((currentCr[i] > 137) && (currentCr[i] < 175) && (currentCb[i] > 100) && (currentCb[i] < 118))  
                    current[i] = 255;  
                else  
                    current[i] = 0;  
            }  
        }  
  
        imshow("frame", frame);  
        imshow("result", result);  
  
        if (waitKey(30) >= 0)  
            stop = true;  
    }  
  
    cv::waitKey();  
    return 0;  
}  
