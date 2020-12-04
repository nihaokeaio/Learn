/*给定部分长度的钢条价值，求解给定长度钢条的最大价值*/
#include "general_fun.h"
#define N 10
#define W 45
int KANPSACK_0_1(int* values, int* weights, int n, int Weight);
int cut_rod(int* nums, int numsSizes);
int main()
{
	int values[N] = { 1,5,8,9,10,17,17,20,24,30 };
	int weights[N] = { 1,5,8,9,10,17,17,20,24,30 };
	printf("%d", KANPSACK_0_1(values,weights,N,W));
}

int cut_rod(int* nums, int numsSizes)
{
	int dp[N+1];
	for (int i = 0; i <= numsSizes; i++)
	{
		dp[i] = 0;
	}
	for (int i = 1; i <= numsSizes; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = Max(dp[i], dp[i - j] + nums[j - 1]);
		}
		printf("dp[%d]:%d\n", i, dp[i]);
	}
	return dp[numsSizes];
}
/*0-1背包问题，给定n个物品，给定其价值和重量，求解最大承重Weight条件下的最大收益*/
int KANPSACK_0_1(int* values, int* weights, int n, int Weight)
{
	int dp[20][100];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= Weight; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= Weight; j++)
		{
			if (j < weights[i-1])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - weights[i-1]] + values[i-1]);
			
		}
		printf("dp[%d][%d]=%d\n", i, Weight, dp[i][Weight]);
	}
	//return dp[n][W];
  }
