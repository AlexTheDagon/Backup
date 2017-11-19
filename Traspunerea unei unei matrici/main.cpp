#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,m,aux,a[100][100],da=1,maxim=-100000,i1,j1,x,y,p,v[10000],w,c,i,j;
int main()
{in>>n>>m;
p=m*n;
c=p;
for(int k=0;k<n;k++)
{
    for(int l=0;l<m;l++)in>>a[k][l];
}
while(p>0)
{

    for(j=j1;j<m-1;j++)
    {
        v[w]=a[i][j];
        w++;
        p--;
    }
    j++;
    for(i=i1;i<n-1;i++)
    {
        v[w]=a[i][j];
        w++;
        p--;
    }
    i++;
    for(j=m;j>0;j--)
    {
        v[w]=a[i][j];
        w++;
        p--;
    }
    j--;

    for(i=n;i>1;i--)
    {
        v[w]=a[i][j];
    }

    i1++;
    j1++;
    m--;
    n--;
}
for(int i=0;i<c+100;i++)out<<v[i];

    return 0;
}
