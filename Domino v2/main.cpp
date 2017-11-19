#include <iostream>
#include <fstream>
#include <stack>
#define x first
#define y second
using namespace std;
ifstream in("domino1.in");
ofstream out("domino1.out");
stack <pair<int,int> > s,aux;
stack <int> r;
int n,elim,rotiri,ultr=100000,sem,srot;
pair <int,int> p,ur;
int cmp(pair<int,int> i,pair <int,int> j)
{
    if(i.x<j.x || (i.x==j.x && i.y<j.y))return 1;
    return 0;
}///bine
int cmprot(pair<int,int> i,pair <int,int> j)
{
    if(i.x<j.y || (i.x==j.y && i.y<j.x))return 1;
    return 0;
}///bine
int main()
{
    in>>n>>rotiri>>elim;
    for(int i=1;i<=n;++i)
    {
        in>>p.x>>p.y;
        srot=0;
        if(cmprot(p,p) && (rotiri>0 || (ultr<=elim && cmprot(ur,p))))
        {
            swap(p.x,p.y);
            srot=1;
            ultr=0;
            --rotiri;
            ur=p;
        }
        if(s.empty())
        {
            s.push(p);
            r.push(srot);
            if(srot==0)++ultr;
        }
        else
        {
            while(!s.empty() && elim>0 && cmp(s.top(),p))
            {
                s.pop();
                rotiri+=r.top();
                r.pop();
                --elim;
                --ultr;
                if(ultr<0)ultr=1000000;
            }
            s.push(p);
            r.push(srot);
            if(srot==0)++ultr;
        }
    }


    ///de aici ii bine
    while(elim>0)
    {
        s.pop();
        --elim;
    }///bine
    while(!s.empty())
    {
        aux.push(s.top());
        s.pop();
    }
    while(!aux.empty())
    {
        out<<aux.top().x<<aux.top().y;
        aux.pop();
    }
    return 0;
}
