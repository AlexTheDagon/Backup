#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <algorithm>
#define NM 100010
#define KM 35
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair
using namespace std;
ifstream in("blis.in");
ofstream out("blis.out");
int n,a[NM],maxx,k,act,poz,dp[NM],dpsize;
vector <pii> v[NM];
string s;
int main()
{
    in>>k;
    in>>s;
    for(auto i:s)a[++n]=(i-'0');
    dp[0]=-1;
    for(int i=1;i<=n+3;++i)dp[i]=2000000000;
    for(int i=1;i<=n;++i)
    {
        act=0;
        for(int j=0;j<k && i+j<=n;++j)
        {
            act=act*2+a[i+j];///bine
            poz=min(upper_bound(dp+1,dp+n+1,act)-dp,n);
            maxx=max(maxx,act);
            if(dp[poz-1]<act)v[i+j].pb(mp(poz,act));
        }
        for(int j=0;j<v[i].size();++j)
        {
            if(dp[v[i][j].x]>v[i][j].y)dp[v[i][j].x]=v[i][j].y;
        }
        /// v[i][j].x poz pe care se afle elementul terminat pe poz i
        ///
    }
    out<<maxx<<'\n';
    int ind=0;
    for(int i=1;i<=n && dp[i]!=2000000000;++i)++ind;
    out<<ind;
    return 0;
}
/// lgm[poz][nrbiti]--lmax a unui subsir crescator ce se termina pe poz si are nrbiti
