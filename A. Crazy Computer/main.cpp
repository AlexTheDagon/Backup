#include <iostream>

using namespace std;
int a,b,n,nr,c;
int main()
{
    cin>>n>>c;
    for(int i=1;i<=n;++i)
    {
        a=b;
        cin>>b;
        if(b-a<=c)nr++;
        else nr=1;
    }
    cout<<nr;
    return 0;
}
