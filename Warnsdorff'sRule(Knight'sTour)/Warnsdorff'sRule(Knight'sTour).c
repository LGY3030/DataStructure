#include<stdio.h>
#include<stdbool.h>
#define N 8
 
int solvestep(int x, int y, int move, int a[N][N],
                int ktmove1[],  int ktmove2[]);
 

void printsolution(int a[N][N])
{
	int x,y;
    for (x = 0; x < N; x++)
    {
        for (y = 0; y < N; y++)
            printf(" %2d ", a[x][y]);
        printf("\n");
    }
}
 
bool check(int x, int y, int a[N][N])
{
    return ( x >= 0 && x < N && y >= 0 &&
             y < N && a[x][y] == 0);
}

bool start(){

    int a[N][N];
 	int x,y;

    for (x = 0; x < N; x++)
        for (y = 0; y < N; y++)
            a[x][y] = 0;
 

    int ktmove1[8] = {-2,-1,1,2,2,1,-1,-2};
    int ktmove2[8] = {1,2,2,1,-1,-2,-2,-1};
 

    a[0][0]=1;
 	
 	if(N==1){
 		printf("%d:\n",N);
 		printf("%2d",a[0][0]);
	}
	 
	else{
    	if (solvestep(0, 0, 2, a, ktmove1, ktmove2) == false)
    	{
    		printf("%d:\n",N);
        	printf("no solution");
        	return false;
    	}
    	else
    		printf("%d:\n",N);
        	printsolution(a);
 
    	return true;
   	}
}
 

int solvestep(int x, int y, int move, int a[N][N],
                int ktmove1[N], int ktmove2[N])
{
   int k, next_x, next_y;
   if (move == N*N+1)
       return true;
 
 
   for (k = 0; k < 8; k++)
   {
       next_x = x + ktmove1[k];
       next_y = y + ktmove2[k];
       if (check(next_x, next_y, a))
       {
         a[next_x][next_y] = move;
         if (solvestep(next_x, next_y, move+1, a,
                         ktmove1, ktmove2) == true)
             return true;
         else
             a[next_x][next_y] = 0;
       }
   }
 
   return false;
}
 

int main()
{
    start();

}
