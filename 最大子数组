//建立关于最大数组的函数
#include "biggst_array.h"
#include <windows.h>
#define N 10000
#define test 0
#define fun rand_array(N,N,0)

int *rand_array(int size,int range,int flag);
// 生成随机数组，size=长度，range=范围，flag=1显示
int *find_max_subarray(int A[],int low,int mid,int high);
//计算数组的一组最大子数组
int *find_maxmum_subarray(int A[],int low,int high);
//分治法获得最大子数组
int *force_find_maxmum_subarray(int A[],int n);
int *line_find_maxmum_subarray(int A[],int n);
int main()
{
    clock_t start,finish,finish1;
    double total_time;
    start=clock();
    int b[10]={-1  , 1 ,   0   , -2  , 3   , -4  , 2  ,  2   , -4  , 6};
    int *a,*c;//获取最大子数组的上下标与和
    //a=find_max_subarray(rand_array(10,10,1),0,4,9);
    a=find_maxmum_subarray(fun,0,N-1);
    printf("%d %d %d \n",a[0],a[1],a[2]);
    finish=clock();
    total_time=(double)(finish-start)/CLOCKS_PER_SEC*100000.0;
    printf("%f\n",total_time);
    
    a=line_find_maxmum_subarray(fun,N);
    printf("%d %d %d \n",a[0],a[1],a[2]);
    finish1=clock();
    total_time=(double)(finish1-finish)/CLOCKS_PER_SEC*100000.0;
    printf("%f\n",total_time);
    if(test)
    {
        int k=0;
        int x=1000;
        while(x--)
        {
                a=find_maxmum_subarray(fun,0,N-1);
            Sleep(50);
            c=line_find_maxmum_subarray(fun,N);
            if(c[0]>c[1])
            k++;
        }
        printf("k=%d",k);
    }
	return 0;
}

int *rand_array(int size,int range,int flag)
{
    int aa,i;
    static int *a;
    a=(int *)malloc(size*sizeof(int));
	int count = 0;

	// 按时间重新播种
	srand((unsigned)time(NULL));

	for (i = 0; i < size; i++)
	{
		aa = rand() % range+1-range/2;
		*(a+i) = aa;
	}
    if(flag==1)
	for (i = 0; i < size; i++)
	{
		printf("%-5d", a[i]);
		count++;
		if (count == 10)
		{
			printf("\n");
			count = 0;
		}
			
	}
    return a;
}

int *find_max_subarray(int A[],int low,int mid,int high)
{
    int left_sum=INT_MIN;
    int right_sum=INT_MIN;
    int max_left,max_right,sum=0;
    int *a;
    a=(int *)malloc(3*sizeof(int));//a[0]=max_left;a[1]=max_right;a[2]=left_sum+right_sum
    sum=0;
    for(int i=mid;i>=low;i--)
    {
        sum=sum+A[i];
        if(sum>left_sum)
            {
                left_sum=sum;
                max_left=i;
            }
    }
    sum=0;
    for(int j=mid+1;j<=high;j++)
    {
        sum=sum+A[j];
        if(sum>right_sum)
            {
                right_sum=sum;
                max_right=j;
            }
    }
    a[0]=max_left;
    a[1]=max_right;
    a[2]=left_sum+right_sum;
    //printf("low=%d,mid=%d,high=%d,left_sum=%d,right_sum=%d,a[2]=%d\n",low,mid,high,left_sum,right_sum,a[2]);
    return a;
}

int *find_maxmum_subarray(int A[],int low,int high)
{
    int *a;
    int mid;
    int *left,*right,*cross;
    a=(int *)malloc(3*sizeof(int));
    left=(int *)malloc(3*sizeof(int));
    right=(int *)malloc(3*sizeof(int));
    cross=(int *)malloc(3*sizeof(int));
    if (high==low)
        {
            a[0]=low;
            a[1]=high;
            a[2]=A[low];
            return a;
         }
     else 
     { 
        mid=(int)floor((low+high)/2);//获得<=floor(x)的最小整数ceil则相反
        //printf("Smid=%d\n",mid);       
        left=find_maxmum_subarray(A,low,mid);
        right=find_maxmum_subarray(A,mid+1,high);
        cross=find_max_subarray(A,low,mid,high);
        //printf("left[2]=%d right[2]=%d\n",left[2],right[2]);
        if(left[2]>=right[2]&&left[2]>=cross[2])
        {
            //printf("left:%d %d %d \n",left[0],left[1],left[2]);
            free(right);
            free(cross);
            return left;
        }
        else if(right[2]>=left[2]&&right[2]>=cross[2])
       {
            //printf("right:%d %d %d \n",right[0],right[1],right[2]);
            free(left);
            free(cross);
            return right;
        }
        else
        {
            //printf("cross:%d %d %d \n",cross[0],cross[1],cross[2]);
            free(right);
            free(left);
            return cross;
        }
     }
     
}

int *force_find_maxmum_subarray(int A[],int n)
{
    int sum_max=INT_MIN;
    static int a[3];
    for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int h=i;h<n;h++)
                {
                    sum+=A[h];
                    if(sum>=sum_max)
                        {
                            sum_max=sum;
                            a[0]=i;
                            a[1]=h;
                        }
                }
        }
    a[2]=sum_max;
    return  a;  
}
int *line_find_maxmum_subarray(int A[],int n)
{
    int sum=INT_MIN;
    int *a;
    int k=0;
    int ans=INT_MIN;
    a=(int *)malloc(3*sizeof(int));
    for(int i=0;i<n;i++)
    {
        if(sum<0)
            {
                sum=A[i];               
                k=i;
            }
        else
            {
                sum+=A[i];
                
                if(sum>ans)
                {
                    ans=sum;
                    a[1]=i;
                    a[0]=k;
                }
            }
    }
    a[2]=(ans>sum)?ans:sum;
    return a;
}


