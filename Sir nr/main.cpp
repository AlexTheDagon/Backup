#include <iostream>
#include <fstream>

using namespace std;

int main()
{int a[10000],A,B,q,N,S[10000];
ifstream in("date.in");
in>>N;
ofstream out("date.out");
for(int i=0;i<N;i++)
{
    in>>a[i];
    S[i]=a[i];
}
for(int i=1;i<N;i++)
{
    S[i]=S[i-1]+S[i];
    out<<S[i]<<" ";
}
in>>q;
out<<endl;
while(q>0)
{
    in>>A>>B;
    out<<S[B]<<" "<<S[A-1]<<endl;
    out<<S[B]-S[A-1]<<endl;
    q--;

}

    return 0;
}
