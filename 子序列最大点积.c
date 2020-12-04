/*求解两个给定序列的最大点积*/

#include "general_fun.h"

#define N1 2
#define N2 2
int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size);
int main()
{
	int nums1[N1] = { -1,-1 };
	int nums2[N2] = { 1,1 };
	printf("%d", maxDotProduct(nums1, N1, nums2, N2));
}


int maxDotProduct(const int* nums1, int nums1Size, const int* nums2, int nums2Size)
{
	int dp[500][500];
	//dp[0][0] = nums1[0] * nums2[0];
	for (int i = 1; i <= nums1Size; i++)
	{
		for (int j = 1; j <=nums2Size; j++)
		{
			dp[i][j] = nums1[i-1] * nums2[j-1];
			dp[i][j] = Max(dp[i][j], dp[i - 1][j - 1] + nums1[i-1] * nums2[j-1]);
			dp[i][j] = Max(dp[i][j], dp[i - 1][j]);
			dp[i][j] = Max(dp[i][j], dp[i][j - 1]);
			dp[i][j] = Max(dp[i][j], dp[i - 1][j - 1]);

		}
	}
	return dp[nums1Size][nums2Size];
}
