#define _CRT_SECURE_NO_WARNINGS
// https://www.acmicpc.net/problem/2751
// Sorting_1 [01/18]

/*
*  N의 최댓값이 10^6, 제한 시간은 1초이면 
*  N=10^6 일 때 O(NlogN) = 1.6 * (10^7) < 10^8 이므로
*  O(NlogN)인 알고리즘으로 해결 가능하다.
*  Quick Sort는 평균적으로 O(NlongN)이지만
*  worst case에 대해 O(N^2)이기 때문에 시간 초과가 발생했다.
*
*  [Merge Sort]
*  퀵 정렬과 동일하게 devide-and-conquer를 이용한다.
*  퀵 정렬은 pivot을 기준으로 정렬 후 분할하지만
*  병합 정렬은 모두 분할 후 정렬을 하는 차이가 있다.
*/

#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right)
{
	int leftSize = mid - left + 1;
	int rightSize = right - mid; // mid 비포함하므로 1을 더해지 않는다! (이거 때문에 오류 발생함)
	int* leftArr = new int[leftSize]; // left ~ mid
	int* rightArr = new int[rightSize]; // mid+1 ~ right

	// 값 복사
	for (int m = 0; m < leftSize; m++)
	{
		leftArr[m] = arr[left+m];
	}
	for (int n = 0; n < rightSize; n++)
	{
		rightArr[n] = arr[mid+1+n];
	}

	int i = 0; int j = 0; int k = left;

	// 정렬
	while (i < leftSize && j < rightSize)
	{
		if (leftArr[i] < rightArr[j])
		{
			arr[k] = leftArr[i];
			i++;
		}
		else
		{
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}

	// 나머지 정렬
	while (i < leftSize)
	{
		arr[k++] = leftArr[i++];
	}
	while (j < rightSize)
	{
		arr[k++] = rightArr[j++];
	}
}

void mergeSort(int arr[], int left, int right)
{
	if (left >= right)
		return;
	
	int mid = (left + right) / 2;

	mergeSort(arr, left, mid); // 분할
	mergeSort(arr, mid + 1, right); // 분할
	merge(arr, left, mid, right); // 정복
}

int main(void)
{	
	int N;
	cin >> N;
	int num[1000001];
	// int* num = new int[N];

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]); // 입력 횟수가 많은 경우 cin/cout보다 scanf/printf를 이용(시간 초과 발생)
	}

	mergeSort(num, 0, N-1);

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", num[i]);
	}

	return 0;
}
