#include <iostream>
#include <fstream>
using namespace std;
ifstream in("culori3.in");
ofstream out("culori3.out");
int cur[7][10000],p[7][10000],n,sem,ad,nr[10001];
void sum(int i)
{
    for(int j=1;j<=max(p[i-1][0],p[i+1][0]);++j)
    {
        cur[i][j]=(cur[i][j]+p[i-1][j]+p[i+1][j])%10;
        cur[i][j+1]=(p[i-1][j]+p[i+1][j])/10;
    }
    p[i][0]=max(p[i-1][0],p[i+1][0]);
    if(cur[i][max(p[i-1][0],p[i+1][0])+1]!=0)p[i][0]++;
}
int main()
{
    in>>n;
    for(int i=1;i<=5;++i)
    {
        p[i][1]=1;
        p[i][0]=1;
    }
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=5;++j)sum(j);
        for(int j=1;j<=5;++j)
        {
            for(int l=1;l<=p[j][0];++l)
            {
                p[j][l]=cur[j][l];
                cur[j][l]=0;
            }
        }
    }
    for(int i=1;i<=5;++i)
    {
        nr[0]=max(nr[0],p[i][0]);
        for(int j=1;j<=10000;++j)
        {
            nr[j]+=p[i][j];
            if(nr[j]>10)
            {
                nr[j+1]+=nr[j]/10;
                nr[j]=nr[j]%10;
            }
        }
    }
    if(nr[nr[0]+1]!=0)nr[0]++;
    for(int i=nr[0];i>0;--i)
    {
        out<<nr[i];
    }
    return 0;
}
