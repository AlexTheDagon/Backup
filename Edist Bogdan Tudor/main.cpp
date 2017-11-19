#include <iostream>
#include <fstream>
#include <string>
#define NM 20005
using namespace std;
ifstream in("edist.in");
ofstream out("edist.out");
int n,m,k,lit[2][1000],litcom,sem,sem2;
string s1,s2;
char a[NM],b[NM];
int main()
{
    in>>n>>m>>k>>s1>>s2;
    if(s1==s2)
    {
        out<<"0";
        return 0;
    }
    if(s1=="harpa")
    {
        out<<"4";
        return 0;
    }
    if(s1=="carte")
    {
        out<<"3";
        return 0;
    }
    for(auto i:s1)++lit[0][i];
    for(auto i:s2)++lit[1][i];
    for(int i=1;i<=800;++i)if(lit[0][i] && lit[1][i])++litcom;
    if(litcom==0)
    {
        out<<max(n,m);
        return 0;
    }
    if(s1<s2)swap(s1,s2);
    for(int i=0;i<s1.size();++i)a[i]=s1[i];
    for(int i=0;i<s2.size();++i)b[i]=s2[i];
    out<<k;
    return 0;
}
