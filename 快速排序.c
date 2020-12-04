#include "quick_sort.h"

int PARTITION(int *a, int p, int r)
{
	int x = a[r];
	int i = p - 1;
	for(int j=p;j<r;j++)
		if (a[j] <= x)//>表示递减排序，<表示递增排序
		{
			i += 1;
			exchange(a, i, j);
		}
	exchange(a, i + 1, r);//交换数组a中i+1 and r 元素
	return i + 1;
}

int QUICKSORT(int *a, int p, int r)
{
	
	int q = PARTITION(a, p, r);
	if (q == r||q==p)
		return 0;
	QUICKSORT(a, p, q-1);
	QUICKSORT(a, q, r);

	return 0;
}
