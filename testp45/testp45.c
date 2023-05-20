#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//2023.05.19
//p45 函数练习 --- 传值调用和传址调用

// 1. 判断100-200之间一个数是不是素数 ====================================
//int is_prime(int n)
//{
//	// 2 - n-1之间的数字
//	int j = 0;
//	for (j = 2; j < n; j++)//优化 j < sqrt()
//	{
//		if (n % j == 0)
//			return 0;//不是素数返回0
//	}
//	return 1;//不能被其他数整除，是素数返回1
//}
//int main()
//{
//	// 产生100 - 200 之间的素数
//	int  i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		// 判断i是否素数
//		if (is_prime(i) == 1)
//		{
//			count++;
//			printf("%d\n", i);
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

// 2. 判断一年是否是闰年 =====================================================
//int is_leap_year(int n)//如果不写返回类型，默认返回int型
//{	
//		if (((n % 4 == 0) && (n % 100 !=0)) || (n % 400 == 0))
//			return 1;
//		else 
//			return 0;
//		//或者 return (((n % 4 == 0) && (n % 100 !=0)) || (n % 400 == 0));
//}
//
//int main()
//{
//	int y = 0;
//	for (y = 1000; y <= 2000; y++)
//	{
//		if (is_leap_year(y) == 1)
//			printf("%d ", y);
//	}
//	return 0;
//}

// 3. 实现一个整形有序数组的二分查找 ===============================================
int binary_search(int a[], int k, int s)
//			    待查找数组  要找的数  数组元素个数
{
	int left = 0;
	int right = s - 1;
	
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] > k)
		{
			right = mid - 1;
		}
		else if (a[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int key = 8;//要找的数字
	int sz = sizeof(arr) / sizeof(arr[0]);//数组元素个数
	//找到就返回找到的位置的下标
	//找不到就返回-1
	
	int ret = binary_search(arr,key,sz);//下标
	//数组arr传参，实际传递的不是数组本身，仅传过去了数组首元素的地址

	if (-1 == ret)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了，下标是：%d\n", ret);
	}

	return 0;
}

