#include<stdio.h>   

int binomial(int  n,int k)
{
    if (k != 0 && n != k) {
    	
        return binomial(n-1, k) + binomial(n-1, k-1);
        
    } 
	else {
		
        return 1;
    }
}

int main(void)
{
	int k,n,result; 
	

    scanf("%d",&n);
  
    scanf("%d",&k);

    result = binomial(n,k);
    
    printf("%d\n",result);
    
    return 0;
}

    
