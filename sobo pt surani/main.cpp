#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("sobo.in");
ofstream fout("sobo.out");
const int Nmax=15+2,Lmax=1000+5;
const int Dpmax=1<<15;
const int INF=0x3f3f3f3f;
int dp[Dpmax],col[Dpmax],cost[Lmax];
int n,l;
string s;
int solve(int conf)
{
    //cout<<"Am intrat in config "<<conf<<'\n';
    if(dp[conf]!=INF)return dp[conf];
    int newconf1,newconf2,helper=0;
    for(int i=1;i<=l;i++)
    {
        helper=0;
        newconf1=conf & col[i];
        for(int j=0;j<n;j++)
            if((col[i] & (1<<j))==0)helper+=(1<<j);
        //cout<<helper<<" ";
        newconf2=conf & helper;
        if(newconf1!=conf && newconf2!=conf)dp[conf]=min(dp[conf],max(solve(newconf1),solve(newconf2))+cost[i]);
    }
    return dp[conf];
}
int main()
{
    fin>>n>>l;
    for(int i=1;i<=Dpmax;++i)dp[i]=INF;
    for(int i=0;i<n;++i)dp[1<<i]=0;
    for(int i=1;i<=n;++i)
    {
        fin>>s;
        for(int j=0;j<s.size();++j)
            if(s[j]=='1')col[j+1]=col[j+1]+(1<<(i-1));
    }
    for(int i=1;i<=l;++i)
        fin>>cost[i];
    for(int i=1;i<=n;++i)
    {
        int helper=0;
        //fout<<col[i]<<" ";
        for(int j=0;j<n;j++)
            if((col[i] & (1<<j))==0)helper+=(1<<j);
        //fout<<helper<<'\n';
    }
    fout<<solve((1<<(n))-1);
    return 0;
}
