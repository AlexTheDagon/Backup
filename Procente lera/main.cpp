#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
ifstream fin("procente.in");
ofstream fout("procente.out");
int divz[]={1,2,4,5,8,10,16,20,25,32,40,50,64,80,100,125,128,160,200};
int div2[]={0,1,2,0,3,1,4,2,0,5,3,1,6,4,2,0,7,5,3};
int div5[]={0,0,0,1,0,1,0,1,2,0,1,2,0,1,2,3,0,1,2};
long long dp[200][200][100];
int n,pr,p2,p5,ind;
char c;
int dfind()
{
    for(int i=0;i<19;i++)
        if(divz[i]==pr)
            return i;
            return -1;
}
int main()
{
    fin>>n>>c>>pr;
    if(c=='-')pr=100-pr;
    else pr=100+pr;
    ind=dfind();
    if(ind==-1)
    {
        fout<<0;
        return 0;
    }
    p2=2*n-div2[ind];
    p5=2*n-div5[ind];
    dp[0][0][0]=1;
    for(int nr=0;nr<19;nr++)
        for(int x=0;x<=p2;x++)
            for(int y=0;y<=p5;y++)
                for(int k=0;k<n-1;k++)
                dp[x+div2[nr]][y+div5[nr]][k+1]+=dp[x][y][k];
    fout<<dp[p2][p5][n-1];
    return 0;
}
