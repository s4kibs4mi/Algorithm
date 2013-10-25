#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100000 // number of data to be sort

void swap(int *x,int *y){
	int hold;
	hold = *x;
	*x = *y;
	*y = hold;
}

int partition(int a[],int p,int r){
	int x = a[r],i = p-1,j;
	for(j=p;j<r;j++){
		if(a[j]<=x){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[r]);
	return i+1;
}

void quickSort(int a[],int p,int r){
	if(p<r){
		int q = partition(a,p,r);
		quickSort(a,p,q-1);
		quickSort(a,q+1,r);
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
