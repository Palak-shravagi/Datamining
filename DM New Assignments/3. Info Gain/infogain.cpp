#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
int main()
{

    fstream file("input.csv");

    string line, word;
    string outlook, temp, humidity;
    char *day;
    map<string, int> parent;
    map<string, map<string, int>> child;
    // map<string,double> childValEntropy;

    if (!file.is_open())
    {
        perror("Error in opening input file : ");
        return 0;
    }

    int i = 0;
    string childName;
    while (getline(file, line))
    {
        stringstream str(line);

        day = strtok(str, " , ");
        getline(str, outlook, ',');
        getline(str, temp, ',');
        getline(str, humidity, ',');
        getline(str, wind, ',');
        getline(str, playGame, ',');

        cout << day << " " << outlook << " " << temp << " " << humidity << " " << wind << " " << playGame << " \n";
        x` int choice;

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

        cout << playGame << " " << childName << "\n";
        parent[playGame]++;
        child[childName][playGame]++;
    }
    double posR = parent["Yes"], negR = parent["No"];
    cout << posR << " " << negR << "\n";
    double totR = posR + negR;
    double parent_entropy = 0;
    if (posR != 0)
        parent_entropy = -(posR / totR) * log2(posR / totR);

    if (negR != 0)
        parent_entropy += -(negR / totR) * log2(negR / totR);

    cout << parent_entropy;

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

    ofstream fw("output.csv");
    fw << "Info Gain : "
       << "," << info_gain;
    fw.close();

    return 0;
}
