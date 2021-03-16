#include <QtTest>
#include <QCoreApplication>
#include "colorhistogram.h"
// add necessary includes here

class TestCSVFile : public QObject
{
    Q_OBJECT

public:
    TestCSVFile();
    ~TestCSVFile();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void test_case2();

};

TestCSVFile::TestCSVFile()
{

}

TestCSVFile::~TestCSVFile()
{

}

void TestCSVFile::initTestCase()
{

}

void TestCSVFile::cleanupTestCase()
{

}

void TestCSVFile::test_case1()
{
    ColorHistogram objColorHistogram("..\\QTTestHistogram\\Data\\DSC_0278.JPG", 256);
    objColorHistogram.CalculateHistogram();
    objColorHistogram.WriteHistToCSV("..\\QTTestHistogram\\Data\\histData.csv");

    ifstream ifile;
    ifile.open("..\\QTTestHistogram\\Data\\histData.csv");
    QVERIFY2(ifile.good(), "CSV File does not exist");
}

void TestCSVFile::test_case2()
{
    fstream fInput;
    fInput.open("..\\QTTestHistogram\\Data\\histData.csv", ios::in);
    vector<vector<string>> lines;
    string line;
    string word;
    while(getline(fInput, line) )
    {
        vector<string> row;
        stringstream ss(line);
        while(getline(ss, word, ',' ))
        {
            row.push_back(word);
        }

        // Verify if number of values in each row is 257(256 + 1(for color name))
        QVERIFY2(row.size() == 257, "Data inconsistency: Number of values != 257 ");

        lines.push_back(row);
    }

    // Verify if number of lines in the file are 3
    QVERIFY2(lines.size() == 3, "Data inconsistency: Number of rows != 3");

    size_t szLines = lines.size();
    int val;
    for(size_t i = 0; i < szLines; i++)
    {
        for(int j = 1; j < 257; j++ )
        {
            try
            {
                val = stoi(lines[i][j]);

            }
            catch (const std::invalid_argument& ia)
            {
                QVERIFY2(false, ia.what());
            }
        }
    }
}

QTEST_MAIN(TestCSVFile)

#include "tst_testcsvfile.moc"
