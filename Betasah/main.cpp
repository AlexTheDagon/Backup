#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
#define x first
#define y second
#define mp make_pair
using namespace std;
ifstream in("betasah.in");
ofstream out("betasah.out");
int a[1005][1005],n,d,k,ii,jj,patratele,cur,maxx,linie;
vector <pair<int,int> > v;
pair<int,int> fr;
int ok(int i,int j)
{
    return(i>0 && i<=n && j>0 && j<=i);
}
int main()
{
    in>>n>>d>>k;
    for(int i=1;i<=d;++i)
    {
        in>>ii>>jj;
        a[ii][jj]=-2;
        v.pb(mp(ii,jj));
    }
    for(int i=1;i<=k;++i)
    {
        in>>ii>>jj;
        a[ii][jj]=-1;
    }
    for(int i=1;i<=n;++i)
    {
        linie=0;
        for(int j=1;j<=i;++j)
        {
            if(a[i][j]>=0 || a[i][j]==-2)++linie;
        }
        maxx=max(maxx,linie);
    }
    out<<maxx<<'\n';
    for(auto i:v)
    {
        fr=i;
        ++fr.x;
        while(a[fr.x][fr.y]>=0 && ok(fr.x,fr.y))
        {
            a[fr.x][fr.y]=2;
            ++fr.x;
        }
        fr=i;
        --fr.x;
        while(a[fr.x][fr.y]>=0 && ok(fr.x,fr.y))
        {
            a[fr.x][fr.y]=2;
            --fr.x;
        }
        fr=i;
        ++fr.y;
        while(a[fr.x][fr.y]>=0 && ok(fr.x,fr.y))
        {
            a[fr.x][fr.y]=2;
            ++fr.y;
        }
        fr=i;
        --fr.y;
        while(a[fr.x][fr.y]>=0 && ok(fr.x,fr.y))
        {
            a[fr.x][fr.y]=2;
            --fr.y;
        }
        ///aaaaa
        fr=i;
        ++fr.x;
        ++fr.y;
        while(a[fr.x][fr.y]>=0 && ok(fr.x,fr.y))
        {
            a[fr.x][fr.y]=2;
            ++fr.x;
            ++fr.y;
        }
        fr=i;
        --fr.x;
        --fr.y;
        while(a[fr.x][fr.y]>=0 && ok(fr.x,fr.y))
        {
            a[fr.x][fr.y]=2;
            --fr.x;
            --fr.y;
        }
        fr=i;
        --fr.x;
        ++fr.y;
        while(a[fr.x][fr.y]>=0 && ok(fr.x,fr.y))
        {
            a[fr.x][fr.y]=2;
            --fr.x;
            ++fr.y;
        }
        fr=i;
        ++fr.x;
        --fr.y;
        while(a[fr.x][fr.y]>=0 && ok(fr.x,fr.y))
        {
            a[fr.x][fr.y]=2;
            ++fr.x;
            --fr.y;
        }
    }

    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)if(a[i][j]==2)++patratele;
    out<<patratele;
    return 0;
}
