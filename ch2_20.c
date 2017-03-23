#include <stdio.h>
//Attention! heavy code!
void input_Dimension_arr(int *,int *);
void type_arr(int m,int arr[][m],int N,int M);
void print_arr(int m,int arr[][m],int N,int M);
void input_row_col(int*, int*,int *,int *);
int inspection(int N,int M);
void exchange(int*,int*,int m,int arr[][m],int N,int M);
void crazy_replacement(int*, int*,int m, int arr[][m],int N,int M);

main()
{
    int N,M;
    int m;
        input_Dimension_arr(&N,&M);
    int row,col;
     m=M;
    int flag=0; //(1)if the same
    int arr[N][M];

type_arr(m,arr,N,M);
print_arr(m,arr,N,M);
flag=inspection(N,M);
input_row_col(&row,&col,&N,&M);

 if (flag) exchange(&row,&col,m,arr,N,M);
     else crazy_replacement(&row,&col,m,arr,N,M);

print_arr(m,arr,N,M);
}
//----------type_arr-------------------
void type_arr(int m, int arr[][m], int N, int M)
{
int i,j,w;
for (i=0;i<N;++i)
    {
        for (j=0;j<M;++j)
        {
            w=rand()%100;
            arr[i][j]=w;
        }
    }
}

//----------------inspection----------
int inspection(int N,int M)
{
    int i,j;
int check_row=0,check_col=0;
for (i=0;i<N;++i)
    {
           check_row++;
        for (j=0;j<M;++j)
        {
           check_col++;
        }
    }

    if (check_row==check_col)
    {
        printf("the number of columns and rows of the same\n");
        return 1;
    }
    else
    {
        printf("the number of columns and rows are sundry\n");
        return 0;
    }
}
//---------input_row_col----------------
void input_row_col(int *r, int *c,int *n,int *m)
{
    int f;
    do{
        f=0;
        printf("for to replace\n");
printf("enter desired number row: \n");
scanf("%d",&*r);

printf("enter desired number column: \n");
scanf("%d",&*c);

  if ( (*r<=*n)&&(*c<=*m) )
   {
      if (*r<*c) printf("Row is larger than column\n");
      else printf("Column is larger than row \n");
      f=0;
   }
       else {printf("wrong input!!! please re-enter!\n");f=1;}

      }while (f);

}
//-----exchange---------------------------
void exchange(int *row, int *col, int m, int arr[][m], int N, int M)
{
    printf("if the same:\n");
    printf(" row[%d] change  by  column[%d]:\n",*row,*col);
int r=*row;
int c=*col;
int i,j;
int tmp;
int arr2[N][M];

tmp=arr[r][c];
for (i=0;i<N;++i)
{
    for (j=0;j<M;++j)
    {
        if(i==r)
        {

            arr2[i][c]=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=arr2[i][c];
        }
    }
}
arr[r][c]=tmp;
printf("\n");

}

//------------crazy_replacement-------------
void crazy_replacement(int *row, int *col, int m, int arr[][m], int N, int M)
{
    printf("if the sundry:\n");
    printf(" row[%d] change  by  column[%d]:\n",*row,*col);
    int r,c;
    if (row>col)
    {
     r=*row;c=*col;
    } else
         {
          c=*row;r=*col;
         }                //It does not work with a certain dimension!

int i,j;
int tmp;
int arr2[N][M];
tmp=arr[r][c];
for (i=0;i<N;++i)
{
    for (j=0;j<M;++j)
    {
        if(i==r)
        {
            arr2[i][c]=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=arr2[i][c];
        }
    }
}
arr2[r][c]=tmp;

printf("\n");
}
//---------print_arr-----------------
void print_arr(int m, int arr[][m], int N, int M)
{
int i,j;
for (i=0;i<N;++i)
    {
        printf("\n");
        for (j=0;j<M;++j)
        {
           printf("%3i",arr[i][j]);
        }
    }
printf("\n");
}

void input_Dimension_arr(int *n,int *m)
{
    int f;
    do{
            f=0;
printf("Enter the desired array size :\n");

printf("input quantity row from 0 to 100: \n");
scanf("%d",&*n);
//it's impossible to 100
printf("input quantity column from 0 to 100: \n");
scanf("%d",&*m);

if (   ( (*n>0)&&(*m>0) ) &&  ( (*n<=100)&&(*m<=100) )   )f=0;
     else {printf("wrong input!!! please re-enter!\n");f=1;}
    }while (f);
}
