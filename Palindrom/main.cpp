#include <iostream>
#include <fstream>
#include <string.h>
#include <bits/stdc++.h>
#define NM 400005
using namespace std;
ifstream in("palindrom.in");
ofstream out("palindrom.out");
int n,S[NM],k;
char T[NM],P[NM],poz;
int main()
{
    in>>T+1;
    n=strlen(T+1);
    for(int i=1;i<=n;++i)P[i]=T[n+1-i];
    k=0;
    for(int i=2;i<=n;++i)
    {
        while(k>0 && P[i]!=P[k+1])k=S[k];
        if(P[i]==P[k+1])++k;
        S[i]=k;
    }
    k=0;
    for(int i=1;i<=n;++i)
    {
        while(k>0 && P[k+1]!=T[i])k=S[k];
        if(P[k+1]==T[i])++k;
    }
    out<<T+1;
    for(int i=k+1;i<=n;++i)out<<P[i];
    return 0;
}
