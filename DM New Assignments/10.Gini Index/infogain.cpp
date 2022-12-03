#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    fstream file("input.csv", ios::in);

    string line, word;
    string day, outlook, temp, humidity, wind, playGame;

    map<string, int> parent;
    map<string, map<string, int>> child;
    // map<string,double> childValEntropy;

    if (!file.is_open())
    {
        perror("Error in opening input file : ");
        return -1;
    }

    int i = 0;
    string childName;
    while (getline(file, line))
    {
        stringstream str(line);

        getline(str, day, ',');
        getline(str, outlook, ',');
        getline(str, temp, ',');
        getline(str, humidity, ',');
        getline(str, wind, ',');
        getline(str, playGame, ',');

        // cout << playGame << " ";

        int choice;

        if (i == 0)
        {
            i++;
            cout << "Enter Child Column Number : ";
            cin >> choice;
            continue;
        }

        switch (choice)
        {
            case 1:
                childName = day;
                break;

            case 2:
                childName = outlook;
                break;

            case 3:
                childName = temp;
                break;

            case 4:
                childName = humidity;
                break;

            case 5:
                childName = wind;
                break;

            default:
                childName = wind;
        }

        parent[playGame]++;
        child[childName][playGame]++;
    }

    // for (auto p : parent)
    // {
    //     cout << p.first << " " << p.second << "\n";
    // }

    // for (auto p : child)
    // {
    //     for (auto pp : p.second)
    //     {
    //         cout << p.first << " " << pp.first << " " << pp.second << "\n";
    //     }
    // }

    double posR = parent["Yes"], negR = parent["No"];
    double totR = posR + negR;
    // cout << posR << " " << negR << "\n";

    double parent_entropy = -((posR / totR) * log2(posR / totR) + (negR / totR) * log2(negR / totR));
    // cout << "Parent Entropy" << parent_entropy << "\n";

    double child_entropy_pro = 0;
    for (auto p : child)
    {
        string val = p.first;
        double pR = child[val]["Yes"], nR = child[val]["No"];

        // cout << val << " " << pR << " " << nR << "\n";
        double tR = pR + nR;

        child_entropy_pro += -((pR + nR) / totR) * ((pR / tR) * log2(pR / tR) + (nR / tR) * log2(nR / tR));
    }

    // cout << "Child Entropy * Their proportion : " << child_entropy_pro << "\n";

    double info_gain = parent_entropy - child_entropy_pro;
    cout << "Info gain : " << info_gain << "\n";

    ofstream fw("output.csv",ios::out);
    fw << "Info Gain : " << "," << info_gain ;
    fw.close();

    return 0;
}
