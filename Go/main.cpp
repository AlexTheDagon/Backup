#include <iostream>
#include <fstream>

using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,m,k,a[1000][1000],i1,i2,j1,j2,s=0,s1;

int main()
{in>>n>>m>>k;
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=m;j++)
    {
        in>>a[i][j];
    }
}
while(k>0)
{
    s1=0;
    in>>i1>>j1>>i2>>j2;
    for(int i=i1;i<=i2;i++)
    {
        for(int j=j1;j<=j2;j++)
        {
            s1=s1+a[i][j];
        }
    }
    if(s1>s)
    {
        s=s1;
    }
    k--;
}
out<<s;

    return 0;
}
