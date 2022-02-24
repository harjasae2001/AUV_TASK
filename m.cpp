#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

Mat imgHSV, mask;
int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;

int main(){

    string path = "/home/harjasae2001/Desktop/WhatsApp Image 2022-02-08 at 19.03.39.jpeg";
    Mat img = imread(path);
    // Mat imgHSV = cvtColor(img, cv.COLOR_BGR2HSV);
    cvtColor(img, imgHSV, COLOR_BGR2HSV);

namedWindow("TrackBars", (640, 200));
createTrackbar("Hue Min", "TrackBars", &hmin, 179);
createTrackbar("Hue Max", "TrackBars", &hmax, 179);
createTrackbar("Sat Min", "TrackBars", &smin, 255);
createTrackbar("Sat Max", "TrackBars", &smax, 255);
createTrackbar("Val Min", "TrackBars", &vmin, 255);
createTrackbar("Val Max", "TrackBars", &vmax, 255);


    while(true){
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);


        inRange(imgHSV, lower, upper, mask);
        imshow("Image", img);
        imshow("Image HSV", imgHSV);
        imshow("Image HSV", imgHSV);
        imshow("Image Mask", mask);

        waitKey(10);
    }
    return 0;
}
    
