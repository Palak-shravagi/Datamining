#include <bits/stdc++.h>
using namespace std;
int main()
{
    fstream fr("input.csv", ios::in);
    if (!fr.is_open())
    {
        perror("Error in opening input file : ");
        return -1;
    }
    string line, xstr, ystr;
    vector<double> x, y;
    int i = 0;
    while (getline(fr, line))
    {
        if (i == 0)
        {
            i++;
            continue;
        }
        stringstream str(line);
        getline(str, xstr, ',');
        getline(str, ystr, ',');
        x.push_back(stod(xstr));
        y.push_back(stod(ystr));
    }
    int n = x.size();
    double x_sum = 0, y_sum = 0;
    double x_mean, y_mean, sum_dev_pro = 0, sum_xdev = 0, sum_ydev = 0;
    for (int i = 0; i < n; i++)
    {
        x_sum += x[i];
        y_sum += y[i];
    }
    x_mean = x_sum / n;
    y_mean = y_sum / n;
    for (int i = 0; i < n; i++)
    {
        sum_xdev += (x[i] - x_mean) * (x[i] - x_mean);
        sum_ydev += (y[i] - y_mean) * (y[i] - y_mean);

        sum_dev_pro += (x[i] - x_mean) * (y[i] - y_mean);
    }
    double covxy = sum_dev_pro / n;
    double std_x = sqrt(sum_xdev / n);
    double std_y = sqrt(sum_ydev / n);
    double corr_coeff = covxy / (std_x * std_y);
    cout << "Correlation Coefficient : " << corr_coeff << "\n";
    return 1;
}