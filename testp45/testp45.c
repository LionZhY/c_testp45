#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//2023.05.19
//p45 ������ϰ --- ��ֵ���úʹ�ַ����

// 1. �ж�100-200֮��һ�����ǲ������� ====================================
//int is_prime(int n)
//{
//	// 2 - n-1֮�������
//	int j = 0;
//	for (j = 2; j < n; j++)//�Ż� j < sqrt()
//	{
//		if (n % j == 0)
//			return 0;//������������0
//	}
//	return 1;//���ܱ�����������������������1
//}
//int main()
//{
//	// ����100 - 200 ֮�������
//	int  i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		// �ж�i�Ƿ�����
//		if (is_prime(i) == 1)
//		{
//			count++;
//			printf("%d\n", i);
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

// 2. �ж�һ���Ƿ������� =====================================================
//int is_leap_year(int n)//�����д�������ͣ�Ĭ�Ϸ���int��
//{	
//		if (((n % 4 == 0) && (n % 100 !=0)) || (n % 400 == 0))
//			return 1;
//		else 
//			return 0;
//		//���� return (((n % 4 == 0) && (n % 100 !=0)) || (n % 400 == 0));
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

// 3. ʵ��һ��������������Ķ��ֲ��� ===============================================
int binary_search(int a[], int k, int s)
//			    ����������  Ҫ�ҵ���  ����Ԫ�ظ���
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
	int key = 8;//Ҫ�ҵ�����
	int sz = sizeof(arr) / sizeof(arr[0]);//����Ԫ�ظ���
	//�ҵ��ͷ����ҵ���λ�õ��±�
	//�Ҳ����ͷ���-1
	
	int ret = binary_search(arr,key,sz);//�±�
	//����arr���Σ�ʵ�ʴ��ݵĲ������鱾��������ȥ��������Ԫ�صĵ�ַ

	if (-1 == ret)
	{
		printf("�Ҳ���\n");
	}
	else
	{
		printf("�ҵ��ˣ��±��ǣ�%d\n", ret);
	}

	return 0;
}

