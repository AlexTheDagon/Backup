#include <iostream>
#include <fstream>
using namespace std;
ifstream in("procente.in");
ofstream out("procente.out");
long long dp[205][205][105];
int put[3][205];
int x,y,n;
int p;
char s;
int nr[]={1,2,4,5,8,10,16,20,25,32,40,50,64,80,100,125,128,160,200};
int main()
{
    in>>n;
    for(int i=0;i<19;++i)put[0][nr[i]]=1;
    put[1][1]=0;
    put[2][1]=0;
    put[1][2]=1;
    put[2][2]=0;
    put[1][4]=2;
    put[2][4]=0;
    put[1][5]=0;
    put[2][5]=1;
    put[1][8]=3;
    put[2][8]=0;
    put[1][10]=1;
    put[2][10]=1;
    put[1][16]=4;
    put[2][16]=0;
    put[1][20]=2;
    put[2][20]=1;
    put[1][25]=0;
    put[2][25]=2;
    put[1][32]=5;
    put[2][32]=0;
    put[1][40]=3;
    put[2][40]=1;
    put[1][50]=1;
    put[2][50]=2;
    put[1][64]=6;
    put[2][64]=0;
    put[1][80]=4;
    put[2][80]=1;
    put[1][100]=2;
    put[2][100]=2;
    put[1][125]=0;
    put[2][125]=3;
    put[1][128]=7;
    put[2][128]=0;
    put[1][160]=5;
    put[2][160]=1;
    put[1][200]=3;
    put[2][200]=2;
    ///Sper ca e bine
    in>>s>>p;
    if(s=='+')p+=100;
    else p=100-p;
    if(put[0][p]==0)out<<"0";
    else
    {
        dp[put[1][p]][put[2][p]][1]=1;
        for(int l=0;l<19;++l)
        {
            for(int i=0;i<=2*n;++i)
            {
                for(int j=0;j<=2*n;++j)
                {
                    for(int k=1;k<n;++k)
                    {
                        dp[i+put[1][nr[l]]][j+put[2][nr[l]]][k+1]+=dp[i][j][k];
                    }
                }
            }
        }
        out<<dp[2*n][2*n][n];
    }
    return 0;
}
