#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

void swap(int *a,int *b){ int h = *a; *a = *b; *b = h; }

void Selection_sort(int a[]){
	int i,j,min;
	for(i=0;i<N;i++){
		min = i;
		for(j = i+1;j<N;j++){
			if(a[j]<a[min])
				min = j;
		}
		swap(&a[i],&a[min]);
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
	Selection_sort(a);
	stop = clock();
	for(i=0;i<N;i++) printf("%d ",a[i]);
	printf("\n");
	printf("Running Time : %.2lf\n",(stop-start)/CLOCKS_PER_SEC);
	return 0;
}
