#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <queue>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define NM 1005
using namespace std;
ifstream in("pandora.in");
ofstream out("pandora.out");
vector<int> v;
vector<pair<int,int> > b;
queue<pair<int,int> > q;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int ii,jj;
int m,n,k,x,y,c,s,ss;
int a[NM][NM],sp1[NM][NM],sp2[NM][NM],nr,nrr,maxx;
pair<int,int> fr;
int sem;
bool viz[NM][NM];
int myrandom(int i)
{
    return rand()%i;
}
int main()
{
    srand(time(0));
    in>>n>>k>>m;
    for(int i=0;i<=1005;++i)v.push_back(i);
    for(int i=1;i<=m;++i)
    {
        in>>x>>y>>c;
        a[x][y]=c;
        b.pb(mp(x,y));
    }
    random_shuffle(v.begin(),v.end(),myrandom);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            sp1[i][j]=sp1[i-1][j]+sp1[i][j-1]-sp1[i-1][j-1]+a[i][j];
            sp2[i][j]=sp2[i-1][j]+sp2[i][j-1]-sp2[i-1][j-1]+v[a[i][j]];
        }
    }
    sort(b.begin(),b.end());
    for(int i=0;i<b.size();++i)
    {
        fr=b[i];
        if(fr.f+k-1<=n && fr.s+k-1<=n && viz[fr.f][fr.s]==0)
        {
            s=-(a[fr.f][fr.s]+a[fr.f+k-1][fr.s+k-1]+a[fr.f][fr.s+k-1]+a[fr.f+k-1][fr.s]);
            ss=-(v[a[fr.f][fr.s]]+v[a[fr.f+k-1][fr.s+k-1]]+v[a[fr.f][fr.s+k-1]]+v[a[fr.f+k-1][fr.s]]);;
            maxx=(max(max(a[fr.f][fr.s],a[fr.f+k-1][fr.s+k-1]),max(a[fr.f][fr.s+k-1],a[fr.f+k-1][fr.s])));
            nr=a[fr.f+1][fr.s+1];
            nrr=v[a[fr.f+1][fr.s+1]];
            s+=sp1[fr.f+k-1][fr.s+k-1]-sp1[fr.f+k-1][fr.s-1]-sp1[fr.f-1][fr.s+k-1]+sp1[fr.f-1][fr.s-1];
            ss+=sp2[fr.f+k-1][fr.s+k-1]-sp2[fr.f+k-1][fr.s-1]-sp2[fr.f-1][fr.s+k-1]+sp2[fr.f-1][fr.s-1];
            if(ss==nrr*(k*k-4) && s==nr*(k*k-4) && maxx<nr)
            {
                out<<fr.f<<" "<<fr.s<<'\n';
                sem=1;
                q.push(fr);
                viz[fr.f][fr.s]=1;
                while(!q.empty())
                {
                    fr=q.front();
                    q.pop();
                    for(int d=0;d<4;++d)
                    {
                        ii=fr.f+dx[d];
                        jj=fr.s+dy[d];
                        if(viz[ii][jj]==0 && a[ii][jj]!=0)
                        {
                            q.push(mp(ii,jj));
                            viz[ii][jj]=1;
                        }
                    }
                }
            }
        }
    }
    if(sem==0)out<<"0";
    return 0;
}
///solutia 1:
///Mapam de (2-3,nu mai stiu sigur)matricea si facem asemanator omogene

///SOlutia 2:
///    FOrmam patrate ca la problema Custi(infoarena)
