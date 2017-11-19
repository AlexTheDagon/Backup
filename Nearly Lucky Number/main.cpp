#include <iostream>

using namespace std;
long long n,sem=1,cif;
int main()
{
    cin>>n;
    while(n)
    {
        if(n%10==4 || n%10==7)++cif;
        n=n/10;
    }
    if(cif!=4 && cif!=7)sem=0;
    if(sem==0)cout<<"NO";
    else cout<<"YES";
    return 0;
}
