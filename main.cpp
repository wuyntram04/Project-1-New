#include<iostream>
#include <iomanip>
#include"input.h"
#include<fstream>
#include"Dataset.h"
#include"StatsDataSet.h"

using namespace std;

void showMenu();
void showIntro();
void insertMenu();
void deleteMenu();
//Dataset ds;
StatsDataSet ds;


int main()
{
    showIntro();

    do
    {
        system("cls");

        if (ds.getSize() == 0) {
            cout << "\n\tAddress of Dynamic array: 0000000000000000";   // lưu ý
        }
        else {
            cout << "\n\tAddress of Dynamic array: " << ds.rawAddress(); // lưu ý
        }
        cout << "\n\tDataset: (" << ds.getType() << ")\n\t";
        ds.display();
        showMenu();
        
        switch (toupper(inputChar("\n\tOption: ")))
            {
            case '0': exit(0);
            case '1':
            {
                system("cls");

                cout << "\n\n\tIn statistics, Population refers to the entire group of data";
                cout << "\n\tpoints that a study is interested in, while a Sample is a";
                cout << "\n\tsubset of that population that is actually used in the study.";

                cout << "\n\n\tConfigure Dataset Menu";
                cout << "\n\t" << string(80, char(205));
                cout << "\n\t\tA. sample";
                cout << "\n\t\tB. population";
                cout << "\n\t" << string(80, char(196));
                cout << "\n\t\tR. return";
                cout << "\n\t" << string(80, char(205));

                switch (toupper(inputChar("\n\t\tOption: ")))
                {
                case 'A':
                {
                    cout << "\n\tData Set configured for Sample";
                    ds.setSample(true);
                }
                break;

                case 'B':
                {
                    cout << "\n\tData Set configured for Population";
                    ds.setSample(false);
                }
                break;
                case 'R': break;
                }
            }
            break;
            case '2':
            {
                insertMenu();
                break;
            }
            case '3':
                if (ds.CheckEmpty()) break;
                deleteMenu();
                break;
            case 'A':
                if (ds.CheckEmpty()) break;
                cout << "\n\tMinimum \t\t = " << ds.Minimum();
                break;
            case 'B':
                if (ds.CheckEmpty()) break;
                cout << "\n\tMaximum \t\t = " << ds.Maximum();
                break;
            case'C':
                if (ds.CheckEmpty()) break;
                cout << "\n\tRange \t\t = " << ds.Range();
                break;
            case'D':
                cout << "\n\tSize \t\t = " << ds.getSize();
                break;
            case'E':
                if (ds.CheckEmpty()) break;
                cout << "\n\tSum \t\t = " << ds.Sum();
                break;
            case 'F':
                if (ds.CheckEmpty()) break;
                cout << "\n\tMean \t\t = " << ds.Mean();
                break;
            case 'G':
                if (ds.CheckEmpty()) break;
                cout << "\n\tMedian \t\t = " << ds.Median();
                break;
            case'H':
                if (ds.CheckEmpty()) break;
                ds.Mode(cout);
                break;
            case 'I':
                if (ds.CheckEmpty()) break;
                cout << "\n\tStandard Deviation = \t" << ds.StandDeviation();
                break;
            case 'J':
                if (ds.CheckEmpty()) break;
                cout << "\n\tVariance = \t" << ds.Variance();
                break;
            case 'K':
                if (ds.CheckEmpty()) break;
                cout << "\n\tMidrange = \t" << ds.MidRange();
                break;
            case 'L':
                if (ds.CheckEmpty()) break;
                cout << "\n\tQuartiles  \t\tQuartiles: ";
                cout << "\n\t\t\t\tQ1 --> " << fixed << setprecision(1) << ds.Q1();
                cout << "\n\t\t\t\tQ2 --> " << fixed << setprecision(1) << ds.Median();
                cout << "\n\t\t\t\tQ3 --> " << fixed << setprecision(1) << ds.Q3();
                break;
            case 'M':
                if (ds.CheckEmpty()) break;
                cout << "\n\tInterquartile Range = \t" << ds.IQR();
                break;
            case 'N':
            {
                if (ds.CheckEmpty()) break;

                cout << "\n\tOutlinears  = \t ";
                int* out = nullptr;
                int m = 0;
                double lower = 0.0, upper = 0.0;

                ds.Outliners(out, m, lower, upper);

                if (m == 0)
                {
                    cout << "none";
                }
                else
                {

                    for (int i = 0; i < m; ++i)
                    {
                        if (i > 0)
                            cout << out[i];
                    }

                }
                if (out) delete[] out;
                break;

            }
            case'O':
                if (ds.CheckEmpty()) break;
                cout << "\n\tSum of Square \t\t = " << ds.SumOfSquare();
                break;
            case 'P':
                if (ds.CheckEmpty()) break;
                cout << "\n\tMean Absolute Deviation \t\t = " << ds.MeanAbsoluteDeviation();
                break;
            case 'Q':
                if (ds.CheckEmpty()) break;
                cout << "\n\tRoot Mean Square \t\t = " << ds.RootMeanSquare();
                break;
            case 'R':
                if (ds.CheckEmpty()) break;
                cout << "\n\t Standard Error of the Mean \t\t = " << ds.StandardError();
                break;
            case 'S':
                if (ds.CheckEmpty()) break;
                cout << "\n\tSkewness \t\t = " << ds.Skewness();
                break;
            case 'T':
                if (ds.CheckEmpty()) break;
                cout << "\n\tKurtosis \t\t = " << setprecision(9) << ds.Kurtosis();
                break;
            case 'U':
                if (ds.CheckEmpty()) break;
                cout << "\n\tKurtosis Excess \t\t = " << setprecision(9) << ds.KurtosisExcess();
                break;
            case 'V':
                if (ds.CheckEmpty()) break;
                cout << "\n\tCoefficient of Variation \t\t = " << ds.CoefficientOfVariation();
                break;
            case 'W':
                if (ds.CheckEmpty()) break;
                cout << "\n\tRelative Standard Deviation \t\t = " << ds.RelativeSD();
                break;
            case'X':
                if (ds.CheckEmpty()) break;
                ds.FrequencyTable(cout);
                break;
            case 'Y':
                ds.displayALL(cout); break;
            case 'Z':
            {
                string filename;
                cout << "\nSpecify a text file to save results: ";
                cin >> filename;

                if (filename.find(".txt") == string::npos) {
                    filename += ".txt";
                }

                ds.SaveToFile(filename);

                cout << "\nCONFIRMATION: File, " << filename << ", has been generated.\n";
            }
               
                break;
            default: cout << "\t\tERROR - Invalid option."; break;
            }
        
       

        cout << "\n";
        system("pause");

    } while (true);

    return EXIT_SUCCESS;
}

