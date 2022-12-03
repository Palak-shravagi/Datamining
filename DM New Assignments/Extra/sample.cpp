#include<bits/stdc++.h>
using namespace std;

map<string,map<string,int>> classRegionMap;
map<string,int> catMap;
map<string,int> regMap;
string cat,region,cnt;

map<string,map<string,double>> dweight;
map<string,map<string,double>> tweight;

void readFile()
{

    fstream infile("input_file.csv",ios::in);

    if(!infile.is_open())
    {
        perror("Error : ");
       
        return ;
    }

    string line;
    int val  = 0;
    int i=0;
     while(getline(infile,line))
     {
        if(i==0)
        {
            i++;
            continue;
        }
        stringstream str(line);
        getline(str,cat,',');
        getline(str,region,',');
        getline(str,cnt,',');
        val = stoi(cnt);

        classRegionMap[cat][region] = val;
        catMap[cat] += val;
        regMap[region] += val;

     }
}

void calc()
{
    for(auto i = classRegionMap.begin();i!=classRegionMap.end();i++){
        for(auto pp : i->second){

            cat = (*i).first;
            region = pp.first;
            int val = pp.second;

            double t_weight = 0,d_weight=0;

            t_weight = ((double)(classRegionMap[cat][region]) / catMap[cat])*100;
            d_weight = ((double)(classRegionMap[cat][region]) / regMap[region])*100;

            tweight[cat][region] = t_weight;
            dweight[cat][region] = d_weight;
        }
    }
}

void write()
{

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

    ofstream fw("output.csv", ios::out);

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
            fw << tweight[cat][region] << "%,";
            fw << dweight[cat][region] << "%,";
        }

        fw << catMap[cat] << "," << ((float)catMap[cat] / catMap[cat]) * 100 << "%," << ((float)catMap[cat] / (regSum)) * 100 << "%" <<endl;
    }

    fw << "Both Classes ,";

    for (auto p : regMap)
    {
        region = p.first;

        fw << regMap[region] << ",";
        fw << tweight[cat][region] << "%,";
        fw << dweight[cat][region] << "%,";
    }

    fw << regSum << "," << "100% , 100%" << endl; 

    fw.close();
}

int main()
{
    readFile();

    calc();

    write();

    for(auto i = classRegionMap.begin();i!=classRegionMap.end();i++){
        for(auto pp : i->second){

            cat = (*i).first;
            region = pp.first;
            int val = pp.second;

            cout << "T-weight for [" << cat << "][" << region << "] : " << tweight[cat][region] << "%" << "\n";
            cout << "D-weight for [" << cat << "][" << region << "] : " << dweight[cat][region] << "%" <<"\n\n";
        }
    }

}