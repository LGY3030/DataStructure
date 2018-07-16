#include<stdio.h>
#include<stdbool.h>

bool check(int m,int n,int x, int y, int a[m][n])
{
    return ( x >= 0 && x < m && y >= 0 &&
             y < n && (a[x][y] == 0||a[x][y] == 6));
}

int main(void){
	int m,n;
	int starti,startj;
	int endi,endj;
	scanf("%d%d",&m,&n);
	int a[m][n];
	char getmaze[n];
	int i,j;	
	for(i=0;i<m;i++){
			scanf("%s",getmaze);
			for(j=0;j<n;j++){
			if(getmaze[j]=='s'){
				a[i][j]=5;
				starti=i;
				startj=j;
			}
			else if(getmaze[j]=='d'){
				a[i][j]=6;
				endi=i;
				endj=j;
			}
			else if(getmaze[j]=='0'){
				a[i][j]=0;
			}	
			else{
				a[i][j]=1;
			}	
		}
	}
	int ktmove1[8] = {-1,0,1,1,1,0,-1,-1};
    int ktmove2[8] = {1,1,1,0,-1,-1,-1,0};
    
 	if (solvestep(m,n,starti, startj,endi, endj, a, ktmove1, ktmove2) == false)
    {
    	
        printf("no route");
        return false;
    }
    else
	{
		printsolution(m,n,endi, endj,a);
	}
	return true;
	
}

int solvestep(int m,int n,int x, int y,int w,int z,  int a[m][n],int ktmove1[8], int ktmove2[8])
{
   int k, next_x, next_y;
   int i,j;
	if (a[w][z] != 6)
       	return true;	


   for (k = 0; k < 8; k++)
   {
       next_x = x + ktmove1[k];
       next_y = y + ktmove2[k];
       if (check(m,n,next_x, next_y, a))
       {
         a[next_x][next_y] = 8;
         if (solvestep(m,n,next_x, next_y, w, z,a, ktmove1, ktmove2) == true)
             return true;
         else
             a[next_x][next_y] = 0;
       }
   }
 
   return false;
}
void printsolution(int m,int n,int w,int z,int a[m][n])
{
	int i,j,count=0,finalcount;
	for (i = 0; i < m; i++){
    	for (j = 0; j < n; j++){
    		if(a[i][j]==8){
    			count++;
			}
		}
    }
    finalcount=count+1;
    printf("\n");
    for (i = 0; i < m; i++){
    	for (j = 0; j < n; j++){
    		if(i==w && j==z){
    			printf("d");
			}
			else if(a[i][j]==5){
    			printf("s");
			}
    		else if(a[i][j]==8){
    			printf("*");
			}
			else{
				printf("%d",a[i][j]);
			}
	
		}
        printf("\n");
	}
    printf("%d steps",finalcount);
        
    
}
