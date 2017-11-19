#include <iostream>

using namespace std;
int t,s,x;
int main()
{
    cin>>t>>s>>x;
    if(((x-t-1)%s==0 || (x-t)%s==0) && x>t+1 || x==t)cout<<"YES";
    else cout<<"NO";
    return 0;
}
