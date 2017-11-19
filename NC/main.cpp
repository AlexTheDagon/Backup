#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in("nc.in");
ofstream out("nc.out");
int fr,x[2000000],cuv;
int main()
{
    string s;
    while(in>>s)
    {
        if(s[s.find(',')+1]!='\0' && s[s.find(',')]==',' && s.find(',')!=0)++cuv;
        if(s[s.size()-1]=='.' || s[s.size()-1]=='!' || s[s.size()-1]=='?')
        {
            if(s.size()!=1)++cuv;
            x[++fr]=cuv;
            cuv=0;
        }
        ++cuv;

    }
    out<<fr<<'\n';
    for(int i=1;i<=fr;++i)out<<x[i]<<'\n';
    return 0;
}
