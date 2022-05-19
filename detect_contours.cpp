#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

void getContours(Mat imgDil, Mat img){

    // {{Point(20, 30), Point(50,60)}, {}, {}}
    vector<vector<Point>> contours;

    vector<Vec4i> heirarchy;
    findContours(imgDil, contours, heirarchy, RETR_EXTERNAL, CHAIN_APPROX_TC89_KCOS);
            drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
    

    // for(int i = 0; i< contours.size(); i++){
    //    int area = contourArea(contours[i]);
    // //    cout<<area<<endl;

    //    vector<vector<Point>> conPoly(contours.size());
    //    vector<Rect> boundRect(contours.size());
    //    if(area > 10000)
    //    {
    //        float peri = arcLength(contours[i], true);
    //        approxPolyDP(contours[i], conPoly[i], 0.02*peri,true);
    //         cout<<conPoly[i].size()<<endl;
    //         // boundRect[i] = boundingRect(conPoly[i]);
    //         // rectangle(img,boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
    //    }
    // }
}

int main(){
    string path = "/home/harjasae2001/Desktop/opencv/WhatsApp Image 2022-02-08 at 19.03.39.jpeg";
    Mat img = imread(path);
    
    //Preprocessing
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(3,3), 3, 0);
    Canny(imgBlur, imgCanny, 25, 75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(imgCanny, imgDil, kernel);

    getContours(imgDil, img);

    imshow("Image", img);
    // imshow("Image Gray", imgGray);
    // imshow("Image Blur", imgBlur);
    // imshow("Image Canny", imgCanny);
    // imshow("Image Dilated", imgDil);


    waitKey(0);
    return 0;
}