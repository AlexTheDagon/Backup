#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("dir.in");
ofstream fout("dir.out");
vector<string>sol;
vector<string>solf;
string s,p,sl;
int bs=92,c;
int i=0;
void afisare()
{
    for(auto j : solf)
    {
        if(j.size()!=1 || j[0]!=bs)fout<<j<<'\n';
    }
}
void colect()
{
    sl="";
    for(int j=0;j<sol.size();++j)
    {
        for(int z=0;z<sol[j].size();++z)sl.push_back(sol[j][z]);
        if(j!=sol.size()-1)sl.push_back(bs);
    }
    solf.push_back(sl);
}
void next_string()
{
    p="";
    while(i<s.size() && (s[i]!=',' && s[i]!='(' && s[i]!=')'))
    {
        p.push_back(s[i]);
        ++i;
    }
}
void evaluare()
{
    if(s[i]==')'){++i;return;}
    while(i==0 || (s[i]>=65 && s[i]<=90))
    {
        next_string();
        sol.push_back(p);p="";
        ++i;
        evaluare();
        ++i;
        sol.pop_back();
    }
    if(s[i]>=97 && s[i]<=123)
    {
        next_string();
        sol.push_back(p);
        colect();
        sol.pop_back();
        while(i<s.size() && s[i]!=')')
        {
            ++i;
            next_string();
            sol.push_back(p);
            colect();
            sol.pop_back();
        }
        p="";++i;
    }
}
int main()
{
    fin>>s;
    p="";
    for(int k=0;k<s.size();++k)
        if(s[k]>=97 && s[k]<=123)
        {
            c++;
            while(s[k]>=97 && s[k]<=123)++k;
        }
    fout<<c<<'\n';
    evaluare();
    sort(solf.begin(),solf.end());
    afisare();
    return 0;
}

