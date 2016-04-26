#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include<assert.h>

void AdjustDown(int* a, int parent, int size)
{
	int child = 2 * parent + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[parent]>a[child])
		{
			swap(a[parent], a[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}


void Print(int* a, int size)
{
	cout << "前k个最大的数据：" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}


void HeapSet(int*a,int N,int K)
{
	assert(a);
	assert(K > 0);
	int* arr = new int[K];
	//将前K个数据保存
	for (int i = 0; i < K; i++)
	{
		arr[i] = a[i];
	}

	//建堆
	for (int i = 0; i < (K - 2) / 2; i++)
	{
		AdjustDown(arr,i,K);
	}

	//对剩余的N-K个元素比较大小
	for (int i = K; i < N; i++)
	{
		if (arr[0]<a[i])
		{
			arr[0] = a[i];
			AdjustDown(arr, 0, K);
		}
	}

	Print(arr,K);
	delete[] arr;
}


void Test()
{
	int arr[] = { 12, 2, 10, 4, 6, 8, 54, 67, 25, 178 };
	int k = 5;
	HeapSet(arr, sizeof(arr) / sizeof(arr[0]),k);
}


int main()
{
	Test();
	system("pause");
	return 0;
}