#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include<string.h>
using namespace cv;
using namespace std;

int main(int argc, char * argv[])
{
    //if (argc != 3) {
        //cerr << "./videoCreator path ext" << endl;
        //return -1;
    //}

    //Read sequence of images
    Size frameSize(224, 224);
    VideoCapture sequence("C:/Users/tumh/GTAImage2/%1d.png");
    if (!sequence.isOpened())
    {
       cerr << "Failed to open Image Sequence!\n" << endl;
       return -1;
    }
    //Write video
    VideoWriter oVideoWriter
    ("C:/Users/tumh/MyVideo.avi",CV_FOURCC('M','P','E','G'), 10, frameSize);
    Mat imageGrey;
    if(!oVideoWriter.isOpened())
    {
      cout<<"ERROR: Failed to write the video"<<endl;
      return -1;
    }
    Mat Image;
    do
    {
      sequence>>Image;
      //You added this test to avoid the empty image
      if(Image.empty())
         break;
      printf("Write image to video \n");
      oVideoWriter.write(Image);
    }
    while(!Image.empty());

    return 1;
}
