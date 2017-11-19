#include <iostream>

using namespace std;
int a[30],t,x;
int main()
{
    for(int i=2;i<=29;++i)
    {
        if(i%5==0 || i%3==0)a[i]=i;
        a[i]=a[i]+a[i-1];
    }
    for(int i=1;i<=29;++i)cout<<i<<" "<<a[i]<<endl;
    return 0;
}

