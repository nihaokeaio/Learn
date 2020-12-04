#include <stdio.h>
#include "general_fun.h"

int main()
{
	//int nums[8] = { 10, 9, 2, 5, 3, 7, 101, 18 };
	//int nums[6] = { 0,1,0,3,2,3 };
	//int nums[3] = { 1,0,0 };
	//int arr[9] = { 9, 4, 2, 10, 7, 8, 8, 1, 9 };
	//int nums[9] = { 1, 3, 6, 7, 9, 4, 10, 5, 6 };
	int nums[1] = { 100 };
	int numsSize = 9;
	printf("max=%d", maxTurbulenceSize(nums, 1));
}

int lengthOfLIS(int* nums, int numsSize) 
{
	int *dp;
	int n = 1;
	dp = (int*)malloc(numsSize * sizeof(int));
	for (int i = 0; i < numsSize; i++)
	{
		dp[i] = 1;
	}
	for (int i = 1; i < numsSize; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j])
			{
				dp[i] = Max(dp[i], 1 + dp[j]);
			}
		}
		n = Max(n, dp[i]);
	}
	return n;
}


int maxTurbulenceSize(int* arr, int arrSize)
{
	int* dp;
	int n = 1;
	dp = (int*)malloc(arrSize * sizeof(int));
	for (int i = 0; i < arrSize; i++)
	{
		dp[i] = 1;
	}
	if (arrSize > 1)
	{
		if (arr[0] != arr[1])
		{
			dp[1] = 2;
		}
		if (arrSize >  2)
		{
			for (int i = 2; i < arrSize; i++)
			{
				if (arr[i - 1] > arr[i])
				{
					dp[i] += 1;
					if (arr[i - 2] < arr[i - 1])
						dp[i] = dp[i - 1] + 1;
				}
				if (arr[i - 1] < arr[i])
				{
					dp[i] += 1;
					if (arr[i - 2] > arr[i - 1])
						dp[i] = dp[i - 1] + 1;
				}
				n = (n > dp[i]) ? n : dp[i];
			}
		}
		n = (n > dp[1]) ? n : dp[1];
	}
	
	return n;
}
