// Character sorting using insertion sort

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 100

void DisplayNumb(int str[]);

void InsertionSort(char str[]){
	int i,j,key,len = strlen(str);
	for(i=1;i<len;i++){
		key = str[i];
		for(j=i-1;j>=0 && str[j]>key;j--){
			str[j+1] = str[j];
		}
		str[j+1] = key;
	}
}

int main(){
	char str[N];
	//double start_time,end_time;
	gets(str);
	//start_time = clock();
	InsertionSort(str);
	//end_time = clock();
	printf("\nAfter Sort :\n");
	puts(str);
	//printf("\nAlgorithm Execute Time : %.2lf",(end_time-start_time)/CLOCKS_PER_SEC);
	return 0;
}
