#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    fstream file("data.csv", ios::in);

    if (!file.is_open())
    {
        cout << "Couldn't Open file";
        return 0;
    }

    string line, word;
    string cat, region, count;
    int val;

    map<string, map<string, int>> classRegionMap;
    map<string, int> catMap;
    map<string, int> regMap;

    int i = 0;

    while (getline(file, line))
    {
        stringstream str(line);

        if (i == 0)
        {
            i++;
            continue;
        }

        getline(str, cat, ',');
        getline(str, region, ',');
        getline(str, count, ',');

        val = stoi(count);

        // cout << cat << " " << region << " "<< stoi(count)+10 << " " << "\n";

        classRegionMap[cat][region] = val;
        catMap[cat] += val;
        regMap[region] += val;
    }

    int catSum = 0, regSum = 0;

    for (auto p : catMap)
    {
        catSum += p.second;
    }

    // cout << "catSum : " << catSum << "\n";

    for (auto p : regMap)
    {
        regSum += p.second;
    }

    ofstream fw("tdoutput2.csv", ios::out);

    fw << "Class Region , Europe ,,, North America ,,, Both Regions,,, " << endl;
    fw << " ,Count,t-weight,d-weight,Count,t-weight,d-weight,Count,t-weight,d-weight" << endl;

    for (auto c : catMap)
    {
        cat = c.first;
        fw << cat << ",";

        for (auto p : regMap)
        {
            region = p.first;

            fw << classRegionMap[cat][region] << ",";
            fw << ((float)classRegionMap[cat][region] / catMap[cat]) * 100 << "%,";
            fw << ((float)classRegionMap[cat][region] / regMap[region]) * 100 << "%,";
        }

        fw << catMap[cat] << "," << ((float)catMap[cat] / catMap[cat]) * 100 << "%," << ((float)catMap[cat] / (regSum)) * 100 << "%" << endl;
    }

    fw << "Both Classes ,";

    for (auto p : regMap)
    {
        region = p.first;

        fw << regMap[region] << ",";
        fw << ((float)regMap[region] / regSum) * 100 << "%,";
        fw << ((float)regMap[region] / regMap[region]) * 100 << "%,";
    }

    fw << regSum << ","
       << "100% , 100%" << endl;

    fw.close();

    return 1;
}