#include <iostream>
#include <algorithm>
using namespace std;
int n,a[100];
bool cmp(int x,int y){return (x%10<y%10);}
int main()
{cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
}
sort(a,a+n,cmp);
for(int i=1;i<=n;i++)
{
    cout<<a[i]<<" ";
}

    return 0;
}
