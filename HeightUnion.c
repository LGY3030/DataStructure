#include<stdio.h>
int parent[100];
void HeightUnion(int i,int j){
	if(parent[i]<parent[j]){
		parent[i]=j;
	}
	else if(parent[i]==parent[j]){
		parent[j]=i;
		parent[i]=parent[i]+1;
	}
	else{
		parent[j]=i;
	}
}
int main(void){
	int a,i,j,k;
	scanf("%d",&a);
	for(i=0;i<100;i++){
		parent[i]=-100;
	}
	for(j=1;j<a;j++){
		HeightUnion(0,j);
	}
	printf("Node    parent\n");
	for(k=0;k<a;k++){
		printf("%d    ",k);
		if(parent[k]>=0){
			printf("   %d",parent[k]);
		}
		else if(parent[k]<0){
			printf("   root");
		}
		else{
			;
		}
		printf("\n");
	}
} 
