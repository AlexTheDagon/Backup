#include <iostream>
#define modulo 1000000007
using namespace std;
string s;
long long st[200005],dr[200005];
int main()
{
    cin>>s;
    for(int i=1;i<=s.size();++i)
    {
        st[i]=st[i-1];
        if(s[i-1]=='(')++st[i];
    }
    for(int i=s.size();i>0;--i)
    {
        st[i]=st[i+1];
        if(s[i-1]=='(')++st[i];
    }
    for(int i=1;i<=s.size();++i)
    {
        if(st[i]>1)
        {
            if(st[i]!=st[i-1])st[i]=st[i-1]*st[i];
            else st[i]=st[i-1];
        }
        st[i]=st[i]%modulo;
    }
    for(int i=s.size();i>0;--i)
    {
        if(st[i]>1)
        {
            if(st[i]!=st[i+1])st[i]=st[i+1]*st[i];
            else st[i]=st[i+1];
        }
        st[i]=st[i]%modulo;
    }
    for(int i=1;i<)
    return 0;
}
