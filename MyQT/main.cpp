#include <QCoreApplication>
#include "colorhistogram.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ColorHistogram objColorHistogram("..\\MyQT\\Data\\DSC_0278.JPG", 256);
    objColorHistogram.CalculateHistogram();
    objColorHistogram.WriteHistToCSV("..\\MyQT\\Data\\histData.csv");
    return a.exec();
}
