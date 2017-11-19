// brute force - 25 puncte
#include <fstream>

using namespace std;

typedef unsigned short cifra;


ifstream f("7segmente.in");
ofstream g("7segmente.out");
cifra v[20],p=0;
// cifra d[10]={6,2,5,5,4,5,6,3,7,6};
unsigned long long n=0,m=0,dmin=0,xmin=0,x,k,j=0;




int main()
{

cifra pc=0,i=0,aux=0,nc=0;

f>>n>>p;
m=n;

v[0]=0;i=0;
while (m>0)
{
	v[++i]=m%10;
	switch (m%10)
	{
	case 0 : pc=pc+6;break;
	case 1 : pc=pc+2;break;
	case 2 : pc=pc+5;break;
	case 3 : pc=pc+5;break;
	case 4 : pc=pc+4;break;
	case 5 : pc=pc+5;break;
	case 6 : pc=pc+6;break;
	case 7 : pc=pc+3;break;
	case 8 : pc=pc+7;break;
	case 9 : pc=pc+6;break;
	}
	m=m/10;
}
v[0]=i;
g<<pc<<"\n";


// calculez numarul de cifre maxim pe care-l poate avea numarul cautat
nc=p/2;
if (nc>=v[0]) nc=v[0];


k=1;
for(j=1;j<=nc-1;j++) 
	   k=k*10;

dmin=n;
for(j=k;j<=n;j++)
{
	x=j;pc=0;
	while (x>0)
	{
	switch (x%10)
		{
		case 0 : pc=pc+6;break;
		case 1 : pc=pc+2;break;
		case 2 : pc=pc+5;break;
		case 3 : pc=pc+5;break;
		case 4 : pc=pc+4;break;
		case 5 : pc=pc+5;break;
		case 6 : pc=pc+6;break;
		case 7 : pc=pc+3;break;
		case 8 : pc=pc+7;break;
		case 9 : pc=pc+6;break;
		}
	x=x/10;
	}
	if (pc<=p)
		if (n-j<=dmin) {xmin=j;dmin=n-j;}
}	


g<<xmin;

f.close();
g.close();
return 0;
}

