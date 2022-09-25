#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <ostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int quartile(int q, vector<int> &v)
{
    int n = v.size();
    int term = round((q / 100.0) * (n + 1));
    return v[term - 1];
}

int main()
{
    fstream file("", ios::in);
    if (!file.is_open())
    {
        perror("Error : ");
        return -1;
    }
    string line, mark;
    vector<int> v;
    int i = 0;
    while (getline(file, line))
    {
        if (i == 0)
        {
            i++;
            continue;
        }
        stringstream str(line);
        getline(str, mark, ',');
        int mk = stoi(mark);
        v.push_back(mk);
    }
    sort(v.begin(), v.end());
    int n = v.size();
    int min_marks = v[0], max_marks = v[n - 1];
    float median;
    if (n % 2 == 1)
    {
        median = v[(n - 1) / 2];
    }
    else
    {
        median = (v[(n / 2 - 1)] + v[n / 2]) / 2.0;
    }

    ofstream fw("", ios::out);
    fw << "mini" << min_marks << endl;
    fw << "lower" ;

        return 0;
}