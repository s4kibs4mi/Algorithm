#include <cstdio>
#include <cstdlib>
#define N 10

int a[N] , b[N];

void Merges(int low, int mid, int high){
    int k , h = low , i = low, j = mid +1;

    while(h <= mid && j <= high){
        if(a[h] <= a[j]){
            b[i] = a[h];
            h++;
        }
        else{
            b[i] = a[j];
            j++;
        }
        i++;
    }

    if(h > mid){
        for(k = j; k <= high; k++){
            b[i] = a[k];
            i++;
        }
    }
    else{
        for(k = h; k <= mid; k++){
            b[i] = a[k];
            i++;
        }
    }

    for(k = low; k <= high; k++)
        a[k] = b[k];
}

void MergeSort(int low, int high){
    if(low < high){
        int mid = ( low + high ) / 2;
        MergeSort(low,mid);
        MergeSort(mid+1,high);
        Merges(low,mid,high);
    }
}

int main(){
    int i;
    for(i = 0; i < N; i++)
        scanf("%d",&a[i]);
    MergeSort(0,N-1);
    for(i = 0; i < N; i++)
        printf("%d ",b[i]);
    return 0;
}
