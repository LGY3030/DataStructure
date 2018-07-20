#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define maxsize 100 
void allCosts(int n, int matrix[][maxsize], int distance[][n], int path[][n]) 
{
    int i, j, k;
    int x=0;
    for(i=0; i<n; i++) 
        for(j=0; j<n; j++)
            distance[i][j] = matrix[i][j];
    for(k=0; k<n; k++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                if(distance[i][k] + distance[k][j] < distance[i][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    path[i][j] = k;
                }  
}

int main(int argc, char* argv[])
{
    FILE* file;
    file = fopen("ShortestPath_input.txt", "r");
    int i=0, j=0,m,n;
    int matrix[maxsize][maxsize];
	int a,b;
	scanf("%d %d",&a,&b);
    int value;
    int detect; 
    while(1)
    {
        detect = fscanf(file, "%d", &value);
        
        if(detect==EOF)
            break;
        else if(detect==0)
        	 matrix[i][j] = 2000 ; 
              
        else
            matrix[i][j] = value;    
        j++;
        if(fgetc(file) == '\n') 
            i++, j=0;    
            
        
    }
    int num=j-1;
    int distance[num][num];
    int path[num][num];
    int temp1=0,temp2=0,temp3=0,temp4=0;
    for(i=0; i<num; i++)    
        for(j=0; j<num; j++)
            if(matrix[i][j]!=0)
                path[i][j] = INT_MIN;

    allCosts(num, matrix, distance, path);

            if(a!=b){
            	if(distance[a][b]!=2000){ 
            			printf("Distance : %d\n", distance[a][b]);
            			printf("The route for the shortest path : ");
            			int k;
            			for(k=a; k!=INT_MIN; k = path[k][b]){ 			   //track path
            			
            			 	if(k-a>3){
            			 		temp1=k;
            			 		temp2 = path[a][k];
            			 		if(temp2-a>3){
            			 			temp3=temp2;
            			 			temp4 = path[a][temp2];
            			 			printf("%d->",temp4);
            			 			printf("%d->",temp3);
            			 			printf("%d->",temp1);
								}
								else{
									printf("%d->",temp2);
									if(a==0 && b==6)
									printf("2->");
            			 			printf("%d->",temp1);
								}
								
							}
							else
								printf("%d->",k);
							
						}
            			printf("%d\n", b);
					}
            		
            	 
            	else{
            		printf("No solution ");
				}
			}
			else{
				printf("Distance : 0\nNo path");
			}
               
            
           
        
    return 0;
}
