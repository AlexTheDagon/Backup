#include <iostream>
#include <fstream>
#define MM 100005

using namespace std;
ifstream in("rmq.in");
ofstream out("rmq.out");
int v[20][100005];
int n,m,a,b,x,l[MM],lg,minn,p;
int main()
{
    in>>n>>m;
    for(int i=2;i<MM-2;++i)l[i]=l[i/2]+1;
    for(int i=1;i<=n;++i)in>>v[0][i];
    for(int p=1;p<=l[n];++p)
        for(int i=1;i<=(n-(1<<p)+1);++i)
            v[p][i]=min(v[p-1][i],v[p-1][i+(1<<(p-1))]);
    for(int t=1;t<=m;++t)
    {
        in>>a>>b;
        lg=l[b-a+1];
        out<<min(v[lg][a],v[lg][b-(1<<lg)+1])<<'\n';
    }
    return 0;
}
///rmq[pd][i]--->min pe sec i,i+2^pd-1
