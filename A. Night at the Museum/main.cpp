#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
char a[105],x,y;
int l;
int main()
{
    cin>>a;
    x='a';
    l=0;
    for(int i=0;a[i]!=(char)0;++i)
    {
        y=a[i];
        if(i>0)x=a[i-1];
        l=l+min(abs(y-x),'z'-'a'-abs(y-x)+1);
    }
    cout<<l;
    return 0;
}
