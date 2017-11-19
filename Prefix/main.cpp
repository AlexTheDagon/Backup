#include <iostream>
#define NM 1000005
#include <fstream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
ifstream in("prefix.in");
ofstream out("prefix.out");
int S[NM],n,k,nrt,aux,lng;
char T[NM];
int main()
{
    in>>nrt;
    while(nrt>0)
    {
        --nrt;
        in>>T+1;
        n=strlen(T+1);
        for(int i=0;i<=n+2;++i)S[i]=0;
        k=0;
        for(int i=2;i<=n;++i)
        {
            while(k>0 && T[k+1]!=T[i])k=S[k];
            if(T[k+1]==T[i])++k;
            S[i]=k;
        }
        for(lng=n;lng>0;--lng)
            if(lng%(lng-S[lng])==0 && S[lng])break;
        out<<lng<<'\n';
    }
    return 0;
}
