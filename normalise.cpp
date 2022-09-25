#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ostream>
using namespace std;
int main()
{
   fstream file("/home/palak/Documents/assignments/dm/datafile/new_norm.csv", ios::in);
   if (!file.is_open())
   {
      perror("Error : ");
      return 0;
   }
   string line, mark;
   vector<double> marks;
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
      double mk = stod(mark);
      marks.push_back(mk);
   }
   int n = marks.size();
   sort(marks.begin(), marks.end());
   double old_min = marks[0];
   double old_max = marks[n - 1];
   double new_min, new_max;
   cout << "Enter New Minimum :";
   cin >> new_min;
   cout << "Enter New Maximum :";
   cin >> new_max;
   ofstream fout("/home/palak/Documents/assignments/dm/datafile/minmax_op.csv", ios::app);
   if (!fout.is_open())
   {
      cout << "Error in creating min_max normalised file";
      return -1;
   }
   fout << "Marks"
        << ","
        << "Min_Max_normalised Marks" << endl;
   for (auto x : marks)
   {
      double normalised_marks = (((x - old_min) / (old_max - old_min)) * (new_max - new_min)) + new_min;
      fout << x << "," << normalised_marks << endl;
   }
   fout.close();
   file.close();

   double sum = 0;
   for (auto mk : marks)
   {
      sum += mk;
   }
   double dev_sq = 0;
   double mean = sum / n;
   for (auto mk : marks)
   {
      dev_sq += (mk - mean) * (mk - mean);
   }
   double std_dev = sqrt(dev_sq / n);
   ofstream fw2("/home/palak/Documents/assignments/dm/datafile/zscore.csv", ios::app);
   if (!fw2.is_open())
   {
      cout << "Error in Opening z-score data file";
      return -1;
   }
   fout << "Marks"
        << ","
        << "Z-score Marks";
   for (auto mk : marks)
   {
      double z_score = (mk - mean) / std_dev;
      fw2 << mk << "," << z_score << endl;
   }
   fw2.close();
   return 0;
}
