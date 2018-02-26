#include<opencv2/opencv.hpp>   
//#include<opencv2/highgui/highgui.h>

using namespace std;
using namespace cv;
char name[30];

//边缘检测
int main()
{
    Mat img = imread("input.jpg");
    imshow("原始图", img);
    Mat DstPic, edge, grayImage;

    //创建与src同类型和同大小的矩阵
    DstPic.create(img.size(), img.type());

    //将原始图转化为灰度图
    cvtColor(img, grayImage, COLOR_BGR2GRAY);

	for(int i=1;i<=25;i+=2){
    //先使用3*3内核来降噪
    blur(grayImage, edge, Size(i, i));
    //运行canny算子
    Canny(edge, edge, 6, 18, 3);
	sprintf(name,"blur_%d_%d_canny_%d_%d_%d.jpg",i,i,3,9,3);
	imwrite(name,edge);
	}


}
