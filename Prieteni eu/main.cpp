#pragma option -O2
#include <fstream>
using namespace std;
ifstream fin("prieteni.in");
ofstream fout("prieteni.out");
int n,pas,timp;
int a[1024],b[3][4096];
int etc(int i,int j)
{
	int i0=0,j0=-1,aux;
	while(i!=j)
	{
		if(a[i]>a[j])
		{
			aux=a[i];
			a[i]=a[j];
			a[j]=aux;
			aux=-i0;
			i0=-j0;
			j0=aux;
		}
		i+=i0;
		j+=j0;
	}
	return i;
}
void qsort(int li,int ls)
{
	if(li<ls)
	{
		int k=etc(li,ls);
		qsort(li,k-1);
		qsort(k+1,ls);
	}
}
void cit()
{
	int i;
	fin>>n;
	for(i=1;i<=n;i++)
		fin>>a[i];
}
void rez()
{
	int i,j,min1,min2,t;
	j=1;
	i=1;
	pas=0;
	timp=0;
	min1=a[j];
	min2=a[j+1];
	while(i<=n)
	{
		pas++;
		b[0][pas]=min1;
		t=min1;
		i++;
		b[1][pas]=-1;
		if(i<n)
		{
			b[1][pas]=min2;
			t=min2;
			b[2][pas]=-1;
			i++;
		}
		timp+=t;
		if(i==n)
		{
			pas++;
			b[0][pas]=min1;
			b[1][pas]=-1;
			timp+=min1;
			pas++;
			b[0][pas]=min1;
			b[1][pas]=a[i];
			b[2][pas]=-1;
			timp+=a[i];
			i++;
		}
		else
		{
			pas++;
			b[0][pas]=min1;
			timp+=min1;
			b[1][pas]=-1;
			min2=a[i];
			i--;
		}
	}
}
void scr()
{
	int i,j;
	for(i=1;i<=pas;i++)
	{
		j=0;
		while(b[j][i]!=-1)
		{
			fout<<b[j][i]<<" ";
			j++;
		}
		fout<<endl;
	}
	fout<<timp;
}
int main()
{
	cit();
	qsort(1,n);
	rez();
	scr();
	fout.close();
	return 0;
}
