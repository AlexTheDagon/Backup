#include <iostream>
#include <fstream>
using namespace std;
ifstream in("combinari.in");
ofstream out("combinari.out");
int n,a[19],k;
void back(int m)
{
    int i;
    if(m==k+1)
    {
        for(int j=1;j<=k;j++)out<<a[j]<<" ";
        out<<'\n';
    }
    else
    {
        for(i=a[m-1]+1;i<=n-k+m;i++)
        {
            a[m]=i;
            back(m+1);
        }
    }
}
int main()
{
    in>>n>>k;
    back(1);
    return 0;
}
