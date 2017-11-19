//sursa 100 p - Robert Hasna

#include <cstdio>

using namespace std;

static const int NMAX = 20;

int N, P;
int x[] = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
int v[NMAX];

int cer1;
int rez[NMAX], nrCifre;

int main(int argc, char **argv) {
	freopen("7segmente.in", "r", stdin);
	freopen("7segmente.out", "w", stdout);

	char c = '1';
	while (1) {
		scanf("%c", &c);
		if (c == ' ')
			break;
		v[N++] = c - '0';
	}
	scanf("%d", &P);

	//cerinta 1
	for (int i = 0; i < N; cer1 += x[v[i++]]);
	printf("%d ", cer1);

	//cerinta 2
	nrCifre = (P / 2) < N ? (P / 2) : N;

	if (nrCifre < N) {
		printf("%c", P & 1 ? '7' : '1');
		for (int i = 0; i < nrCifre - 1; printf("1"), ++i)
			;
		return 0;
	}

	P -= N << 1;
	bool miss = false;
	int i;
	for (i = 0; i < N; ++i) {
		P += 2;
		int j = miss ? 9 : v[i];
		while (x[j] > P)
			--j;

		rez[i] = j;
		P -= x[j];

		if (rez[i] != v[i])
			miss = true;
	}

	for (int i = 0; i < N; ++i)
		printf("%d", rez[i]);
	printf("\n");

	return 0;
}
