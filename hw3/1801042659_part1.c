#include <stdio.h>


int sum(int n, int flag);
int mult(int n, int flag);


int main(){
	int n, flag, choice;
	printf("Enter an integer :");
	scanf("%d",&n);
	
	printf("Please enter '0' for sum, '1' for multiplication\n ");
	scanf("%d",&choice);

	printf("Please enter '0' to work on even numbers, '1' to work on odd numbers\n ");
	scanf("%d",&flag);
	

if ( (flag != 0 && flag != 1) || (choice != 0 && choice != 1)){										//if the inputs are wrong the program ends as in example
	if (choice != 0 && choice != 1){													
		printf("Unsupported operation\n");
		return 0;
	}

	if (flag != 0 && flag != 1){
		printf("Invalid value for odd/even selection\n");
		return 0;
	}
}

	switch(choice){
		case 0:
			sum(n,flag);
		break;

		case 1:
			mult(n,flag);
		break;

	}

	return 0;
}



int sum(int n, int flag){

int i, sum = 0;

switch(flag){
		
		case 0:
			for (i = 1; i < n/2; ++i){								// this part is for even numbers, for loop is used to find the sum and to print the equation
				sum = sum + i*2;									
				printf("%d + ",i*2);								
			}
				sum = sum + i*2;
				printf("%d ",i*2);
				printf("= %d \n",sum);
			break;
		case 1:
			for (i = 0; i < ((n+1)/2)-1; i++){
				sum = sum + i*2 +1 ;								// this part is for odd numbers, for loop is used to find the sum and to print the equation
				printf("%d + ",i*2 +1);
			}
				sum = sum + i*2 +1 ;
				printf("%d ",i*2 +1);
				printf("= %d \n",sum);
        	break;

    }

}
int mult(int n, int flag){

int i, mult = 1;

switch(flag){
		
		case 0:
			for (i = 1; i < n/2; ++i){
				mult = mult * i*2;									// this part is for even numbers, for loop is used to find the result and to print the equation
				printf("%d * ",i*2);
			}
				mult = mult * i*2;
				printf("%d ",i*2);
				printf("= %d \n",mult);
			break;
		case 1:
			for (i = 0; i < ((n+1)/2)-1; i++){						// this part is for even numbers, for loop is used to find the result and to print the equation
				mult = mult * (i*2 +1) ;
				printf("%d * ",i*2 +1 );
			}
				mult = mult * (i*2 +1) ;
				printf("%d ",i*2 +1);
				printf("= %d \n",mult);
        	break;

    }

}