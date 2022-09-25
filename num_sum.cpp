#include <bits/stdc++.h>
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int quartile(int q, vector<int> &marks)
{

    int n = marks.size();
    int term = round((q / 100.0) * (n + 1));

    return marks[term - 1];
}
int main()
{
    fstream fr("/home/palak/Documents/assignments/dm/datafile/num_sum_ip.csv", ios::in);
    if (!fr.is_open())
    {
        perror("Error in opening input file : ");
        return -1;
    }
    string line, mark;
    vector<int> marks;
    int i = 0;
    while (getline(fr, line))
    {
        if (line.length() == 0)
            break;

        if (i == 0)
        {
            i++;
            continue;
        }
        stringstream str(line);
        getline(str, mark, ',');

        int mk = stoi(mark);
        marks.push_back(mk);
    }
    sort(marks.begin(), marks.end());
    int n = marks.size();

    int min_marks = marks[0], max_marks = marks[n - 1];
    float median;

    if (n % 2 == 1)
    {
        median = marks[(n - 1) / 2];
    }
    else
    {
        median = (marks[n / 2 - 1] + marks[n / 2]) / 2.0;
    }
    ofstream fw("/home/palak/Documents/assignments/dm/datafile/num_sum_op.csv", ios::out);
    fw << "Minimum Value : " << min_marks << endl;
    fw << "Lower Quartile : " << quartile(25, marks) << endl;
    fw << "Median : " << median << endl;
    fw << "Upper Quartile : " << quartile(75, marks) << endl;
    fw << "Maximum Value : " << max_marks << endl;
    fw.close();
    fr.close();

    return 0;
}