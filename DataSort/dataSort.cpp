#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>


using namespace std;

class DataSort
{
    vector<pair<string, string>> data;

public:
    DataSort() = default;
    ~DataSort() = default;
    void unloadData();
    void sortData();
    void uploadData(fstream *fData);
};

int main()
{
    DataSort dS;
    cout << "Enter File name: " << endl;
    string s;
    cin >> s;
    fstream data(s, ios::in);
    if (data)
    {
        dS.uploadData(&data);
        data.close();
        dS.sortData();
        dS.unloadData();
    }
    return 0;
}

void DataSort::unloadData()
{
    if (data.size())
    {
        fstream f("outData.txt", ios::out | ios::trunc);
        f << "Sorted data:" << endl;
        for (auto i : data)
            f << "Game: " << i.first << " -> Rating: " << i.second << endl;
        f.close();
    }
}

void DataSort::sortData()
{
    sort(data.begin(), data.end(), [](pair<string, string> p1, pair<string, string> p2)
         { return stod(p1.second) < stod(p2.second); });
}

void DataSort::uploadData(fstream *fData)
{
    if (*fData)
        while (fData->good())
        {
            pair<string, string> p;
            *fData >> p.first;
            *fData >> p.second;
            if(p.first.size() && p.second.size())
                data.push_back(p);
        }
}
