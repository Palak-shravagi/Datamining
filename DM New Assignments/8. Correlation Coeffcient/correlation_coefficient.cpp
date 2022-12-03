#include <bits/stdc++.h>
using namespace std;

int main()
{
    fstream fr("input.csv", ios::in);

    if (!fr.is_open())
    {
        perror("Error in opening file : ");
        return -1;
    }

    string line, a_str, b_str;
    vector<int> a, b;

    int i = 0;
    while (getline(fr, line))
    {

        if (i == 0)
        {
            i++;
            continue;
        }

        stringstream str(line);

        getline(str, a_str, ',');
        getline(str, b_str, ',');

        a.push_back(stoi(a_str));
        b.push_back(stoi(b_str));
    }
    fr.close();

    int tot = a.size();
    int a_plus = 0, b_plus = 0, ab_plus = 0;

    for (int i = 0; i < tot; i++)
    {

        a_plus += a[i] == 1 ? 1 : 0;
        b_plus += b[i] == 1 ? 1 : 0;

        ab_plus += a[i] == 1 && b[i] == 1 ? 1 : 0;
    }

    float corr_coeff = ((float)ab_plus / (a_plus * b_plus));

    ofstream fw("output.csv", ios::out);
    fw << "Correlation Coefficient "
       << "," << corr_coeff << endl;

    fw.close();

    return 1;
}