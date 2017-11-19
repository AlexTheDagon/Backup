#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#define x first
#define y second
using namespace std;
ifstream in("admitere.in");
ofstream out("admitere.out");
int m,n,caz,clasa[2005],r,u;
pair<int,int> real[4005],uman[4005],elev[4005],poz[2005];
int main()
{
    in>>caz;
    in>>n>>m;
    for(int i=1;i<=m;++i)in>>real[i].x;
    for(int i=1;i<=m;++i)in>>uman[i].x;
    for(int i=1;i<=n;++i)
    {
        in>>elev[i].x>>elev[i].y;
        real[i+m].x=elev[i].x;
        real[i+m].y=i;
        uman[i+m].x=elev[i].x;
        uman[i+m].y=i;
    }
    sort(uman+1,uman+n+m+1,greater<pair<int,int> >());
    sort(real+1,real+n+m+1,greater<pair<int,int> >());
    if(caz==1)
    {
        for(int i=1;i<=m;++i)
        {
            if(real[i].y)++r;
            if(uman[i].y)++u;
        }
        if(u>r)
        {
            out<<u<<'\n';
            for(int i=1;i<=m;++i)if(uman[i].y)clasa[uman[i].y]=1;
            for(int i=1;i<=n;++i)
            {
                if(clasa[i])out<<"U";
                else out<<"X";
            }
        }
        else
        {
            out<<r<<'\n';
            for(int i=1;i<=m;++i)if(real[i].y)clasa[real[i].y]=1;
            for(int i=1;i<=n;++i)
            {
                if(clasa[i])out<<"R";
                else out<<"X";
            }
        }
    }
    else
    {
        for(int i=1;i<=n+m;++i)
        {
            if(uman[i].y)poz[uman[i].y].x=i;
            if(real[i].y)poz[real[i].y].y=i;
        }
        ///poziti x-uman,y real
        for(int i=1;i<=n;++i)cout<<poz[i].x<<" ";
        cout<<'\n';
        for(int i=1;i<=n;++i)cout<<poz[i].y<<" ";
    }
    return 0;
}
