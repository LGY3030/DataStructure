
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define maxsize 100
#define max(x, y) ( x>y? x: y ) 
#define min(x, y) ( x<y? x: y )


struct node{
	int id;
	int cost;
};


void set_ee(int n, int ee[], int matrix[][maxsize]);
void set_le(int n, int le[], int matrix[][maxsize]);
int set_EandL(int n, int e[], int l[], int ee[], int le[], int matrix[][maxsize]);

void getPath(int n, int matrix[][maxsize], struct node path[], struct node cpath[], int *index, int id, int step);



int main(int argc, char *argv[])
{
	int matrix[maxsize][maxsize];
	int i=0, j=0;
	FILE *fin = fopen("input.txt", "r");
	/*input data*/
	while(1)
	{
		int temp;
		if(fscanf(fin, "%d", &temp)==EOF)
			break;
		matrix[i][j++] = temp;
		if(fgetc(fin)=='\n')	//new line
			i++, j=0;
	}
	int n = j;
	int num = n*(n+1)/2;
	int ee[n], le[n], e[num], l[num];
	/*set ee[]*/
	set_ee(n, ee, matrix);
	/*set le[]*/
	le[n-1] = ee[n-1], le[0] = 0;
	set_le(n, le, matrix);
	/*set e[] and l[]*/
	num = set_EandL( n, e, l, ee, le, matrix);
	/*record path and get number of passed nodes*/
	struct node path[n], cpath[n];
	for(i=0; i<n; i++)
		path[i].cost = 0, cpath[i].cost = 0;
	int index;	//number of node
	getPath(n, matrix, path, cpath, &index, 0, 0);
	path[index-1].id = 8;
	int q[index],k;
	for(k=0; k<index; k++)
	q[k]=0;
	/*output data*/
	puts("a.");

	printf("     e    l\n");
	for(k=0; k<n; k++)
		printf("%d    %d    %d\n",k, ee[k], le[k]);
	printf("\n");
	for(k=0; k<index; k++)
		q[path[k].id+1]=1;
	
	puts("b.");
	
	printf("     e    l   c\n");
	for(k=0; k<num; k++){
	
		if(k>=10) {
			
			
				if(q[k]==1)
			printf("%d   %d    %d   Y",k, e[k], l[k]);
			else
			printf("%d   %d    %d   N",k, e[k], l[k]);
			
			
			
		}
			
			
		else{
			
		
				if(q[k]==1)
			printf("%d    %d    %d   Y\n",k, e[k], l[k]);
			else
			printf("%d    %d    %d   N\n",k, e[k], l[k]);

			
			
		}
		
	}
		
	
	
		
	puts("");
	
	return 0;
}

void set_ee(int n, int ee[], int matrix[][maxsize])
{
	memset(ee, 0, sizeof(int)*n);
	int i, j;
	for(i=1; i<n; i++)	//pointed - col
		for(j=0; j<i; j++)	//from - row
			if(matrix[j][i]!=0)
				ee[i] = max(ee[i], ee[j]+matrix[j][i]);	//set the max of each point
}

void set_le(int n, int le[], int matrix[][maxsize])
{
	int i, j;
	for(i=0; i<n-1; i++)
		le[i] = INT_MAX;
	for(i=n-2; i>=0; i--)	//point out - row
		for(j=i; j<n; j++)	//pointed - col
			if(matrix[i][j]!=0)
				le[i] = min(le[i], le[j]-matrix[i][j]);
}

int set_EandL(int n, int e[], int l[], int ee[], int le[], int matrix[][maxsize])
{
	int i, j, k=0;
	/*set e[]*/
	for(i=0; i<n; i++)	//row
		for(j=0; j<n; j++)	//col
			if(matrix[i][j]!=0)
				e[k++] = ee[i];
	/*set l[]*/
	k=0;
	for(i=0; i<n; i++)	//col
		for(j=0; j<n; j++)	//row
			if(matrix[j][i]!=0)
				l[k++] = le[i]-matrix[j][i];
	return k;
}

void getPath(int n, int matrix[][maxsize], struct node path[], struct node cpath[], int *index, int id, int step)
{
	int i;
	if(id==n-1)
	{
		int csum = 0;
		for(i=0; i<n; i++)
			csum += cpath[i].cost;
		int sum = 0;
		for(i=0; i<n; i++)
			sum += path[i].cost;
		if(sum<csum)	//more cost
		{
			*index = step+1;	//add n-1 node
			for(i=0; i<n; i++)	//copy
				path[i].cost = cpath[i].cost, path[i].id = cpath[i].id;
		}
		cpath[step-1].cost = 0;	//back track
		return;
	}
	for(i=0; i<n; i++)	//row
		if(matrix[id][i]!=0)
		{
			cpath[step].id = id, cpath[step].cost = matrix[id][i];
			getPath(n, matrix, path, cpath, index, i, step+1);	//step out
		}
	cpath[step-1].cost = 0;	//back track
	return;
}