void showMenu()
{
    if(ds.getSize()==0)
    {
        cout << "\n\tERROR: Data Set requires at least 2 values.\n";
    }

    cout << "\n\tDescriptive Statistics Calculator Main Menu\n";
    cout << "\n\t" << string(85, char(205));
    cout << "\n\t0. Exit";
    cout << "\n\t1. Configure Dataset to Sample or Polulation";
    cout << "\n\t2. Insert sort value(s) to the Dataset";
    cout << "\n\t3. Delete value(s) from the Dataset";
    cout << "\n\t" << string(85, char(196));
    cout << "\n\tA. Find Minimum \t\t\tN. Find Outliers";
    cout << "\n\tB. Find Maximum \t\t\tO. Find Sum of Squares";
    cout << "\n\tC. Find Range \t\t\t\tP. Find Mean Absolute Deviation";
    cout << "\n\tD. Find Size \t\t\t\tQ. Find Root Mean Square";
    cout << "\n\tE. Find Sum \t\t\t\tR. Find Standard Error of Mean";
    cout << "\n\tF. Find Mean \t\t\t\tS. Find Skewness";
    cout << "\n\tG. Find Median \t\t\t\tT. Find Kurtosis";
    cout << "\n\tH. Find Mode(s) \t\t\tU. Find Kurtosis Excess";
    cout << "\n\tI. Find Standard Deviation \t\tV. Find Coefficient of Variation";
    cout << "\n\tJ. Find Variance \t\t\tW. Find Relative Standard Deviation";
    cout << "\n\tK. Find Midrange \t\t\tX. Display Frequency Table";
    cout << "\n\tL. Find Quartiles \t\t\tY. Display ALL statical results";
    cout << "\n\tM. Find Interquartile Range \t\tZ. Output ALL statical results to text file";
    cout << "\n\t" << string(85, char(205)) << "\n";

}

