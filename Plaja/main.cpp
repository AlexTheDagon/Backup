#include <iostream>
#include <fstream>
using namespace std;
ifstream in("plaja.in");
ofstream out("plaja.out");
int x[2001][2001],u,a1,a2,b1,b2,sp[2001][2001],t,l,m,n,ta,ll=0,sem;
pair<int,int> y[105];
int main()
{
    in>>n>>m>>u;
    for(int i=0;i<u;++i)in>>y[i].first>>y[i].second;
    in>>t;
    for(int i=0;i<t;++i)
    {
        in>>a1>>b1>>a2>>b2;
        sem=0;
        for(int j=0;j<u;++j)
        {
            if(a1<=y[j].first && y[j].first<=a2 && b1<=y[j].second && b2>=y[j].second)sem=1;
        }
        if(sem==0)
        {
            x[a1][b1]++;
            x[a2+1][b1]--;
            x[a1][b2+1]--;
            x[a2+1][b2+1]++;
            ta++;
        }
    }
    ///bine
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            sp[i][j]=sp[i-1][j]+sp[i][j-1]+x[i][j]-sp[i-1][j-1];
        }
    }
    ///bine
    out<<ta<<" ";
    in>>l;
    for(int i=0;i<u;++i)++sp[y[i].first][y[i].second];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            sp[i][j]=sp[i-1][j]+sp[i][j-1]+sp[i][j]-sp[i-1][j-1];
        }
    }
    for(int i=0;i<l;++i)
    {
        in>>a1>>b1>>a2>>b2;
        if((sp[a2][b2]-sp[a2][b1-1]-sp[a1-1][b2]+sp[a1-1][b1-1])==0)ll++;
    }
    out<<ll;

    return 0;
}
