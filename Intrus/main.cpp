#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define mp make_pair
#define pb push_back
#define x first
#define y second
using namespace std;
ifstream in("intrus.in");
ofstream out("intrus.out");
int a[1005][1005],n,m,d,sum,sp[1015][1015],ii,jj,ii2,jj2,maxx[1025][1025];
vector <pair <int,int> > crd[1000005],verif;
vector <pair<pair<int,int>,pair<int,int> > > v;
vector <pair<pair<int,int>,int > > mx;
bool er[1000005];
int cerinta;
int main()
{
    in>>cerinta;
    in>>n>>m>>d;

    for(int i=2;i<=1000000;++i)er[i]=1;
    for(int i=2;i<=1000000;++i)
    {
        for(int j=i+i;j<=1000000;j+=i)er[j]=0;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>a[i][j];
            if(er[a[i][j]])sp[i][j]=1;
            sp[i][j]=sp[i-1][j]+sp[i][j-1]+sp[i][j]-sp[i-1][j-1];
            if(a[i][j]!=0)
            {
                if(er[a[i][j]])mx.pb(mp(mp(a[i][j],i),j));
                crd[a[i][j]].pb(mp(i,j));
            }
        }
    }
    for(int i=1;i<=1000000;++i)
    {
        if(crd[i].size()>1)
        {
            for(auto j:crd[i])verif.pb(j);
        }
    }
    if(cerinta==1)
    {
        out<<verif.size();
    }
    else
    {
        sort(mx.begin(),mx.end());
        for(int i=mx.size()-1;i>=0;--i)
        {
            for(int l=mx[i].x.y;l<mx[i].x.y+d;++l)
            {
                for(int c=mx[i].y;c<mx[i].y+d && maxx[l][c]==0;++c)
                {
                    maxx[l][c]=mx[i].x.x;
                }
            }
        }
        if(verif.size()!=0)
        {
            for(auto i:verif)
            {
                ii=max(1,i.x-d/2)-1;
                jj=max(1,i.y-d/2)-1;
                ii2=min(n,i.x+d/2);
                jj2=min(m,i.y+d/2);
                v.pb(mp(mp(sp[ii2][jj2]+sp[ii][jj]-sp[ii][jj2]-sp[ii2][jj],maxx[i.x+d/2][i.y+d/2]),mp(-i.x,-i.y)));
            }
            sort(v.begin(),v.end());
            for(int i=v.size()-1;i>=0;--i)
            {
                out<<a[-v[i].y.x][-v[i].y.y]<<" "<<-v[i].y.x<<" "<<-v[i].y.y<<'\n';
            }
        }
        else out<<"-1";
    }
    return 0;
}
