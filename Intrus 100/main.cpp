#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define pb push_back
#define mp make_pair
#define niv first.first
#define maxv first.second
#define l second.first
#define c second.second
#define NM 1050
using namespace std;
ifstream in("intrus.in");
ofstream out("intrus.out");
int d,a[NM][NM],er[NM*NM],fr[NM*NM],per,sp[NM][NM],maxx[NM][NM],n,m,p;
vector<pair<pair<int,int>,pair<int,int> > > v;
void ciur()
{
    for(int i=2;i<=1000000;++i)er[i]=1;
    for(int i=2;i<=1000000;++i)
    {
        if(er[i]==1)for(int j=i+i;j<=1000000;j+=i)er[j]=0;
    }
}
int main()
{
    ciur();
    in>>p>>n>>m>>d;
    for(int i=d;i<n+d;++i)
        for(int j=d;j<m+d;++j)
            in>>a[i][j];
    for(int i=d;i<n+d;++i)
    {
        for(int j=d;j<m+d;++j)
        {
            if(er[a[i][j]])
            {
                for(int k=i-d/2;k<=i+d/2;++k)
                    for(int kk=j-d/2;kk<=j+d/2;++kk)maxx[k][kk]=max(maxx[k][kk],a[i][j]);
                ++sp[i-d/2][j-d/2];
                --sp[i-d/2][j+d/2+1];
                --sp[i+d/2+1][j-d/2];
                ++sp[i+d/2+1][j+d/2+1];
            }
            ++fr[a[i][j]];
        }
    }
    if(p==1)
    {
        for(int i=1;i<=1000000;++i)if(fr[i]>1)per+=fr[i];
        out<<per;
    }
    else
    {
        for(int i=d;i<n+d;++i)
            for(int j=d;j<m+d;++j)sp[i][j]+=(sp[i-1][j]+sp[i][j-1]-sp[i-1][j-1]);
        for(int i=d;i<n+d;++i)
            for(int j=d;j<m+d;++j)if(fr[a[i][j]]>1 && a[i][j]!=0)v.pb(mp(mp(sp[i][j],maxx[i][j]),mp(-(i-d+1),-(j-d+1))));
        sort(v.begin(),v.end());
        if(v.size())
        {
            for(int i=v.size()-1;i>=0;--i)
            {
                out<<a[-v[i].l+d-1][-v[i].c+d-1]<<" "<<-v[i].l<<" "<<-v[i].c<<'\n';
            }
        }
    }
    return 0;
}
