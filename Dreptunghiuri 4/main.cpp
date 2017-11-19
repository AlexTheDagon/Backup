#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#define pb push_back
#define NM 1050
using namespace std;
ifstream in("dreptunghiuri4.in");
ofstream out("dreptunghiuri4.out");
long long x1[NM],yy1[NM],x2[NM],yy2[NM],n,k,s,xx,yy,xv[NM],yv[NM],lin;
vector <int> x,y,ax,ay;
map<int,int> mx,mm;
int fr[NM][NM];
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)
    {
        in>>x1[i]>>yy1[i]>>x2[i]>>yy2[i];
        x1[i]+=11;
        x2[i]+=10;
        yy1[i]+=11;
        yy2[i]+=10;
        ax.pb(x1[i]);
        ax.pb(x2[i]);
        ay.pb(yy1[i]);
        ay.pb(yy2[i]);
    }
    sort(ax.begin(),ax.end());
    sort(ay.begin(),ay.end());
    for(auto i:ax)
    {
        if(x.size()==0)x.pb(i);
        else if(x[x.size()-1]!=i)x.pb(i);
    }
    for(auto i:ay)
    {
        if(y.size()==0)y.pb(i);
        else if(y[y.size()-1]!=i)y.pb(i);
    }
    ax.clear();
    ay.clear();
    ///bine
    for(auto i:x)
    {
        ++xx;
        mx[i]=xx;
        xv[xx]=i;
    }
    for(auto i:y)
    {
        ++yy;
        mm[i]=yy;
        yv[yy]=i;
    }
    y.clear();
    x.clear();
    ///bine
    for(int i=1;i<=n;++i)
    {
        ++fr[mx[x1[i]]][mm[yy1[i]]];
        ++fr[mx[x2[i]]+1][mm[yy2[i]]+1];
        --fr[mx[x2[i]]+1][mm[yy1[i]]];
        --fr[mx[x1[i]]][mm[yy2[i]]+1];
    }
    for(int i=1;i<NM-5;++i)
        for(int j=1;j<=NM-5;++j)
            fr[i][j]=fr[i][j]+fr[i-1][j]+fr[i][j-1]-fr[i-1][j-1];
    xv[xx+1]=xv[xx]+1;
    for(int i=1;i<=xx;++i)
    {
        lin=0;
        for(int j=1;j<=yy;++j)
            if(fr[i][j]==k)++lin;
        s+=lin*(xv[i+1]-xv[i]);

    }
    out<<s;
    return 0;
}
