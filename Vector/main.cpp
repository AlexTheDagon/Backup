#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
int main()
{
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.insert(v.begin()+2,8);
    for(int i=0;i<v.size();++i)cout<<v[i]<<" ";
    return 0;
}
