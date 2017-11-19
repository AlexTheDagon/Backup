#include <iostream>
#include <stack>
using namespace std;
stack <int> s1,s2;
void print(stack <int> x);
int main()
{
    s1.push(2);
    s1.push(1);
    print(s1);
    cout<<endl<<s1.top();
    return 0;
}
void print(stack <int> x)
{
    stack <int> aux;
    while(!x.empty())
    {
        aux.push(x.top());
        x.pop();
    }
    while(!aux.empty())
    {
        cout<<aux.top()<<'\n';
        aux.pop();
    }
}
