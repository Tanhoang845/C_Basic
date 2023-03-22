#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
void swap(double *list, int i, int j)
{
	double tmp = list[i];
	list[i]=list[j];
	list[j]=tmp;
}
void bubbleSort(double *list,int size)
{
	int i,j;
	for(i=size;i>=2;i--)
		for(j=0;j<i;j++)
			if(list[j-1]>list[j])
				swap(list,j-1,j);
}

void bubbleSortImproved(double *list,int size)
{
	int i,j;
	for(i=size;i>=2;i--)
	{
		int countSwap = 0;
		for(j=0;j<i;j++)		
			if(list[j-1]>list[j])
			{
				countSwap++;
				swap(list,j-1,j);
			}
		if(countSwap==0) return; // day da co thu tu	
	}		
}

void selectionSort(double *list,int size)
{
	int i,j;
	for(i=size; i>=2; i--)
	{
		int vtMax = 0;
		for(j=1; j<i; j++)
			if(list[j]>list[vtMax]) vtMax=j;
		swap(list,vtMax,i-1);	
	}
}
// thuc hien selectionsort theo khoang tu start toi end
void selectionSort2(double *list,int start, int end)
{
	int i,j;
	int size = end-start +1;
	for(i=start+size; i>=2+start; i--)
	{
		int vtMax = 0+start;
		for(j=1+start; j<i; j++)
			if(list[j]>list[vtMax]) vtMax=j;
		swap(list,vtMax,i-1);	
	}
}

void quickSort(double *list, int s, int e)
{
	if(s>=e) return;
	int pivot = list[s];
	int i=s+1, j=e;
	while(j>=i)
	{
		if(list[j]<pivot)
		{
			swap(list,i,j);
			i++;
		}
		else j--;		
	}
	swap(list,j,s); // dao lai vi tri cua pivot
	
	quickSort(list,s,j-1);
	quickSort(list,j+1,e);
}

void quickSortImproved(double *list, int s, int e)
{
	if(s>=e) return;
	if(e-s<=100) // nho hon 100 thi chon selectionSort
	{
		selectionSort2(list,s,e);
		return;
	}	
	
	int pivot = list[s];
	int i=s+1, j=e;
	while(j>=i)
	{
		if(list[j]<pivot)
		{
			swap(list,i,j);
			i++;
		}
		else j--;		
	}
	swap(list,j,s); // dao lai vi tri cua pivot
	
	quickSort(list,s,j-1);
	quickSort(list,j+1,e);
}

// sinh ngau nhien mang kich thuoc size
double *generateList(int size)
{
	double* list = (double*)malloc(sizeof(double)*size);
	srand(time(NULL)); //khoi tao nhan ngau nhien
	for(int i=0; i<size; i++)
		list[i] = rand();
	return list;
}

// 10 phan tu dau va 10 cuoi
void printTest(const double *list,int size, int limit)
{
	printf("front: ");
	int i;
	for(i=0;i<limit;i++)
		printf("%.2lf, ",list[i]);
	printf("\ntail: ");
	
	for(i= size-limit-1;i<size;i++)
		printf("%.2lf, ",list[i]);
	printf("\n");
}

void printAll(const double *list,int size)
{
	printf("Data:");
	for(int i=0;i<size;i++)
		printf("%.2lf, ",list[i]);
	printf("\n");
}

double * generateCopy(double *list, int size)
{
	double* list2 = (double*)malloc(sizeof(double)*size);
	for(int i=0; i<size; i++)
		list2[i] = list[i];
	return list2;
}

int main()
{
	double *list;
	int SIZE = 5000, LIMIT = 20;
	list= generateList(SIZE);
	printf("Test size: %d\n", SIZE);
	struct timeval start, stop;
	double secs = 0;
	
	gettimeofday(&start, NULL);
	double *list1 = generateCopy(list, SIZE);
	//quickSort(list1,0,SIZE-1);
	bubbleSort(list1,SIZE);
	free(list1);
	gettimeofday(&stop, NULL);
	secs = (double)(stop.tv_usec - start.tv_usec) ;
	printf("Bubble Sort time taken %lf\n",secs);
	
	gettimeofday(&start, NULL);
	list1 = generateCopy(list, SIZE);
	bubbleSortImproved(list1,SIZE);
	free(list1);
	gettimeofday(&stop, NULL);
	secs = (double)(stop.tv_usec - start.tv_usec) ;
	printf("Bubble improved Sort time taken %lf\n",secs);
	
	gettimeofday(&start, NULL);
	list1 = generateCopy(list, SIZE);
	selectionSort(list1,SIZE);	
	free(list1);
	gettimeofday(&stop, NULL);
	secs = (double)(stop.tv_usec - start.tv_usec) ;
	printf("Selection Sort time taken %lf\n",secs);
	
	gettimeofday(&start, NULL);
	list1 = generateCopy(list, SIZE);
	quickSort(list1,0,SIZE-1);
	free(list1);
	gettimeofday(&stop, NULL);
	secs = (double)(stop.tv_usec - start.tv_usec) ;
	printf("Quick Sort time taken %lf\n",secs);
	
	//printf("\n\nDA sap xep:\n");
	//printAll(list, SIZE);
	//printTest(l1,SIZE,LIMIT);
	
	return 0;
}


