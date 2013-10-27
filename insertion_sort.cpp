#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10000
void DisplayNumb(int a[]);
void NumValueGen(int a[]){
	for(int i=0;i<N;i++) a[i] = rand()%50;
}


void InsertionSort(int a[]){
	int i,j,key;
	for(i=1;i<N;i++){
		key = a[i];
		for(j=i-1;j>=0 && a[j]>key;j--){
			a[j+1] = a[j];
		}
		a[j+1] = key;
		//DisplayNumb(a);
		//printf("\n\n");
	}
}


void DisplayNumb(int a[]){
	for(int i=0;i<N;i++) printf("%d ",a[i]);
}
int main(){
	int a[N];
	double start_time,end_time;
	NumValueGen(a);
	start_time = clock();
	InsertionSort(a);
	end_time = clock();
	//DisplayNumb(a);
	printf("\nAlgorithm Execute Time : %.2lf",(end_time-start_time)/CLOCKS_PER_SEC);
	return 0;
}
