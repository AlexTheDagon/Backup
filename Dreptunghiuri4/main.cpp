#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define NM 2005
#define mp make_pair
using namespace std;
ifstream in("dreptunghiuri4.in");
ofstream out("dreptunghiuri4.out");
pair<pair<int,int>,pair<int,int> > crd[1005];
set<int> l,c;
unordered_map<int,int> nl,nc,ll,cc;
long long n,k,nrl,nrc,sol;
short sp[NM][NM];
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)
    {
        in>>crd[i].ff>>crd[i].fs>>crd[i].sf>>crd[i].ss;
        l.insert(crd[i].ff);
        l.insert(crd[i].sf);
        c.insert(crd[i].fs);
        c.insert(crd[i].ss);
    }///bine
    for(auto i:l)
    {
        nl[i]=++nrl;
        ll[nrl]=i;
    }
    for(auto i:c)
    {
        nc[i]=++nrc;
        cc[nrc]=i;
    }///bine
    for(int i=1;i<=n;++i)
    {
        sp[nl[crd[i].ff]][nc[crd[i].fs]]++;
        sp[nl[crd[i].sf]][nc[crd[i].ss]]++;
        sp[nl[crd[i].ff]][nc[crd[i].ss]]--;
        sp[nl[crd[i].sf]][nc[crd[i].fs]]--;
    }
    for(int i=1;i<=nrl;++i)
    {
        for(int j=1;j<=nrc;++j)
        {
            sp[i][j]=sp[i][j]+sp[i-1][j]+sp[i][j-1]-sp[i-1][j-1];
            if(sp[i][j]==k && i<nrl && j<nrc)sol+=(1LL*(ll[i+1]-ll[i])*(cc[j+1]-cc[j]));
        }
    }

    out<<sol;
    return 0;
}
