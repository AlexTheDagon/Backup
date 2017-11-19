#include <iostream>
#include <fstream>
#include <deque>
#define mp make_pair
#define pb pop_back
#define pf push_front
#define x first
#define y second
using namespace std;
ifstream in("aiacusarpe.in");
ofstream out("aiacusarpe.out");
int n,m,t,s,sm;
char c;
int viz[1005][1005],ii,jj;
deque <pair<int,int> > d;
int ok(int i,int j)
{
    return (i>0 && i<=n && j>0 && j<=m);
}
int main()
{
    in>>n>>m;
    in>>t;
    ii=1;
    jj=1;
    s=1;
    viz[1][1]=1;
    d.pf(mp(1,1));
    for(int i=1;i<=t && ok(ii,jj);++i)
    {
        in>>c;
        if(c=='N')--ii;
        if(c=='S')++ii;
        if(c=='E')++jj;
        if(c=='V')--jj;
        if(ok(ii,jj))
        {
            if(viz[ii][jj]==1)
            {
                pair<int,int> fr;
                fr=mp(ii,jj);
                while(d.back()!=fr)
                {
                    viz[d.back().x][d.back().y]=0;
                    d.pb();
                    --s;
                }
                viz[d.back().x][d.back().y]=0;
                d.pb();
                --s;
            }
            viz[ii][jj]=1;
            ++s;
            d.pf(mp(ii,jj));
            sm=max(s,sm);
        }
    }
    out<<sm;
    return 0;
}
