#include <iostream>

using namespace std;
int n;
void afis(int i)
{
    if(i>0)
    {
        for(int j=1;j<=i;++j)cout<<j<<" ";
        cout<<'\n';
        afis(i-1);
    }
}
int main()
{
    cin>>n;
    afis(n);
    return 0;
}
