#include <stdio.h>
#include <math.h>

int andop (int a, int b);
int check_binary(int x);

int main(){
	
	int a,b,check=1;
	while(check){																				// check is initially 1. if the user enters appropriate numbers it becomes 0 thus breaks the loop.
		printf("\nFirst integer:\t");
		scanf("%d",&a);
		printf("Second integer:\t");
		scanf("%d",&b);
		if (floor(log10(a))!= floor(log10(b))){ 												// for checking the length of the numbers 
			printf("Integers should have the same length, please enter two new integers.\n");
		}
		else if (check_binary(a) == 0 || check_binary(b) == 0){									//check_binary function is checking wheter the nummber is binary or not
			printf("Integers should be binary,  please enter two new integers.\n");
		}
		else{
			printf("%d AND %d = %d\n\n", a, b, andop(a,b) );
			
			check=0;
		}

	}

	return 0;
}


int andop (int a, int b){

int exp=0, retval;
float val=0;

while(a!=0){
	if ( a%10  ==  b%10 ){								// if the first digits are same then it checks if they are 1.
		if (a%10 == 1){
		val = val + pow(10,exp);						// if the digits are equal adds 10^exp , exp starting from 0 so if the numbers are 1111 1010 first it will add 10^1 then it will add 10^3 making the val 10+1000 = 1010 
		}
		
	}
	exp = exp+1;
	a=a/10;
	b=b/10;
}
	retval=val;
	return retval;

}
int check_binary(int x){

	while(x!=0){										//this loop checks all the digits if there is even one digits differrent from 1 or 0 it returns 0, if not loop ends and it returns 1.
		if (x%10 != 1 && x%10 != 0){
			return 0;
		}
		x=x/10;	
	}
	return 1;

}