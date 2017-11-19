#include <iostream>

using namespace std;
int k,n,w;
int main()
{
    cin>>k>>n>>w;
    cout<<max(k*(w+1)*w/2-n,0);
    return 0;
}
