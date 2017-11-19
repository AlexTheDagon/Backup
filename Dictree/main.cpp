#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
ifstream in("dictree.in");
ofstream out("dictree.out");
int cuv=1;
int n;
string s[25005];
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        in>>s[i];
    sort(s+1,s+n+1);
    cuv+=s[1].size();
    for(int i=2;i<=n;++i)
    {
        int j;
        for(j=0;j<min(s[i].size(),s[i-1].size()) && s[i][j]==s[i-1][j];++j);
        cuv+=(s[i].size()-j);
    }
    out<<cuv;
    return 0;
}
