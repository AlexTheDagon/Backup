#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define NM 100005
using namespace std;
ifstream in("rmq.in");
ofstream out("rmq.out");
int lg[NM],rmq[20][NM],n,m,x,y;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        in>>rmq[0][i];
    for(int i=2;i<=n;++i)
        lg[i]=lg[i/2]+1;
    ///build
    for(int i=1;i<=lg[n];++i)
        for(int j=1;j+(1<<i)-1<=n;++j)
            rmq[i][j]=min(rmq[i-1][j],rmq[i-1][j+(1<<(i-1))]);
    ///query
    for(int i=1;i<=m;++i)
    {
        in>>x>>y;
        int log=lg[y-x+1];
        out<<min(rmq[log][x],rmq[log][y-(1<<log)+1])<<'\n';
    }
    return 0;
}
