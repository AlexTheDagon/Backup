#include <iostream>
#include <fstream>

using namespace std;
ifstream in("date.in");
ofstream out("date.out");

int main()
{int m,n,v,seschimba=1,a[100][100],c=0;
in>>n>>m;
for(int j=0;j<=m+1;j++)
{
    for(int i=0;i<=n+1;i++)
    {
        a[i][j]=1;
    }
}

for(int j=1;j<=m;j++)
{
    for(int i=1;i<=n;i++)
    {
        in>>a[i][j];
    }
}
while(seschimba==1)
{
    seschimba=0;
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            v=0;
            if(a[i][j]==1)
            {
                if(a[i-1][j-1]==0)v++;
                if(a[i-1][j+1]==0)v++;
                if(a[i+1][j-1]==0)v++;
                if(a[i+1][j+1]==0)v++;
            }
            if(v>1)
            {
                a[i][j]=0;
                seschimba=1;
            }
        }
    }
    if(seschimba==1)
    {
        c++;
    }
}
for(int j=1;j<=m;j++)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i][j]==1)c=-1;
    }
}
out<<c;

    return 0;
}
