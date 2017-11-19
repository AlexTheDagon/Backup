#include <iostream>

using namespace std;
int n;
int main()
{
    cin>>n;
    if(n<=3)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    if(n%2==0)
    {
        cout<<"2 * 3 = 6"<<endl;
        cout<<"6 * 4 = 24"<<endl;
        cout<<"1 * 24 = 24"<<endl;
        for(int i=5;i<n;i+=2)
        {
            cout<<i+1<<" - "<<i<<" = "<<1<<endl;
            cout<<"1 * 24 = 24"<<endl;
        }
    }
    else
    {
        cout<<"2 - 1 = 1"<<endl;
        cout<<"1 + 3 = 4"<<endl;
        cout<<"4 * 5 = 20"<<endl;
        cout<<"20 + 4 = 24"<<endl;
        for(int i=6;i<n;i+=2)
        {
            cout<<i+1<<" - "<<i<<" = "<<1<<endl;
            cout<<"1 * 24 = 24"<<endl;
        }
    }
    return 0;
}
