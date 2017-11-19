#include <iostream>
#include <algorithm>
using namespace std;
int n,a[100],s,s1,j;
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        s+=a[i];
    }
    sort(a,a+n);
    j=n;
    while(s1<=s)
    {
        --j;
        s1+=a[j];
        s-=a[j];
    }
    cout<<n-j;
    return 0;
}
