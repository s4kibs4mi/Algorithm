#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int h = *a;
    *a = *b;
    *b = h;
}

void PrintArray(int a[][3],int e){
    for(int i=0;i<e;i++){
        for(int j=0;j<3;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

}

void SortW(int a[][3],int e){
    int i,j,min;
    for(i=0;i<e;i++){
        min = i;
        for(j=i+1;j<e;j++){
            if(a[j][2]<a[min][2])
                min = j;
        }
        swap(&a[i][2],&a[min][2]);
        swap(&a[i][1],&a[min][1]);
        swap(&a[i][0],&a[min][0]);
    }
}

void MakeSet(int parent[],int v){
	for(int i=1;i<= v;i++) parent[i] = i;
}

int find(int parent[],int r){
	if(parent[r] == r) return r;
	return find(parent,parent[r]);
}

int main(){
    freopen("in.txt","r",stdin);
    int v,e;
    scanf("%d %d",&v,&e);
    int a[e][3],parent[v];
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
    }
    printf("Inputed : \n\n");
    PrintArray(a,e);
    printf("\n");
    SortW(a,e);
    printf("\nSorted : \n\n");
    PrintArray(a,e);
    printf("\n\n");
    
    MakeSet(parent,v);
	printf("\nMST : \n\n");
	int i = 0,count = 0,MinCost = 0;
	while(i < e){
		int x,y;
		x = find(parent,a[i][0]);
		y = find(parent,a[i][1]);
		if(x!=y){
            parent[x]=y;
            count++;
            MinCost += a[i][2];
            printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
            if(count==v-1) break;
        }
        i++;
	}
	printf("\n\nMinimum Cost : %d\n",MinCost);
    return 0;
}
