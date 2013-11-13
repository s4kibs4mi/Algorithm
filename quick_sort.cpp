#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100000 // number of data to be sort

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
	srand(time(NULL));
	int i,a[N];
	double start,stop;
	for(i=0;i<N;i++) a[i] = rand()%100;
	//for(i=0;i<N;i++) printf("%d ",a[i]); // printing data before sorting
	printf("\n");
	start = clock();
	quickSort(a,0,N-1);
	stop = clock();
	//for(i=0;i<N;i++) printf("%d ",a[i]); // printing data after sorting
	printf("\n\nRequired time to Sort : %.3lf",(stop-start)/CLOCKS_PER_SEC);
	return 0;
}
