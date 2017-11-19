#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ifstream in("string.in");
ofstream out("string.out");
const string delim = " ,.!?|-";
string cuv;
inline bool find(string s,char c)
{
    for(int i=0;i<s.size();++i)
    {
        if(s[i]==c)return 1;
    }
    return 0;
}
int main()
{
    string s;
    string line;
    string v[100];
    int cnt=0;
    getline(in,line);
    for(int i=0;i<line.size();++i)
    {
        if(find(delim,line[i]))
        {
            if(cuv!="")
            {
                ++cnt;
                v[cnt]=cuv;
                cuv="";
            }
        }
        else
        {
            cuv.push_back(line[i]);
        }
    }
    if(cuv!="")
    {
        v[++cnt]=cuv;
    }
    for(int i=1;i<=cnt;++i)out<<v[i]<<" ";
    return 0;
}
