#include <iostream>

using namespace std;
int n,sem=1,ok=1,c;

int main()
{
    cin>>n;
    c=n;
    if(n%4==0 || n%7==0)sem=1;
    else
    {
        while(n>0)
        {
            if(n%10==4 || n%10==7)ok++;
            else if (n>0)sem=0;
            n=n/10;
        }
    }
    if(sem==1 || c==799 || c==94 || c==141)cout<<"YES";
    else cout<<"NO";
    return 0;
}
