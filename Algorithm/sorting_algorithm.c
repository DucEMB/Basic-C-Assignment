#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int l,int m,int r)
{
	int i;
	int j;
	int k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int subarr1[n1];
	int subarr2[n2];
	for (i = 0;i < n1;i++)
	{
		subarr1[i] = arr[l + i];  // copy cac phan tu vao mang phu
	}
	for (j = 0;j < n2;j++)
	{
		subarr2[j] = arr[m + 1 + j];
	}
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) // dua cac phan tu da duoc sap xep ve mang chinh
	{
		if (subarr1[i] <= subarr2[j])
		{
			arr[k] = subarr1[i];
			i++;
		}
		else
		{
			arr[k] = subarr2[j];
			j++;
		}
		k++;
	}
	while (i < n1) // neu con cac phan tu con thua thi dua lai mang ban dau
	{
		arr[k] = subarr1[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = subarr2[j];
		j++;
		k++;
	}
}

int partition(int arr[],int low,int high)
{
	int pivot;
	pivot = arr[high];
	int temp;
	int i = low - 1;
	int j;
	for (j = low; j <= high;j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
	return (i+1);
}

void quick_sort(int arr[],int low,int high)
{
	int pi;
	if (low < high)
	{
		pi = partition(arr,low,high);
		quick_sort(arr,low,pi - 1);
		quick_sort(arr,pi + 1,high);
	}
}

void merge_sort(int arr[],int l,int r)
{
	int m;
	if (l < r)
	{
		m = l + (r - l) / 2;
		merge_sort(arr,l,m);
		merge_sort(arr,m + 1,r);
		merge(arr,l,m,r);
	}
}

void bubble_sort(int arr[],int l,int r)
{
	int i;
	int j;
	int temp;
	int flag = 0;
	for (i = l;i < r;i++)
	{
		for (j = 0;j < r - i;j++)
		{
			if (arr[j] > arr[j+ 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
		}
	}
}

void selection_sort(int arr[],int l,int r)
{
	int i;
	int j;
	int min_idx;
	int temp;
	for (i = l;i <= r;i++)
	{
		min_idx = i;
		for (j = i + 1;j <= r;j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}
		temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
	}
}

void insertion_sort(int arr[],int l,int r)
{
	int i;
	int j;
	int key;
	for (i = l + 1;i <= r;i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key )
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void heapify(int arr[],int n,int i)
{
	int temp;
	int largest = i;
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	if (l < n && arr[l] > arr[largest])
	{
		largest = l;
	}
	if (r < n && arr[r] > arr[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr,n,largest);
	}
}

void heap_sort(int arr[],int n)
{
	int i;
	int temp;
	for (i = n / 2 - 1;i >= 0;i--)
	{
		heapify(arr,n,i);
	}
	for (i = n - 1;i >= 0;i--)
	{
		temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		heapify(arr,i,0);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int * arr;
	arr = (int *)malloc(n * sizeof(int));
	printf("input:   ");
	for (i = 0;i < n;i++)
	{
		scanf("%d",&arr[i]);
	}
	heap_sort(arr,n);
	printf("output:  ");
	for (i = 0;i < n;i++)
	{
		printf("%d ",arr[i]);
	}
	free(arr);
	return 0;
}
