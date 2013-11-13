#include<stdio.h>
#include<stdlib.h>
#define N 10 // number of elements

void swap(int *a,int *b){
	int h = *a;
	*a = *b;
	*b = h;
}

int partition(int a[],int p,int r){
	int i,j,x;
	i = p;
	x = a[r];
	for(j=p;j<r;j++){
		if(a[j]<=x){
			swap(&a[j],&a[i]);
			i++;
		}
	}
	swap(&a[i],&a[r]);
	return i;
}

void QuickSort(int a[],int p,int r){
	int q;
	if(p<r){
		q = partition(a,p,r); // partitioning Array a[]
		QuickSort(a,p,q-1);
		QuickSort(a,q+1,r);
	}
}

int main(){
	int i,a[N];
	for(i=0;i<N;i++) a[i] = rand()%100; // getting rand number for Array a[]
	for(i=0;i<N;i++) printf("%d ",a[i]); // Displaying Array a[] before sorting
	QuickSort(a,0,N-1);
	printf("\n");
	for(i=0;i<N;i++) printf("%d ",a[i]); // Displaying Array a[] after sorting
	return 0;
}
