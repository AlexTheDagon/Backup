#include <iostream>

using namespace std;
int a[101],x,s,maxx;
int main()
{
    for(int i=1;i<=5;i++)
    {
        cin>>x;
        s+=x;
        a[x]++;
    }
    for(int i=100;i>=0;--i)
    {
        if(a[i]>=2)
        {
            maxx=max(min(a[i],3)*i,maxx);
        }
    }
    s=s-maxx;
    cout<<s;

    return 0;
}
