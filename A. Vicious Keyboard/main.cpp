#include <iostream>

using namespace std;
string s;
int t,tm;
int main()
{
    cin>>s;
    for(int j=0;j<s.size()-1;++j)if(s[j]=='V' && s[j+1]=='K')++t;
    tm=max(tm,t);
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='V')s[i]='K';
        else s[i]='V';
        t=0;
        for(int j=0;j<s.size()-1;++j)if(s[j]=='V' && s[j+1]=='K')++t;
        if(s[i]=='V')s[i]='K';
        else s[i]='V';
        tm=max(tm,t);
    }
    cout<<tm;
    return 0;
}
