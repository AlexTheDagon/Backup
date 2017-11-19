#include <iostream>

using namespace std;
int n,minn,maxx;
int main()
{
    cin>>n;
    minn=n/7*2;
    if(n%7==6)minn++;
    maxx=n/7*2+min(n%7,2);
    cout<<minn<<" "<<maxx;
    return 0;
}
