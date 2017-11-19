#include <iostream>

using namespace std;
int n;
void afisare(int i)
{
    if(i<=n)
    {
        afisare(i+1);
        for(int j=1;j<=i;++j)cout<<j<<" ";
        cout<<'\n';
    }
}
int main()
{
    cin>>n;
    afisare(1);
    return 0;
}
