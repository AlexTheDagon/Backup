#include <iostream>
#include <fstream>
#define L 1005
#define N 20
#include <bitset>
using namespace std;
ifstream in("sobo.in");
ofstream out("sobo.out");
bitset <35000> put;
int n,dp[(1<<15)+5],l,harta[L],cost[L],x,st,nharta[L];
string s[N];
void tipar(int config)
{
    for(int i=n-1;i>=0;--i)cout<<((config&(1<<i))!=0);
}
int solve(int conf)
{
    if(dp[conf]!=(1<<30))return dp[conf];
    short newconf0,newconf1;
    for(int i=0;i<l;++i)
    {
        newconf1=conf&harta[i];
        newconf0=conf&nharta[i];
        if(newconf1!=conf && newconf0!=conf)dp[conf]=min(dp[conf],(max(solve(newconf1),solve(newconf0))+cost[i]));
    }
    return dp[conf];
}
int main()
{
    in>>n>>l;
    for(int i=0;i<n;++i)in>>s[i];
    for(int i=0;i<l;++i)in>>cost[i];
    for(int i=1;i<(1<<n);++i)dp[i]=(1<<30);
    for(int i=0;i<n;++i)dp[1<<i]=0;
    for(int j=0;j<l;++j)
    {
        for(int i=n-1;i>=0;--i)
        {
            harta[j]=(harta[j]<<1)|(s[i][j]-'0');
            nharta[j]=(nharta[j]<<1)|((s[i][j]-'0')==0);
        }
    }
    st=(1<<n)-1;
    out<<solve(st);

    return 0;
}




















///1 1 1 1 0
///0-->nu mia poate fi candidat special
///1-->mai sunt candidati

///dp(configuratie)=cost minim total daca incepem de la CONFIGURATIE si ajungem la finaL(cand avem un sigur bit de 1:0001,0010,...)
///deci finaL=2^i

///punem intrebari pe 1 si pt 0 la fiecare coloana
///solve(conf)-->se verif fiecare poz pt 0 si pt 1(Sa nu uit sa verific ca sa se schimbe ceva mai departe)

///solve(conf)
///{
  ///  dp(conf)=1<<30;
   /// for(i=1;i<=l;++i)
   /// {
   ///     newconf0
   ///     newconf1
   /// }
///}
