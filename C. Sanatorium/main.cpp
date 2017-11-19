#include <iostream>

using namespace std;
long long maxx,a,b,c,z;
int main()
{
    cin>>a>>b>>c;
    z=0;
    maxx=max(a,max(b,c));
    cout<<max(maxx-1-a,z)+max(maxx-1-b,z)+max(maxx-1-c,z);
    return 0;
}
