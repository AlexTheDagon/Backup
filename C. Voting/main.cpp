#include <iostream>
#include <queue>
using namespace std;
int n;
string s;
queue <int> q[2];
int main()
{
    cin>>n;
    cin>>s;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='D')q[0].push(i+1);
        else q[1].push(i+1);
    }
    while(!q[1].empty() && !q[0].empty())
    {
        if(q[1].front()<q[0].front())
        {
            q[0].pop();
            q[1].push(q[1].front()+n);
            q[1].pop();
        }
        else
        {
            q[1].pop();
            q[0].push(q[0].front()+n);
            q[0].pop();
        }
    }
    if(!q[1].empty())cout<<"R";
    else cout<<"D";
    return 0;
}
