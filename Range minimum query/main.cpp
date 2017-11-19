#include <iostream>
#include <fstream>
#define S 400
using namespace std;
ifstream in("rmq.in");
ofstream out("rmq.out");
int n,m,a[100005],b[S],x,y,minn;
int main()
{
    in>>n>>m;
    for(int i=1;i<S-3;++i)b[i]=1000000;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        b[(i-1)/S+1]=min(b[(i-1)/S+1],a[i]);
    }
    ///bine
    for(int t=1;t<=m;++t)
    {
        in>>x>>y;
        minn=1000000;
        ///bine
        for(int i=(x-1)/S+2;i<(y-1)/S+1;++i)minn=min(minn,b[i]);
        ///bine
        for(int i=x;i<min(((x-1)/S+2)*S,y+1);++i)minn=min(minn,a[i]);
        for(int i=max(((y-1)/S+1)*S,x);i<=y;++i)minn=min(minn,a[i]);
        out<<minn<<'\n';
    }
    return 0;
}
