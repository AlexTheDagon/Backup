#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define x first
#define y second
using namespace std;
vector<string> v[200];
string s[105];
pair<int,string> srt[200];
int n,sem,poz,ind;
void rec(int poz)
{
    if(poz==s[ind].size())sem=1;
    if(sem)return;
    int semm=0;
    for(auto i:v[s[ind][poz]])
    {
        semm=1;
        for(int j=0;j<i.size();++j)
        {
            if(s[ind][poz+j]!=i[j])semm=0;
        }
        if(semm && i!=s[ind])rec(poz+i.size());
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        srt[i]=make_pair(s[i].size(),s[i]);
        v[s[i][0]].pb(s[i]);
    }
    sort(srt+1,srt+n+1);
    for(int i=1;i<=n;++i)s[i]=srt[i].y;
    for(int i=n;i>0 && sem==0;--i)
    {
        ind=i;
        rec(0);
    }
    if(sem==0)cout<<"-1";
    else cout<<s[ind];
    return 0;
}
