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
    string name, age, wce;
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

        getline(str, name, ',');
        getline(str, age, ',');
        getline(str, wce, ',');

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
            childName = name;
            break;

        case 2:
            childName = age;
            break;
        default:
            childName = wce;
        }
        childName = age;
        parent[wce]++;
        child[childName][wce]++;
    }

    double posR = parent["1"], negR = parent["0"];
    double totR = posR + negR;
    // cout << posR << " " << negR << "\n";

    double parent_entropy = -((posR / totR) * log2(posR / totR) + (negR / totR) * log2(negR / totR));
    // cout << "Parent Entropy" << parent_entropy << "\n";

    double child_entropy_pro = 0;
    for (auto p : child)
    {
        string val = p.first;
        double pR = child[val]["1"], nR = child[val]["0"];

        // cout << val << " " << pR << " " << nR << "\n";
        double tR = pR + nR;

        child_entropy_pro += -((pR + nR) / totR) * ((pR / tR) * log2(pR / tR) + (nR / tR) * log2(nR / tR));
    }

    // cout << "Child Entropy * Their proportion : " << child_entropy_pro << "\n";

    double info_gain = parent_entropy - child_entropy_pro;
    cout << "Info gain : " << info_gain << "\n";

    ofstream fw("output.csv", ios::out);
    fw << "Info Gain : "
       << "," << info_gain;
    fw.close();

    return 0;
}
