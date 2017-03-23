#include <stdio.h> 
//-----explanation-----change--variable--x!
//variable External level(file) --by the pointer -->function b() and function c() !!!

void a (); 
void b (); 
void c (); 
int x = 1; // variable External level(file)

main()
{
	
int x = 5; //variable In the field of view “block” (Indoor unit of function main())
printf("variable x In the outer field of view main() = %d\n", x);

  { // the started a new field of view (Indoor unit of function main())
  int x = 7;
  printf("variable x In the inside field of view main() = %d\n",x);
  printf("----------------------\n");
  } // the finished a new field of view (Indoor unit of function main())

printf("variable x In the outer field of view main() = %d\n",x);
printf("----------------------\n");

a(); // change "block"
b(); // change "file"
c(); // change "block" and "file"
printf("----------------------\n");
//-->x modification  10+15(fun b and c)
a(); 
b(); //  -->x==25!!!modification 10+15(fun b and c)
c(); 

b();//-->x modification 250+15(fun b and c)

printf("\nvariable x in the function main() = %d\n",x);
printf("----------------------\n");

}

void a()
{
int x = 25; // changing in field of view "block"
printf("\nvariable x of function a() = %d After login in this function\n", x);
x++; // modification
printf("\nvariable x of function a() = %d before login in this function \n",x);
printf("----------------------");
}

void b()
{
printf("\nvariable External level x = %d at the entrance in function b() \n", x);
x *= 10; // variable modification in external level !
printf("\nvariable External level x = %d at the exit in function b() \n",x);
printf("----------------------");
}

void c()
{	
printf("\nvariable External level x = %d at the entrance in function c() \n",x);
x += 15; // variable modification in external level
printf("\nvariable External level x = %d  After modification in c() \n",x);
int x = 77; 
printf("\nvariable Internal level x = %d after an ad c()",x);
x--; //  variable modification in internul level
printf("\nvariable Internal level x = %d before at the exit in function c() \n",x);
printf("----------------------");
}
