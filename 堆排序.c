#include "heap_subfun.h"

#define NUM 100

int	PARENT(int i)
{
	return i / 2;
}

int	LEFT(int i)
{
	return 2 * i;
}

int	RIGHT(int i)
{
	return 2 * i+1;
}


/*下列函数的作用是将数组a[]右移一位，并使a[0]=0;*/
int *remake_array(int a[],int lengtg)
{
	int *b;
	int i = 0;
	b = (int *)malloc(NUM * sizeof(int));
	b[0] = i;
	while (i< lengtg)
	{
		b[i + 1] = a[i];
		i++;
	}
	return b;
}
/*下列函数对指定位置的根结点经行升(降)排序，衍生置叶结点(最底层)*/
void MAX_HEAPIFY(int *a, int i,int length)
{
	int l, r, largest;
	l = LEFT(i);
	r = RIGHT(i);
	if (l < length && a[l] > a[i])//此处小于则表示大->小排序，>则相反
		largest = l;
	else
		largest = i;
	if (r < length && a[r] > a[largest])
		largest = r;
	if (largest != i)
	{
		exchange(a, i, largest);
		MAX_HEAPIFY(a, largest, length);//一次调用则将指定根结点降一层，递归调用直至叶结点
	}
}
/*下列函数构建一个数组的最大(小)堆->父节点数值必然大于(小于)子节点数值*/
void BUILD_MAX_HEAP(int *a,int size)
{
	int heap_size = size;
	for(int i=heap_size/2;i>0;i--)//大于size/2的部分均为叶结点无需操作
		MAX_HEAPIFY(a, i, size);
}
//堆排序最终函数，传入一个数组与相应的长度
int * HEAP_SORT(int *a, int size)
{	
	int *b;
	b = remake_array(a, size);
	size += 1;
	/*上部分是为了贴合算法，将数组a[0]置0，并使总长度加1，方便算法运算*/
	int heap_size = size;
	BUILD_MAX_HEAP(b, size);
	for (int i = size-1; i > 1; i--)
	{
		exchange(b, 1, i);//根据最值必然出现在源结点，将其放置到数组最后一位
		heap_size -= 1;
		MAX_HEAPIFY(b, 1, heap_size);//将堆长减1，不干扰已放置的末尾最值数组
	}
	return b;
}
//下列函数得到数组中的最大值
int MAXIMUM(int *a,int size)
{
	int *b;
	b = remake_array(a, size);
	size += 1;
	BUILD_MAX_HEAP(b, size);
	return b[1];
}



