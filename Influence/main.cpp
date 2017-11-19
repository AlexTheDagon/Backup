#include <iostream>
#include <vector>
#include <bitset>
#define pb push_back
using namespace std;
bitset <5005> a[5005];
vector <int> v[5005],bad;
string s;
int viz[5005];
int getnr();
int n,k,x,y,poz,maxx,sol,aux;
bitset<5005> dfs(int nod)
{
    if(viz[nod])return a[nod];
    viz[nod]=1;
    for(auto i:v[nod])
    {
        a[nod]=a[nod]|dfs(i);
    }
    return a[nod];
}
int cnt(bitset<5005> b);
int main()
{
    while(cin>>n>>k)
    {
        maxx=0;
        sol=0;
        getline(cin,s);
        for(int i=1;i<=k;++i)
        {
            cin>>x;
            bad.pb(x);
        }
        getline(cin,s);
        for(int i=1;i<=n;++i)
        {
            poz=0;
            s.clear();
            getline(cin,s);
            x=0;
            while(poz<s.size())
            {
                if(isdigit(s[poz]))
                {
                    if(x==0)
                    {
                        x=getnr();
                    }
                    else
                    {
                        y=getnr();
                        v[x].pb(y);
                    }
                }
                ++poz;
            }
        }
        ///bine   bad-tipii X,a-bitseturile
        for(int i=1;i<=n;++i)a[i][i]=1;
        for(auto badguy:bad)
        {
            dfs(badguy);
            aux=cnt(a[badguy]);
            if(aux>maxx)
            {
                maxx=aux;
                sol=badguy;
            }
            if(aux==maxx && badguy<sol)sol=badguy;
        }
        cout<<sol<<'\n';
        for(int i=1;i<=n;++i)
        {
            v[i].clear();
            viz[i]=0;
            a[i].reset();
        }
    }
    return 0;
}
int getnr()
{
    int nr=0;
    while(isdigit(s[poz]))
    {
        nr=nr*10+s[poz]-'0';
        ++poz;
    }
    return nr;
}
int cnt(bitset<5005> b)
{
    int nrb=0;
    for(int i=1;i<=n;++i)if(b[i])++nrb;
    return nrb;
}
