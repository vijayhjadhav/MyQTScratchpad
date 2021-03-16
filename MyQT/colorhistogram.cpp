#include "colorhistogram.h"

ColorHistogram::ColorHistogram(const String &InputImageFileName, int histSize)
                             :ImageFileName(InputImageFileName), histSize(histSize)
{

}

void ColorHistogram::ProcessImage()
{
    Mat srcImage = imread(ImageFileName, IMREAD_COLOR);
    split(srcImage, bgr_planes);
}

void ColorHistogram::CalculateHistogram()
{
    ProcessImage();

    float range[] = { 0, 256 }; //the upper boundary is exclusive
    const float* histRange = { range };
    bool uniform = true, accumulate = false;

    // Calculate the Histogram values
    calcHist(&bgr_planes[0], 1, 0, Mat(), blue_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[1], 1, 0, Mat(), green_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[2], 1, 0, Mat(), red_hist, 1, &histSize, &histRange, uniform, accumulate);
}

void ColorHistogram::WriteHistToCSV(const string &CSVFileName)
{
    // Create and open the .csv file
    ofstream outputFile;
    outputFile.open(CSVFileName);

    // Generate the lines for Red, Green and Blue
    string sRed, sGreen, sBlue;
    sRed.append("Red");
    sGreen.append("Green");
    sBlue.append("Blue");

    for (int i = 0; i < histSize; i++)
    {
        sRed.append("," + to_string(red_hist.at<float>(i)));
        sGreen.append("," + to_string(green_hist.at<float>(i)));
        sBlue.append("," + to_string(blue_hist.at<float>(i)));
    }

    // Write the lines to .csv file
    outputFile << sRed << endl << sGreen << endl << sBlue << endl;

    // Close the file
    outputFile.close();

}
