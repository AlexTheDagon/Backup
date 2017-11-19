#include <iostream>
#include <fstream>
using namespace std;
ifstream in("gradina3.in");
ofstream out("gradina3.out");
int n,k,p,a,b,sp[1005][1005],maxx,moduri;
int main()
{
    in>>n>>p>>k;
    for(int i=1;i<=p;++i)
    {
        in>>a>>b;
        sp[a][b]=1;
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)sp[i][j]=sp[i][j]+sp[i-1][j]+sp[i][j-1]-sp[i-1][j-1];
    for(int i=k;i<=n;++i)
    {
        for(int j=k;j<=n;++j)
        {
            if(sp[i][j]-sp[i-k][j]-sp[i][j-k]+sp[i-k][j-k]>maxx)
            {
                maxx=sp[i][j]-sp[i-k][j]-sp[i][j-k]+sp[i-k][j-k];
                moduri=0;
            }
            if(sp[i][j]-sp[i-k][j]-sp[i][j-k]+sp[i-k][j-k]==maxx)++moduri;
        }
    }
    out<<maxx<<'\n'<<moduri;
    return 0;
}
