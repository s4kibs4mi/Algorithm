#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 11

void swap(int *a,int *b){ int h = *a; *a = *b; *b = h; }

void adjust(int a[],int i,int n){
	int j,item;
	j = 2*i;
	item = a[i];
	while(j<=n){
		if(j<n && a[j] < a[j+1]) j++;
		if(item >= a[j]) break;
		a[j/2] = a[j];
		j = 2*j;
	}
	a[j/2] = item;
}

void heapify(int a[],int n){
	int i;
	for(i=n/2;i>=1;i--)
		adjust(a,i,n);
}

void heap_sort(int a[],int n){
	int i;
	heapify(a,n);
	for(i=n;i > 1;i--){
		swap(&a[i],&a[1]);
		adjust(a,1,i-1);
	}
}

int main(){
	srand(time(NULL));
	int i,a[N];
	double start,stop;
	for(i=0;i<N;i++) a[i] = rand()%100;
	for(i=1;i<N;i++) printf("%d ",a[i]);
	printf("\n");
	start = clock();
	heap_sort(a,N-1);
	stop = clock();
	for(i=1;i<N;i++) printf("%d ",a[i]);
	printf("\n");
	printf("Running Time : %.2lf\n",(stop-start)/CLOCKS_PER_SEC);
	return 0;
}
