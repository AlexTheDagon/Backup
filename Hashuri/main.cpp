#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define pb push_back
#define prim 1000007
using namespace std;
ifstream in("hashuri.in");
ofstream out("hashuri.out");
vector <long long> v[prim+10];
long long n,op,x,poz;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>op>>x;
        if(op==1)
        {
            poz=-1;
            for(int i=0;i<v[x%prim].size();++i)
                if(v[x%prim][i]==x)poz=i;
            if(poz==-1)v[x%prim].pb(x);
        }
        if(op==2)
        {
            poz=-1;
            for(int i=0;i<v[x%prim].size();++i)
                if(v[x%prim][i]==x)poz=i;
            if(poz!=-1)
                v[x%prim].erase(v[x%prim].begin()+poz);
        }
        if(op==3)
        {
            poz=-1;
            for(int i=0;i<v[x%prim].size();++i)
                if(v[x%prim][i]==x)poz=i;
            if(poz!=-1)out<<1<<'\n';
            else out<<0<<'\n';
        }
    }
    return 0;
}
