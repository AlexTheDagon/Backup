#include <iostream>
#include <fstream>
using namespace std;
ifstream in("culori3.in");
ofstream out("culori3.out");
int cur[7][10001],p[7][10001],n,sem,ad,nr[10001],cifp[7],cifc[7];;
void sum(int i)
{
    for(int j=1;j<=max(cifp[i+1],cifp[i-1])+1;++j)
    {
        cur[i][j]=(cur[i][j]+p[i-1][j]+p[i+1][j])%10;
        cur[i][j+1]=(p[i-1][j]+p[i+1][j])/10;
    }
    cifc[i]=max(cifp[i+1],cifp[i-1]);
    if(cur[i][cifc[i]+1]!=0)cifc[i]++;
}
int main()
{
    in>>n;
    for(int i=1;i<=5;++i)
    {
        p[i][1]=1;
        cifp[i]=1;
    }
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=5;++j)sum(j);
        for(int j=1;j<=5;++j)
        {
            for(int l=1;l<=cifc[i];++l)
            {
                p[j][l]=cur[j][l];
                cur[j][l]=0;
            }
            cifp[i]=cifc[i];
            cifc[i]=0;
        }
    }
    for(int i=1;i<=5;++i)
    {
        nr[0]=max(nr[0],cifp[i]);
        for(int j=1;j<=10000;++j)
        {
            nr[j]+=p[i][j];

        }
    }
    cout<<nr[0];
    for(int j=1;j<=10000;++j)
        {
            if(nr[j]>=10)
            {
                nr[j+1]+=nr[j]/10;
                nr[j]=nr[j]%10;
            }
        }
    if(nr[nr[0]+1]!=0)nr[0]++;
    for(int i=1000;i>0;--i)
    {
        if(sem==1)out<<nr[i];
        else if(nr[i]!=0){out<<nr[i];sem=1;}
    }
    cout<<nr[0]<<endl<<nr[2]<<nr[1];
    return 0;
}
