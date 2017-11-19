#include <iostream>

using namespace std;
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        if(i%2==0)cout<<"I love ";
        else cout<<"I hate ";
        if(i+1<=n)cout<<"that ";
    }
    cout<<"it";
    return 0;
}
