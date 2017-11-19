#include <iostream>
#include <fstream>
using namespace std;
ifstream in("submultimi.in");
ofstream out("submultimi.out");
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
    in>>n;
    for(k=1;k<=n;++k)back(1);
    return 0;
}

