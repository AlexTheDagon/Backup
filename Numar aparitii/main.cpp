#include <iostream>
#include <map>
using namespace std;
int n,x;
int main()
{cin>>n;
map<int,int> m;
for(int i=1;i<=n;i++)
{
    cin>>x;
    m[x]++;
}
for(map<int,int>::iterator it=m.begin();it!=m.end();++it)
{
    cout<<it->first<<"-->"<<it->second<<endl;
}

    return 0;
}
