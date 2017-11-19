#include <iostream>
#define NM 200005
using namespace std;
string s,t;
int a[2][NM],s0,s1;
long long sum;
int main()
{
    cin>>s>>t;
    a[t[0]-'0'][1]=1;
    for(int i=1;i<t.size();++i)
    {
        a[1][i+1]=a[1][i];
        a[0][i+1]=a[0][i];
        ++a[t[i]-'0'][i+1];
    }
    for(int i=0;i<s.size();++i)
    {
        sum=sum+(a['1'-s[i]][t.size()-s.size()+1+i]-a['1'-s[i]][i]);
    }
    cout<<sum;
    return 0;
}
