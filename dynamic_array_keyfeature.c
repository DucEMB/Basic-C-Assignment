#include <stdio.h>
#include <stdlib.h>

void add_element(int * ptr,int * size,int * capacity,int data);
void delete_element(int * ptr,int * size,int key);
void traverse_array(int * ptr,int * size);

int main()
{
	int * ptrarr;
	int size = 0;
	int capacity = 10;
	ptrarr = (int *)calloc(capacity,sizeof(int));
	int i;
	/* add element */
	add_element(ptrarr,&size,&capacity,5);
	add_element(ptrarr,&size,&capacity,6);
	add_element(ptrarr,&size,&capacity,7);
	add_element(ptrarr,&size,&capacity,8);
	add_element(ptrarr,&size,&capacity,9);
	
	for (i = 0;i < capacity;i++)
	{
		printf("%d ",*(ptrarr + i));
	}
	
	/* Indexing element[3] (array index start at 0 ) */
	printf("\n\n");
	printf("gia tri tai o nho thu 3: %d ",ptrarr[3]);
	
	/* delete element at index 2 (array index start at 0) */
	/*delete_element(ptrarr,&size,2);
	
	printf("\nAfter delete element[2]:\n");
	for (i = 0;i < capacity;i++)
	{
		printf("%d ",*(ptrarr + i));
	}*/
	return 0;
}


void add_element(int * ptr,int * size,int * capacity,int data)
{
	if (size == capacity)
	{
		* capacity = (*capacity) * 2;
		realloc(ptr,(* capacity));
	}
	*(ptr + *size) = data;
	(* size)++;
}

void delete_element(int * ptr,int * size,int key)
{
	int i;
	for (i = key;i < * size;i++)
	{
		* (ptr + i) = * (ptr + i + 1);
	}
	* (ptr + (* size)- 1) = 0;
	(* size)--;
}

void traverse_array(int * ptr,int * size)
{
	int i;
	for (i = 0;i < * size;i++)
	{
		/* Code */
		printf("%d ",*(ptr + i));
	}
}


