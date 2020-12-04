#include "general_fun.h"
//计算数组长度,限制：传入a数组必须已指明长度
int len(int a[])
{  
    int i=0;
    while(*(a+i)!='\0')
        i++;
    return i;
}
//比较得到最大值
int Max(int a,int b)
{
    return a>b?a:b;
}
//比较得到最小值
int Min(int a,int b)
{
    return a<b?a:b;
}
//交换数组两个元素,交换a[i]与a[j]
void VOIDexchange(int a[],int i,int j)
{
    int temp=a[i];
    a[i]=a[j];a[j]=temp;
}

int *INTexchange(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j]; a[j] = temp;
	return a;
}
// 生成随机数组，size=长度，range=范围，flag=1显示,ifneg=1表示数组需要负数
int *rand_array(int size, int range, int flag,int ifnegt)
{
	int aa, i;
	static int *a;
	a = (int *)malloc(size * sizeof(int));
	int count = 0;

	// 按时间重新播种
	srand((unsigned)time(NULL));

	for (i = 0; i < size; i++)
	{
		aa = rand() % range + 1 - ifnegt*range / 2;
		if((a + i)!=NULL)
			*(a + i) = aa;
	}
	if (flag == 1)
		for (i = 0; i < size; i++)
		{
			printf("%d ", a[i]);
			count++;
			if (count == 30)
			{
				printf("\n");
				count = 0;
			}

		}
	return a;
}

/*测试某元素是否在数组中，测试对象为int*/
int element_ifin_array(int element, int a[], int length)
{
	for (int i = 0; i < length; i++)
	{
		if (element == a[i])
			return 1;
	}				
	return 0;
}

int *find_min_element(int* nums, int numsSize)
{	
	 static int  a[2];
	a[0]=INT_MAX;/*a[0]存储最小值*/
	a[1] = 0;/*a[0]存储最小值的坐标*/
	
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] < a[0])
		{
			a[0] = nums[i];
			a[1] = i;
		}
	}
	return a;
}




