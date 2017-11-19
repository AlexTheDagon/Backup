#include <iostream>

using namespace std;
int a,b,c,nr;
int main()
{
    cin>>a>>b>>c;
    nr=min(a/1,min(b/2,c/4));
    cout<<7*nr;
    return 0;
}
