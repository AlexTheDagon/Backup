#include <iostream>
#include <string.h>
#include <fstream>
#include <bits/stdc++.h>
#define NM 2000005
#define pb  push_back
using namespace std;
ifstream in("strmatch.in");
ofstream out("strmatch.out");
char c,T[NM],P[NM];
int n,m,f,S[NM],k,cnt;
vector<int> sol;
int main()
{
    in>>P+1;
    n=strlen(P+1);
    S[0]=0;
    k=0;
    for(int i=2;i<=n;++i)
    {
        while(k>0 && P[k+1]!=P[i])k=S[k];
        if(P[k+1]==P[i])++k;
        S[i]=k;
    }
    in>>T+1;
    m=strlen(T+1);
    k=0;
    for(int i=1;i<=m;++i)
    {
        while(k>0 && P[k+1]!=T[i])k=S[k];
        if(P[k+1]==T[i])++k;
        if(k==n)
        {
            ++cnt;
            sol.pb(i-k);
            k=S[k];///bucata posibil refolosobila
        }
    }
    ///bine(teoretic)
    out<<sol.size()<<'\n';
    for(int i=0;i<min(1000,cnt);++i)out<<sol[i]<<" ";
    return 0;
}
