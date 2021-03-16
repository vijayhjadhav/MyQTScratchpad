#ifndef COLORHISTOGRAM_H
#define COLORHISTOGRAM_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <fstream>
using namespace cv;
using namespace std;

class ColorHistogram
{
public:
    ColorHistogram(const String &ImageFileName, int histSize);
    void CalculateHistogram();
    void WriteHistToCSV(const string &CSVFileName);

private:
    void ProcessImage();    

private:
    Mat blue_hist, green_hist, red_hist;
    std::vector<Mat> bgr_planes;
    int histSize;
    String ImageFileName;    
};

#endif // COLORHISTOGRAM_H
