#include<stdio.h>

#define MINN(a,b)((a)<(b)?(a):(b))
#define BOUND 25000007

int T,E,F,N;
int W[507],V[507];
int dp[10007];

int main()
{	
	int i;
	int j;
	int C = 0;
	T = 0;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&E,&F);
		C = F - E;
		scanf("%d",&N);
		for(i = 0;i < N;i++)
			scanf("%d %d",V+i,W+i);	
		for(i = 0;i < 10007;i++)
			dp[i] = BOUND;			
		dp[0] = 0;

		for(j = 0;j < N;j++)
			for(i = 0;i <= C;i++)
				if(W[j] <= i)
				{
					//printf("%d %d %d\n",i,dp[i],dp[i-W[j]]+V[j]);
					dp[i] = MINN((dp[i-W[j]]+V[j]),dp[i]);
				}
		if( dp[C] == BOUND)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[C]);
	}
}
