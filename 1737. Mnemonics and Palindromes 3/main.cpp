#include <iostream>

using namespace std;
int n;
void gen(string s)
{
    for(int i=1;i<=n/3;++i)cout<<s;
    for(int i=1;i<=n%3;++i)cout<<s[i-1];
    cout<<'\n';
}
int main()
{
    cin>>n;
    if(n==1)cout<<"a"<<'\n'<<"b"<<'\n'<<"c";
    else
    {
        if(n==2)cout<<"ab"<<'\n'<<"ac"<<'\n'<<"ba"<<'\n'<<"bc"<<'\n'<<"ca"<<'\n'<<"cb";
        else
        {
            if(n*6>100000)cout<<"TOO LONG";
            else
            {
                gen("abc");
                gen("acb");
                gen("bac");
                gen("bca");
                gen("cab");
                gen("cba");
            }
        }
    }
    return 0;
}
/**
5*49*92
5*




**/
