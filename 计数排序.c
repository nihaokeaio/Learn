#include "general_fun.h"
#include "heap_subfun.h"

int *COUNTINT_SORT(int a[], int size)//size=>数组a的长度
{
	int k=MAXIMUM(a, size)+1;//求得数组a中的最大值，并加一赋给k
	int *c;
	int *b;
	c = (int *)malloc(k * sizeof(int));
	b = (int *)malloc(size * sizeof(int));
	for (int i = 0; i < k; i++)
		c[i] = 0;
	for (int j = 0; j < size; j++)
	{
		c[a[j]] = c[a[j]] + 1;
		//printf("%d ", c[j]);
	}
	
	for (int i = 1; i < k; i++)
	{
		//printf("%d ", c[i]);
		c[i] = c[i] + c[i - 1];
		//printf("%d ", c[i]);
	}
	for (int j = 0; j <=size-1 ; j++)
	{
		b[c[a[j]]-1] = a[j];
		c[a[j]]= c[a[j]]-1;
		/*for (int i = 0; i < k; i++)
		{
			printf("%d ", c[i]);
		}
		printf("\n");*/
	}
	return b;
}
int main()
{
	int A[] = { 2,5,3,0,2,3,0,3 };
	//int N = 100;
	//int *A=rand_array(N, N, 1,0);
	//VOIDexchange(A, 1, 2);
	int *b;
	int size =( sizeof(A) / sizeof(A[0]));
	//int size = N;
	printf("\n");
	b=COUNTINT_SORT(A,size);
	for (int i = 0; i <size; i++)
		printf("%d ", b[i]);
}
