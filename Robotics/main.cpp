#include <iostream>
#include <fstream>
#include <vector>
#define x first.first
#define y first.second
#define z second
#define mp make_pair
#define pb push_back
using namespace std;
ifstream in("robotics.in");
ofstream out("robotics.out");
int a[1005][1005];
vector <pair<pair<int,int>,int> >  v;
pair<pair<int,int>,int> fr;
int n,m,t,vopsea;
int ok(int i,int j)
{
    return (i>0 && i<=n && j>0 && j<=n);
}
int main()
{
    in>>n>>m>>t;
    for(int i=1;i<=m;++i)
    {
        in>>fr.x>>fr.y>>fr.z;
        v.pb(fr);
        a[fr.x][fr.y]=1;
        ++vopsea;
    }
    for(int i=1;i<=t;++i)
    {
        for(auto j:v)
        {
            if(j.z==1)
            {
                if(ok(j.x-i,j.y+i))
                {
                    a[j.x-i][j.y+i]=1;
                    ++vopsea;
                }
                if(ok(j.x+i,j.y-i))
                {
                    a[j.x+i][j.y-i]=1;
                    ++vopsea;
                }
            }
            else
            {
                if(ok(j.x+i,j.y+i))
                {
                    a[j.x+i][j.y+i]=1;
                    ++vopsea;
                }
                if(ok(j.x-i,j.y-i))
                {
                    a[j.x-i][j.y-i]=1;
                    ++vopsea;
                }
            }
        }
    }
    out<<vopsea<<'\n';
    out<<"0 ";
    return 0;
}
