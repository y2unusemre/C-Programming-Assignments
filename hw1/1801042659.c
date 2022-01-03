#include <stdio.h>
#include <math.h>

void find_root();
void find_newtonian_root();
int find_multiple_closest(int a, int b);
void f(char * a1, char a2, char a3);
int main(){
	int a, b;
/*

printf("part 1\n\n");
	find_root();

printf("\npart 2\n\n");
	find_newtonian_root();
	
printf("\npart 3\n\n");

	printf("Please enter the first integer:");
	scanf("%d",&a);
	printf("Please enter the second integer:");
	scanf("%d",&b);
	
	find_multiple_closest(a,b);

*/
	f("1801042659",'y','e');

	return 0;



}



void f(char * a1, char a2, char a3) {
if (*a1==0) printf("\n");
else {
switch ((*a1-'0') % 3) {
case 0: printf("%c", a2); break;
case 1: printf("%c", a3); break;
default: printf("%c", *a1); break;
}
f(a1+1, a3, a2);
}
}



void find_root(){
	int a, b, c, delta, x1, x2;
	
	printf("Please Enter the first coefficient:");
	scanf("%d",&a);
	printf("Please Enter the second coefficient:");
	scanf("%d",&b);
	printf("Please Enter the third coefficient:");
	scanf("%d",&c);
	delta = (b*b)-4*a*c;

	if (delta>0){
		x1= (-b + sqrt(delta)) / (2*a);
		x2= (-b - sqrt(delta)) / (2*a);

		printf("Your equation %dx^2  %+dx  %+d have real roots {%d,%d}.\n",a,b,c,x1,x2);

	}
	else if (delta==0){
		x1= (-b) / (2*a);

		printf("Your equation %dx^2 + %dx + %d have one real double root {%d}.\n",a,b,c,x1);
	}
	else {
		printf("Your equation %dx^2 + %dx + %d does not have any real roots.\n",a,b,c);
	
	}

}


void find_newtonian_root(){

	int a, b, c;
	double  init , x1, x2, x3, x4, x5;
	
	printf("Please enter the first coefficient:");
	scanf("%d",&a);
	printf("Please enter the second coefficient:");
	scanf("%d",&b);
	printf("Please enter the third coefficient:");
	scanf("%d",&c);
	printf("Please enter the initial:");
	scanf("%lf",&init);

	
	x1 = init - ( ( init*init*a ) + (b*init) + c) / ( 2*init*a + b);						//calculating all the iterations 
	x2 = x1 - ( ( a*x1*x1 ) + (b*x1) + c) / ( a*2*x1 + b);
	x3 = x2 - ( ( a*x2*x2 ) + (b*x2) + c) / ( a*2*x2 + b);
	x4 = x3 - ( ( a*x3*x3 ) + (b*x3) + c) / ( a*2*x3 + b);
	x5 = x4 - ( ( a*x4*x4 ) + (b*x4) + c) / ( a*2*x4 + b);
	
	printf("\nYour equation is %dx^2  %+dx  %+d and iterations are.\n\n",a,b,c);
	
	printf("Step\t\tx\t\tf(x)\t\tDifference\n\n");

	printf("x1\t\t%.4f\t\t%.4f\t\t%.4f\n\n" ,x1 , ( a*x1*x1 ) + (b*x1) + c , x1-x5);				//printing the steps 
	printf("x2\t\t%.4f\t\t%.4f\t\t%.4f\n\n" ,x2 , ( a*x2*x2 ) + (b*x2) + c , x2-x5);
	printf("x3\t\t%.4f\t\t%.4f\t\t%.4f\n\n" ,x3 , ( a*x3*x3 ) + (b*x3) + c , x3-x5);
	printf("x4\t\t%.4f\t\t%.4f\t\t%.4f\n\n" ,x4 , ( a*x4*x4 ) + (b*x4) + c , x4-x5);
	printf("x5\t\t%.4f\t\t%.4f\t\t%.4f\n\n" ,x5 , ( a*x5*x5 ) + (b*x5) + c , x5-x5);


}



                                                                                  
int find_multiple_closest(int a, int b){

	int res;

	res = (a/b)*b;

	if (a-res>=res+b-a){
		res += b;
	}

	if (res==a){
		printf("Closest number to  %d that is multiple of  %d is itself.\n",a,b);	
	}
	else
		printf("Closest number to  %d that is multiple of  %d is %d. \n",a,b,res);

	return res;




}