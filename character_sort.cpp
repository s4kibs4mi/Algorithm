// Character sorting using insertion sort

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10

void DisplayNumb(int a[]);

void NumValueGen(char a[]){
	for(int i=0;i<N;i++) a[i] = 65+rand()%25;
}


void InsertionSort(char a[]){
	int i,j,key;
	for(i=1;i<N;i++){
		key = a[i];
		for(j=i-1;j>=0 && a[j]>key;j--){
			a[j+1] = a[j];
		}
		a[j+1] = key;
	}
}


void DisplayChar(char a[]){
	for(int i=0;i<N;i++) printf("%c ",a[i]);
}
int main(){
	char a[N];
	//double start_time,end_time;
	NumValueGen(a);
	printf("After Sort :\n");
	DisplayChar(a);
	//start_time = clock();
	InsertionSort(a);
	//end_time = clock();
	printf("\nAfter Sort :\n");
	DisplayChar(a);
	//printf("\nAlgorithm Execute Time : %.2lf",(end_time-start_time)/CLOCKS_PER_SEC);
	return 0;
}
