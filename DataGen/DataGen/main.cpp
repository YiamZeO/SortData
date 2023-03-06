#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void dataGen(fstream* fData)
{
    if (fData)
    {
        string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
        for (int i = 0; i < 100; i++)
        {
            string result;
            int length = 1 + (rand() % 9);
            result.resize(length);
            for (int j = 0; j < length; j++)
                result[j] = charset[rand() % charset.length()];
            double rating = 1.0 + (double)(rand() % (9 * 10)) / 10;
            *fData << "Example_" << result << " " << rating << endl;
        }
    }
}

int main()
{
    srand(time(NULL));
    cout << "Enter file name:" << endl;
    string fName;
    cin >> fName;
    fstream fData(fName, ios::out | ios::trunc);
    if (fData)
    {
        dataGen(&fData);
        fData.close();
    }
    return 0;
}