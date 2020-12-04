#include "fib.h"
/*以下函数是斐波那契数列的简单递归实现，时间复杂度为O(2^n)*/
int fib(int N)
{
	if (N == 1 || N == 2)return 1;
	return fib(N - 1) + fib(N - 2);
}
/*以下两个函数是动态规划的自上到下的实现，注意每个备忘录的记录*/
/*时间复杂度为O(n)*/
int fib_vision_1(int N) 
{
    int  *memo;
    memo =(int *) malloc(N * sizeof(int));
    for (int i = 0; i <= N; i++)
    {
        memo[i] = 0;
    }
    return helper(memo, N);/*由于需要递归helper，所以需要单独写成一个函数*/
}

int helper(int  *memo, int n) 
{
    // base case
    if (n == 1 || n == 2) return 1;
    // 已经计算过
    if (memo[n] != 0) return memo[n];/*已计算过的值则不需要在计算*/
    memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
    return memo[n];
}
/*以下函数是动态规划的自底向上的实现，注意每个备忘录的记录*/
int fib_vision_2(int N)
{
    int *memo;
    memo = (int*)malloc(N * sizeof(int));
    for (int i = 0; i <= N; i++)
    {
        memo[i] = 0;
    }
    memo[1] = 1;
    memo[2] = 1;
    if (N == 1 || N == 2) return 1;
    for (int i = 3; i <= N; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[N];
}
/*进阶版，将空间压缩置O(1)*/
int fib_vision_3(int N)
{
    int sum, prev, curr;
    prev = 1;
    curr = 1;
    if (N == 1 || N == 2) return 1;
    for (int i = 3; i <= N; i++)
    {
        sum = prev + curr;
        prev = curr;
        curr = sum;
    }
    return sum;
}

