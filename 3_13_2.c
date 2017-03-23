//sorry for my english:)
#include <stdio.h>
#include <conio.h>

void Div(int *,int,int *,int *);
int NSymbol(int *,int,int);
int main ()
{
	int arr[8]={0};
	
	int N;//multi-digit number
	int f,f1;
	int FLAG=0;//If something is wrong:)
	int K;//the number of the numeric digit
	int Q=0;//amount of digits
	int V=0;//Value of number in order
	
	do
	{ f=0;
		printf("Enter many numerical value (from 2 to 8 numeric digit):...");
		scanf("%d",&N);
		getchar();
		if (N<=0)  {f=1;printf("Input correct number!!! Enter positive number please.\n");}
		   else f=0;		
	}while(f);
	
	Div(arr,N,&Q,&FLAG);
	if (FLAG) {printf("GREATER BOOOOOM!\n");printf("It was necessary to enter correctly!\n");return;}
	
	//printf("the amount of digits=%d\n",Q);
	
	 do
	 { f1=0;
	    printf("Enter the number of the numeric digit.\nIf you enter zero--> prints out all the numbers\n...");
		scanf("%d",&K);
		if (K>Q) {f1=1;printf("Something went wrong!!!\nCorrect the mistake and try again!\n");
		        printf("Advice:");
				printf("Enter a number less than the number of digits of the specified multi-digit number");}
		   else {f1=0;V=NSymbol(arr,K,Q);printf("Value of number %d in order = %d",K,V);}	
	 }while(f1);
	 
getch();		
}

void Div(int *arr,int N,int *Q,int *FLAG)
{
  int tmp=0;
  int i=0;
 
   arr[i]=N%10;++*Q;//Write the first digit and ñount the amount of digits
   tmp=N/10;
   i++;
   
   while(tmp>9)
   {
   	arr[i]=tmp%10;++*Q;//Record digits of number to an array and ñount the amount of digits
   	tmp=tmp/10;
   	i++;
   }
   arr[i]=tmp;++*Q;//Write the last digit and ñount the amount of digits
   
    if(N<9) {printf("Invalid input!");*FLAG=1;return; }        	          
    
    if( (*Q<=1)||(*Q>8) ) {printf("Invalid input!Invalid input!Invalid input!BOOOM!");*FLAG=1;return; }
 //print array
 /*
 i=0;
 while(i<*Q)
  {	
 printf("arr[%d]=%d\n",i,arr[i]);  
 i++;
  }  
  */ 
    
}

int NSymbol(int *arr,int K,int Q)
{
	int res;
	int tmp;
	int i;
	int L=0;//length of array
	L=Q;//length of array(amount of digits)
    for (i=0;i<L/2;i++)
         {//Swapping
           tmp=arr[i];
           arr[i]=arr[L-i-1];
           arr[L-1-i]=tmp;
          }
    res=arr[K-1];
    return res;
 } 
