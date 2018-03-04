#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
int threshold_value = 0;
int threshold_type = 3;
int const max_value = 255;
int const max_type = 4;
int const max_BINARY_value = 255;
Mat src, src_gray, dst;
const char* window_name = "Threshold Demo";
const char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
const char* trackbar_value = "Value";
const char* th_min= "th_min";
const char* th_max= "th_max";
const char* blur="blur";
int const th_min_max=30;
int const th_max_max=30;
int const blur_max=13;
int th_min_d=10;
int th_max_d=10;
int blur_d=3;
void Threshold_Demo( int, void* );
int main( int argc, char** argv )
{
  String imageName("input.jpg"); // by default
  if (argc > 1)
  {
      imageName = argv[1];
  }
  src = imread( imageName, IMREAD_COLOR ); // Load an image
  if( src.empty() )
    { return -1; }
  cvtColor( src, src_gray, COLOR_BGR2GRAY ); // Convert the image to Gray
  namedWindow( window_name, WINDOW_AUTOSIZE ); // Create a window to display results
//  createTrackbar( trackbar_type,
//                  window_name, &threshold_type,
//                  max_type, Threshold_Demo ); // Create Trackbar to choose type of Threshold
//  createTrackbar( trackbar_value,
//                  window_name, &threshold_value,
//                  max_value, Threshold_Demo ); // Create Trackbar to choose Threshold value
  createTrackbar(th_min,window_name,&th_min_d, th_min_max, Threshold_Demo );
  createTrackbar(th_max,window_name,&th_max_d, th_max_max, Threshold_Demo );
  createTrackbar("blur",window_name,&blur_d,blur_max, Threshold_Demo );
  Threshold_Demo( 0, 0 ); // Call the function to initialize
  for(;;)
    {
      char c = (char)waitKey( 20 );
      if( c == 27 )
    { break; }
    }
}
void Threshold_Demo( int, void* )
{
  /* 0: Binary
     1: Binary Inverted
     2: Threshold Truncated
     3: Threshold to Zero
     4: Threshold to Zero Inverted
  */
//  threshold( src_gray, dst, threshold_value, max_BINARY_value,threshold_type );
//
	if (blur_d%2==0)	{blur_d++;}
  GaussianBlur( src_gray, dst, Size( blur_d,blur_d ), 0, 0 );
  Canny(dst, dst,th_min_d,th_max_d,3 );

  imshow( window_name, dst );
}
