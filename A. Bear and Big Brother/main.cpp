#include <iostream>

using namespace std;
int a,b,ani;
int main()
{
    cin>>a>>b;
    while(a<=b)
    {
        ++ani;
        a=a*3;
        b=b*2;
    }
    cout<<ani;
    return 0;
}
