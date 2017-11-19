#include <iostream>

using namespace std;

int main()
{
    int n,x=0,im=-1;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>n;
        if (n>im)
        {
            im=n;
            x=0;
        }
        if (n==im)
            x++;
    }
    cout<<x;
    return 0;
}
