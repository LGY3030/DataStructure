#include <stdio.h>
#include <string.h>
#define max_size 500
#define exchange(x, y) (x = x^y, y = x^y, x = x^y)
int curLevel(int pos);
void add(int bst[], int value, int *level);
void renewLevel(int bst[], int *level);
void deleteValue(int bst[], int pos, int *level);
void printBST(int bst[],int level);

int main()
{
	int i;
    int bst[max_size];
    memset(bst, -1, sizeof(bst));
    int value;
    int level=1;
    int count=0;
    do
    {
        scanf("%d", &value); 
		if(value==-1)
		break;  
        add(bst, value, &level); 
        count++;
        
    }
    while(getchar()!='\n');
    printf("Create Binary search tree\n");
    printBST(bst, level);
	
    int dePos;
    int check;
    char yorn[5];
    while(1)
    {
    	check=-50;
    	printf("Delete element?(Y/N) : "); 
    	scanf("%s", yorn);
    	if((strcmp(yorn,"Y")==0)||(strcmp(yorn,"y")==0)){
    		printf("Choice element: ");
        	scanf("%d", &dePos);
        for(i=1;i<=count;i++){
        	if(dePos==bst[i]){
        		dePos=i;
        		check=i;
			}
			else{
				
			}
		}
		if(check==-50){
			printf("%d is not in the tree\n",dePos); 
		}
		else{
			deleteValue(bst, dePos, &level); 
		printf("Binary search tree\n");
        printBST(bst, level);
		}
		}
		else 
		break;
        
    }

    return 0;
}

int curLevel(int pos)
{
    int l=0;
    while(pos!=0)
        pos >>= 1, l++;
    return l;
}

void add(int bst[], int value, int *level)
{
    if(bst[1]==-1)  
        bst[1] = value;
    else
    {
        int temp = bst[1];  
        int pos = 1;
        while(temp!=-1)
        {
            if(value<temp)
                pos <<= 1;
            else if(value>temp)
                pos = (pos<<1)+1;
            else if(value==temp)    
                return;
            temp = bst[pos];
        }
        bst[pos] = value;

        int l;
        if((l=curLevel(pos))>*level)
            *level = l;
    }
}

void renewLevel(int bst[], int *level)
{
  
    int i, j, n;
    int isEmpty;
    do
    {
        n = 1, isEmpty = 1;
        for(i=0; i<*level; i++) 
            n <<= 1;
        for(i=(n>>1); i<n; i++)
            if(bst[i]!=-1)
                isEmpty = 0;
        if(isEmpty)
            (*level)--;
    }
    while(*level && isEmpty);
}

void deleteValue(int bst[], int pos, int *level)
{
    int lr=1; 
    int cpos;   
    do
    {
        cpos = pos;
        if(bst[cpos<<1]!=-1)
            cpos <<= 1, lr=1;
        else if(bst[(cpos<<1)+1]!=-1)
            cpos = (cpos<<1)+1, lr=2;
        else
        {
            bst[cpos] = -1; 
            renewLevel(bst, level);
            return;
        }

        int temp;
        do
        {
            if(lr==1)
                cpos = (cpos<<1)+1;
            else if(lr==2)
                cpos <<= 1;
            temp = bst[cpos];
        }
        while(temp!=-1);
        cpos >>= 1;
        exchange(bst[pos], bst[cpos]), bst[cpos] = -1;  
        pos = lr==1? pos<<1: (pos<<1)+1; 
    }
    while(bst[pos]==-1);
}

void printBST(int bst[],int level)
{
    int i, j, k=1, n=1;
    for(i=0; i<level; i++)
    {
        for(j=0; j<n; j++)
        {
            if(bst[k]==-1)
                printf("*  ");
            else
                printf("%d  ", bst[k]);
            k++;
        }
        n <<= 1;
        printf("\n");
    }
    
}
