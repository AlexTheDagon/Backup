#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cri.in");
ofstream out("cri.out");
int is,js,n,m,minn,sum,a[505][505],cam,mincam,maxx,zona;
int main()
{
    in>>n>>m>>is>>js;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)in>>a[i][j];
    ///zona 1
    sum=0;
    minn=10000;
    for(int i=1;i<=is;++i)
    {
        for(int j=1;j<=js;++j)
        {
            ++cam;
            sum+=a[i][j];
            if((is-i+1+js-j+1)%2==1)minn=min(minn,a[i][j]);
        }
    }
    if(is%2==0 && js%2==0)
    {
        sum-=minn;
        --cam;
    }
    if(sum>maxx)
    {
        zona=1;
        maxx=sum;
        mincam=cam;
    }
    if(sum==maxx && cam<mincam)
    {
        mincam=cam;
        zona=1;
    }
    ///zona 2
    sum=0;
    minn=10000;
    cam=0;
    for(int i=1;i<=is;++i)
    {
        for(int j=js;j<=m;++j)
        {
            ++cam;
            sum+=a[i][j];
            if((is-i+j-js)%2==1)minn=min(minn,a[i][j]);
        }
    }
    if(is%2==0 && (m-js+1)%2==0)
    {
        sum-=minn;
        --cam;
    }
    if(sum>maxx)
    {
        zona=2;
        maxx=sum;
        mincam=cam;
    }
    if(sum==maxx && cam<mincam)
    {
        mincam=cam;
        zona=2;
    }
    ///zona 3
    sum=0;
    minn=10000;
    cam=0;
    for(int i=is;i<=n;++i)
    {
        for(int j=1;j<=js;++j)
        {
            ++cam;
            sum+=a[i][j];
            if((i-is+1+js-j+1)%2==1)minn=min(minn,a[i][j]);
        }
    }
    if((n-is+1)%2==0 && js%2==0)
    {
        sum-=minn;
        --cam;
    }
    if(sum>maxx)
    {
        zona=3;
        maxx=sum;
        mincam=cam;
    }
    if(sum==maxx && cam<mincam)
    {
        mincam=cam;
        zona=3;
    }
    ///zona 4
    sum=0;
    minn=10000;
    cam=0;
    for(int i=is;i<=n;++i)
    {
        for(int j=js;j<=m;++j)
        {
            ++cam;
            sum+=a[i][j];
            if((i-is+1+j-js+1)%2==1)minn=min(minn,a[i][j]);
        }
    }
    if((n-is+1)%2==0 && (m-js+1)%2==0)
    {
        sum-=minn;
        --cam;
    }
    if(sum>maxx)
    {
        zona=4;
        maxx=sum;
        mincam=cam;
    }
    if(sum==maxx && cam<mincam)
    {
        mincam=cam;
        zona=4;
    }
    out<<zona<<" "<<maxx<<" "<<mincam;
    return 0;
}
