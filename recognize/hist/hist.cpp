#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
Mat getHistImg(const MatND& hist)
{
    double maxVal=0;
    double minVal=0;

    //找到直方图中的最大值和最小值
    minMaxLoc(hist,&minVal,&maxVal,0,0);
    int histSize=hist.rows;
    Mat histImg(histSize,histSize,CV_8U,Scalar(255));
    // 设置最大峰值为图像高度的90%
    int hpt=static_cast<int>(0.9*histSize);
    for(int h=0;h<histSize;h++)
    {
        float binVal=hist.at<float>(h);
        int intensity=static_cast<int>(binVal*hpt/maxVal);
		if(intensity!=0)
		cout<<h<<"--"<<intensity<<endl;
        line(histImg,Point(h,histSize),Point(h,histSize-intensity),Scalar::all(0));
    }

    return histImg;
}
int main()
{
    Mat Image=imread("input.jpg");
	Mat Output;
	 cvtColor(Image,Image,CV_BGR2GRAY);
    cv::Mat Img=Image; 
//	for (int i = 0; i < Img.rows; ++i)
//        {
//            uchar* datatemp = Img.ptr<uchar>(i);
//            for (int j = 0; j < Img.cols; ++j)
//            {
//                cout << (int)datatemp[j] << " ";
//                //cout << datatemp[j] << endl;
//            }
//			cout<<endl;
//        }
     const int channels[1]={0};
    const int histSize[1]={256};
    float hranges[2]={0,255};
    const float* ranges[1]={hranges};
    MatND hist;
	cout<<endl;
	cout<<hist;
    calcHist(&Image,1,channels,Mat(),hist,1,histSize,ranges);
	Output = getHistImg(hist);
	imwrite("output.jpg", Output);
    return 0;
}
