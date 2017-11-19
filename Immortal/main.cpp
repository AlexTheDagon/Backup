#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define x first
#define y second
#define NM 25
using namespace std;
ifstream in("immortal.in");
ofstream out("immortal.out");
vector<pair<pair<int,int>,pair<int,int> > >sol;
pair<int,int> crd[NM];
int a[NM][NM],elim[NM],n,m,k;
int dx[]={-1,1,0,0,0};
int dy[]={0,0,1,-1,0};
int ok(int i,int j)
{
    return(i>0 && i<=n && j>0 && j<=m);
}
int main()
{
    in>>n>>m>>k;
    for(int i=1;i<=k;++i)
    {
        in>>crd[i].x>>crd[i].y
        a[crd[i].x][crd[i].y]=i;
    }
    return 0;
}
