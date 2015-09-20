#include<stdio.h>

#define MAXN(a,b)((a)>(b)?(a):(b))

int N,M;
int W[3500],D[3500];
int dp[14000];

int main()
{
	int i;
	int j;
	scanf("%d %d",&N,&M);
	for(i = 0;i < N;i++)
		scanf("%d %d",W+i,D+i);
	for(i = 0;i < 14000;i++)
		dp[i] = 0;
	for(j = 0;j < N;j++)
		for(i = M;i > 0;i--)
			if(W[j] <= i)
				dp[i] = MAXN((dp[i-W[j]]+D[j]),dp[i]);
	printf("%d\n",dp[M]);
}
