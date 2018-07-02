#include <stdio.h>
#include <stdlib.h>
#define address_xor(x, y) (node*)((unsigned)(x)^(unsigned)(y))

typedef struct _node
{
    int data;
    struct _node *link;
} node;

void print_data(node *head, int mode)   
{
    int count=0;
	node *lead, *middle, *follow;
    follow = NULL;
    middle = head;
    if(mode==1)
        puts("The data from left to right:");
    else if(mode==2)
        puts("The data from right to left:");
    printf("%d, ", middle->data, middle->link);
    count++;
    while(lead = address_xor(follow, middle->link)) 
    {
    	count++;
    	if(count<20)
        printf("%d, ", lead->data, lead->link);
        else
        printf("%d ", lead->data, lead->link);
        follow = middle;
        middle = lead;
    }
    printf("\n");
}

int main()
{
    
   
        int i=2;
        node *middle = malloc(sizeof(node)); 
        middle->data=1;  
        
        node *left=NULL, *right, *l_head, *r_head;
        while(1){
        	right = malloc(sizeof(node));   
            right->data=i;
            middle->link = address_xor(left, right);  
            if(i==20)
                break;
            if(!left)  
                l_head = middle;
            left = middle; 
            middle = right;
        	i++;
		}
            
        r_head = right;
        right->link = address_xor(middle, NULL);
        
        print_data(l_head, 1);
        print_data(r_head, 2);
        puts("");
    

    return 0;
}
