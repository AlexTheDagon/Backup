#include <iostream>
#include <fstream>
using namespace std;
ifstream in("minerale.in");
ofstream out("minerale.out");
int lit[105][105],m,r,c[30][30],l[30],viz[105][105];
string s1,s2,s;
int dp(int i,int j)
{
    if(i==j)return l[s[i]-'a'];
    for(int k=i;k<j;++k)
    {
        if(viz[i][k]==0)lit[i][k]=dp(i,k);
        if(viz[k+1][j]==0)lit[k+1][j]=dp(k+1,j);
        for(int ii=0;ii<26;++ii)
            if((lit[i][k]&(1<<ii)))
                for(int jj=0;jj<26;++jj)
                    if(lit[k+1][j]&(1<<jj))lit[i][j]|=c[ii][jj];
    }
    viz[i][j]=1;
    return lit[i][j];
}
int main()
{
    in>>r>>m;
    for(int i=1;i<=r;++i)
    {
        in>>s1>>s2;
        if(s2.size()==1)l[s2[0]-'a']|=(1<<(s1[0]-'A'));
        else c[s2[0]-'A'][s2[1]-'A']|=(1<<s1[0]-'A');
    }
    for(int i=1;i<=m;++i)
    {
        s="";
        in>>s;
        for(int i=0;i<s.size();++i)
            for(int j=0;j<s.size();++j)lit[i][j]=viz[i][j]=0;
        lit[0][s.size()-1]=dp(0,s.size()-1);
        if(lit[0][s.size()-1]==0)out<<"0";
        else
        {
            if(lit[0][s.size()-1]&(1<<('S'-'A')))out<<"1";
            else out<<"2";
        }
        out<<'\n';
    }
    return 0;
}

