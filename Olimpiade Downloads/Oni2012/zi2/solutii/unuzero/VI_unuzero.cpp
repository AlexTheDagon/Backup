#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 1000010
#define mod 666013

int N, A, B;
int s[maxn], n[maxn];

int main() {
	FILE *f1=fopen("unuzero.in", "r"), *f2=fopen("unuzero.out", "w");
	int i, p;
	
	fscanf(f1, "%d %d %d\n", &N, &A, &B);
	N ++;
	
	n[0] = s[0] = 1;
	for(i=1; i<=N; i++) {
		n[i] = n[i-1];
		// negru pe pozitia i
		// (i-1, i-2, ..., i-A, i-A-1, ..., i-B
		if(i-A-1 >= 0) {
			if(i-B-2 >= 0) {
				n[i] += (s[i-A-1] - s[i-B-2] + mod) % mod;
			}
			else {
				n[i] += (s[i-A-1]) % mod;
			}
			
			n[i] %= mod;
		}
		
		s[i] = (s[i-1] + n[i]) % mod;
	}
	
	fprintf(f2, "%d\n", (mod + n[N] - 1) % mod);
	
	fclose(f1); fclose(f2);
	return 0;
}
	
	