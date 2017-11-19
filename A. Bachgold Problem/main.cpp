#include <iostream>

using namespace std;
int nr2,nr,sem;
int main()
{
    cin>>nr;
    nr2=nr/2;
    cout<<nr2<<'\n';
    if(nr%2==1)
    {
        nr2--;
        cout<<"3 ";
    }
    for(int i=1;i<=nr2;++i)cout<<"2 ";
    return 0;
}
