#include <iostream>
#include <math.h>

int x[100],n,nrsol;

void scriesol ()
{ int i,j;
nrsol++;
for(i=1;i<=n;i++)
{ cout<<endl;
for(j=1;j<=n;j++)
if (x[j]==i) cout<<"X ";
else cout<<"O ";
}
}

int potcont(int k)
{ int  i;
for(i=1;i<=k-1;i++)
if (x[i]==x[k] || k-i==abs(x[k]-x[i])) return 0;
return 1;
}

void back(int k)
{
int i;
for(i=1;i<=n;i++)
{
x[k]=i;
if (potcont(k))
if (k==n) scriesol();
else back(k+1);
}
}

void main()
{
cin>>n;
nrsol=0;
back(1);
cout<<nrsol<<" solutii";
}
