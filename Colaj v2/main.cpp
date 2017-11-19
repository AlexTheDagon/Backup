#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#define pb push_back
#define f first
#define s second
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
using namespace std;
ifstream in("colaj.in");
ofstream out("colaj.out");
map <int,int> noux,nouy;
vector <int> sortx,sorty;
vector <pair<pair<int,int>,pair<int,int> > > v;
pair<pair<int,int>,pair<int,int> > fr;
pair<int,int> p;
queue <pair<int,int> > q;
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
int ii,jj,is,ifin,js,jf;
int x,y,z,t,nr,n,m,ultx,ulty,zone;
int folx,foly;
char a[500][500];
int ok(int i,int j)
{
    return(i>=0 && i<=n && j>=0 && j<=m);
}

int main()
{
    in>>nr;
    in>>m>>n;
    --n;
    --m;
    for(int i=1;i<=nr;++i)
    {
        in>>fr.fs>>fr.ff>>fr.ss>>fr.sf;
        --fr.sf;
        --fr.ss;
        sortx.pb(fr.ff);
        sortx.pb(fr.sf);
        sorty.pb(fr.fs);
        sorty.pb(fr.ss);
        v.pb(fr);
    }
    sortx.pb(n);
    sorty.pb(m);
    sort(sortx.begin(),sortx.end());
    sort(sorty.begin(),sorty.end());
    ultx=sortx[0];
    ulty=sorty[0];
    noux[sortx[0]]=min(1,sortx[0]);
    nouy[sorty[0]]=min(1,sorty[0]);
    folx=noux[sortx[0]];
    foly=nouy[sorty[0]];
    for(int i=1;i<sortx.size();++i)
    {
        if(sortx[i]!=ultx)
        {
            ++folx;
            ++folx;
            noux[sortx[i]]=folx;
        }
        ultx=sortx[i];
    }
    for(int i=1;i<sorty.size();++i)
    {
        if(sorty[i]!=ulty)
        {
            ++foly;
            ++foly;
            nouy[sorty[i]]=foly;
        }
        ulty=sorty[i];
    }
    n=noux[n];
    m=nouy[m];
    for(int i=0;i<v.size();++i)
    {
        fr=v[i];
        for(int linie=noux[fr.ff];linie<=noux[fr.sf];++linie)
        {
            for(int coloana=nouy[fr.fs];coloana<=nouy[fr.ss];++coloana)a[linie][coloana]=1;
        }
    }
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            if(a[i][j]==0)
            {
                ++zone;
                a[i][j]=1;
                q.push(make_pair(i,j));
                while(!q.empty())
                {
                    p=q.front();
                    q.pop();
                    for(int d=0;d<4;++d)
                    {
                        ii=p.f+dx[d];
                        jj=p.s+dy[d];
                        if(ok(ii,jj) && a[ii][jj]==0)
                        {
                            a[ii][jj]=1;
                            q.push(make_pair(ii,jj));
                        }
                    }
                }
            }
        }
    }
    out<<zone;
    return 0;
}
