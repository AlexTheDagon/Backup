#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define NM 105
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
ifstream in("jumps.in");
ofstream out("jumps.out");
int n,dp[NM],viz[NM],maxx;
map<string,int> m;
string s[NM],aux;
vector<int> v[NM];
int dfs(int nod)
{
    if(dp[nod]>1)return dp[nod];
    for(auto i:v[nod])
        dp[nod]=max(dp[nod],dfs(i)+1);
    return dp[nod];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        m[s[i]]=i;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<s[i].size();++j)
        {
            aux=s[i];
            aux.erase(aux.begin()+j);
            if(m.find(aux)!=m.end())v[i].pb(m[aux]);
        }
        for(int j=0;j<s[i].size();++j)
        {
            for(int jj=j+1;jj<s[i].size();++jj)
            {
                if(s[i][jj]>=s[i][j])
                {
                    aux=s[i];
                    aux[j]=aux[jj];
                    if(m.find(aux)!=m.end() && i!=m[aux])v[i].pb(m[aux]);
                }
            }
        }
    }
    for(int i=1;i<=n;++i)dp[i]=1;
    for(int i=1;i<=n;++i)
    {
        if(v[i].size())
            maxx=max(maxx,dfs(i));
    }
    cout<<maxx;
    return 0;
}