void showIntro()
{
    cout << "\n\tWhat are Descriptive Statistics?";
    cout << "\n\n\tDescriptive statistics summarize certain aspects of a data set (Sample or Population)\n\tusing numeric calculations.";
    cout << "\n\n\thttps://www.calculatorsoup.com/calculators/statistics/descriptivestatistics.php.";
    cout << "\n\nPress any key to continue . . . ";
    cin.get();

    system("cls");
}

void insertMenu()
{
    do
    {
        system("cls");
        cout << "\n\n\tInsert (sort) Dataset Menu";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t\tA. insert a value";
        cout << "\n\t\tB. insert a specified number of random values";
        cout << "\n\t\tC. read data from file and insert values";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t\tR. return";
        cout << "\n\t" << string(80, char(205));

        switch (toupper(inputChar("\n\n\t\tOption: ")))
        {
        case 'A':
        {
            int val = inputInteger("\n\n\tSpecify an integer value to be inserted: ");
            ds.insertSort(val);
            cout << "\n\t" << val << " has been inserted...\n";
            cout << "\n\t";
            system("pause");
            break;

        }
        case 'B':
        {
            int count = inputInteger("\n\n\tSpecify a number of values to be randomly generated into the Dataset: ", 1, 1000);
            int maxVal = 100;
            ds.insertSort(count, maxVal);
            cout << "\n\tCONFIRMATION: Inserted " << count << " random values into the Dataset.\n";
            cout << "\n\t";
            system("pause");
            break;
        }
        case 'C':
        {
            ifstream inputFile;
            string filename;

            cout << "\n\n\tSpecify a data text file name to read: ";
            //cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover input
            getline(cin, filename);

            if (filename.find(".txt") == string::npos) {
                filename += ".txt";
            }


            inputFile.open(filename);

            if (inputFile)
            {
                int value = 0;
                int count = 0;

                while (inputFile >> value)
                {
                    ds.insertSort(value);   // insert exact values into dataset
                    count++;
                }

                cout << "\n\tCONFIRMATION: " << count
                    << " element(s) have been read and inserted to the Dataset.\n\n";

                inputFile.close();
            }
            else
            {
                cout << "\n\n\tERROR: File, " << filename << ", cannot be found.\n";
            }

            system("pause");

            /*ifstream inputFile;
            string fileName;

            cout << "\n\n\tSpecify a data text file name to read: ";
            //cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover input
            getline(cin, fileName);

            inputFile.open(fileName);

            if (!inputFile) {                    // check if opened successfully
                cout << "\n\n\tERROR: File, " << fileName << ", cannot be found.\n";
                system("pause");

            }
            else
            {
                int value = 0;
                int count = 0;

                while (inputFile >> value)
                {
                    ds.insertSort(value);   // insert exact values into dataset
                    count++;
                }

                cout << "\n\tCONFIRMATION: " << count
                    << " element(s) have been read and inserted to the Dataset.\n\n";

                inputFile.close();
                system("pause");
            }
           */

            break;

        }
        case 'R':
            return;
            break;
        }

    } while (true);

}

void deleteMenu()
{
    do
    {
        system("cls");
        cout << "\n\tDelete Dataset Menu";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t\tA. delete a value";
        cout << "\n\t\tB. delete a range of values";
        cout << "\n\t\tC. delete all values";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t\tR. return";
        cout << "\n\t" << string(80, char(205));

        switch (toupper(inputChar("\n\t\tOption: ", 'ABCR')))
        {
        case 'A':
        {
            int val = inputInteger("\n\tSpecify an integer value to find and be deleted from the Dataset: ");
            ds.deleteValue(val);

        }
        break;
        case 'B':
        {
            int startVal = inputInteger("\n\tSpecify a starting integer value to be deleted from the Dataset: ");
            int endVal = inputInteger("\n\tSpecify an ending integer value to be deleted from the Dataset: ");
            ds.deleteRange(startVal, endVal);
        }
        break;
        case 'C':
            ds.deleteAllValues();
            break;
        case 'R': return;
        default:
            cout << "\n\tERROR: Invalid input. Must be one of 'ABCR' character.";
        }

        cout << "\n\n\t";
        system("pause");

    } while (true);
}
