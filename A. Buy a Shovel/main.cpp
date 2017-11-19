#include <iostream>

using namespace std;
int n,k,c,nr=1;
int main()
{
    cin>>n>>k;
    c=n;
    while(n%10!=k && n%10!=0)
    {
        n+=c;
        nr++;
    }
    cout<<nr;
    return 0;
}
