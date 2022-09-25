#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include<ostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    string line, word;
    fstream file ("/home/palak/Documents/assignments/dm/datafile/infogain_cpp.csv", ios::in);
    string day,outlook,temp,humidity,wind,playGame;
    map<string,int> parent;
    map<string,map<string,int>> child;
    if(file.is_open())
    {
        int i=0;
        while(getline(file, line))
        {
            stringstream str(line);

            if(i==0){
                i++;
                continue;
            }
            getline(str, day, ',');
            getline(str, outlook, ',');
            getline(str, temp, ',');
            getline(str, humidity, ',');
            getline(str, wind, ',');
            getline(str, playGame, ',');
            
            parent[playGame]++;
            child[wind][playGame]++;
        }
        double posR = parent["Yes"],negR=parent["No"];
        double totR = posR + negR;
        double parent_entropy = - ((posR/totR)*log2(posR/totR) + (negR/totR)*log2(negR/totR));
        double child_entropy_pro = 0;
        for(auto p : child){
            string val = p.first;
            double pR = child[val]["Yes"],nR = child[val]["No"];
            double tR = pR + nR;

            child_entropy_pro += -((pR+nR)/totR)*((pR/tR)*log2(pR/tR) + (nR/tR)*log2(nR/tR));
        }
         cout << "Info gain : " << parent_entropy - child_entropy_pro << "\n";
    }
    else{
        cout<<"Could not open the file\n";
    }
    return 0;
}
 
 
