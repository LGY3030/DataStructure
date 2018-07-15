#include <iostream> 

using namespace std;

int Hanoi(int n,char A,char B,char C,int &count){ 

if(n == 1){
cout<<"Move disk "<<n<<" from "<<A<<" to "<<C<<endl;
count++;

}

else{ 
Hanoi(n-1, A, C, B,count); 
cout<<"Move disk "<<n<<" from "<<A<<" to "<<C<<endl;
count++;
Hanoi(n-1, B, A, C,count); 
}
} 

int main(void){ 

int n; 
int count=0;
char A='A';
char B='B';
char C='C'; 

cin>>n; 

Hanoi(n,A,B,C,count); 


cout<<"Total steps: "<<count<<endl;


system("pause"); 
return 0; 
} 
