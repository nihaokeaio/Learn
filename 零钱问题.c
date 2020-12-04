#include "Collect_change.h"
#include "general_fun.h"

int CCGE_origin(int coins[], int count, int length)
{
	int n = INT_MAX;
;
	return dp_org(n, coins, count,length);
}

int dp_org(int n, int coins[], int count, int length)
{
	if (element_ifin_array(count, coins, length))
		return 1;


	for (int i = 0; i < length && (count - coins[i])>0; i++)
	{
		n = Min(n, (dp_org(n, coins,count-coins[i],length) + 1));
	}
	if (n == INT_MAX)
	{
		printf("解为空集！");
		n = -1;
	}
	return n;
}


int CCGE_vision_1(int coins[], int count, int length)
{
	int n = INT_MAX;
	int *memo;
	memo = (int *)malloc(count * sizeof(int));
	for (int i = 0; i <=count && memo!=NULL; i++)
		memo[i] = 0;
	return dp(n, coins, count, length, memo);
}

int dp(int n, int coins[], int count, int length, int* memo)
{
	if (element_ifin_array(count, coins, length))
		return 1;

	if (memo[count] != 0)
		return memo[count];
	
		for (int i = 0; i < length && (count - coins[i])>0; i++)
		{
			memo[count - coins[i]] = dp(n, coins, count - coins[i], length, memo)+1;
			n = Min(n, memo[count - coins[i]]);
		}
	if (n == INT_MAX)
		{
			printf("解为空集！");
			n = -1;
		}
	return n;
}
/*自底向上的数组写法*/
int CCGE_vision_2(int coins[], int count, int length)
{
	int n = INT_MAX;
	if (element_ifin_array(count, coins, length))
		return 1;
	int *memo;
	memo = (int*)malloc(count * sizeof(int));
	for (int i = 0; i <= count && memo != NULL; i++)
		memo[i] = count;
	for (int i = 0; i < length; i++)
		memo[coins[i]] = 1;
	for (int i = 0; i <= count; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if ((i - coins[j]) <= 0) continue;
			memo[i] = Min(memo[i], memo[i - coins[j]] + 1);
		}
	}
	if (memo[count] == INT_MAX)
	{
		printf("解为空集！");
		n = -1;
	}
	return memo[count];
}

/*

首先，分析题目，得到状态方程，此步也较为困难
往往可以根据暴力求解法得到状态方程
通过添加备忘字典可以实现算法的时长优化，自顶向下的写法往往比较晦涩，一般采用自底向上的数组法
将递归函数法转为数组的写法，算是比较高阶的写法，有一定的困难

考虑自底向上的写法，注意相邻项的表达式一定与前面给出的状态方程有关
自底向上，往往是知道A[1],根据状态方程可求得A[2],在根据状态方程可以得到递推式A[3]最终的解；
状态方程要考虑全面，特别是针对n=0,n=1,n<0等往往存在直接解（或是初值）

*/
