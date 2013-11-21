#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

void swap(int *a,int *b){ int h = *a; *a = *b; *b = h; }

void bubble_sort(int a[]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=N-1;j>i;j--){
			if(a[j]<a[j-1])
				swap(&a[j],&a[j-1]);
		}
	}
}

int main(){
	srand(time(NULL));
	int i,a[N];
	double start,stop;
	for(i=0;i<N;i++) a[i] = rand()%100;
	for(i=0;i<N;i++) printf("%d ",a[i]);
	printf("\n");
	start = clock();
	bubble_sort(a);
	stop = clock();
	for(i=0;i<N;i++) printf("%d ",a[i]);
	printf("\n");
	printf("Running Time : %.2lf\n",(stop-start)/CLOCKS_PER_SEC);
	return 0;
}
