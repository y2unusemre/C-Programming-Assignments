#include <stdio.h>



int main(){

	int choice1, choice2; 											// choice1 is for the currency user has , choice2 is for the currency user wants to learn

	double amount;
	
	printf("***** Welcome to ABC Exchange Office *****\n");


	printf("Enter your amount:\n");
		scanf("%lf",&amount);
	
	printf("Please select your currency:\n");
	printf("1. Turkish Lira\n");
	printf("2. Euro\n");		
	printf("3. Dollar\n\n");
	scanf("%d",&choice1);
	printf("\n");


	switch(choice1){
		case 1:
			printf("You have %f Turkish Liras\n",amount);
			break;
		case 2:
			printf("You have %f Euros\n",amount);
			break;
		case 3:
			printf("You have %f Dollars\n",amount);
			break;
		default:
			printf("Your selection is invalid!\n");
		}
	

	printf("Choose which currency you want to convert\n");
	scanf("%d",&choice2);
	printf("\n");

	switch(choice2){
		case 1:
			if (choice1==1){
			printf("You have %lf Turkish Liras\n",amount);	
			}
			if (choice1==2){
			printf("You have %lf Turkish Liras\n",amount*6.69);	
			}
			if (choice1==3){
			printf("You have %lf Turkish Liras\n",amount*6.14);	
			}
			break;
		case 2:
			if (choice1==1){
			printf("You have %lf Euros\n",amount/6.69);	
			}
			if (choice1==2){
			printf("You have %lf Euros\n",amount);	
			}
			if (choice1==3){
			printf("You have %lf Euros\n",amount/1.09);	
			}
			break;
		case 3:
			if (choice1==1){
			printf("You have %lf Dollars\n",amount/6.14);	
			}
			if (choice1==2){
			printf("You have %lf Dollars\n",amount*1.09);	
			}
			if (choice1==3){
			printf("You have %lf Dollars\n",amount);	
			}
			break;
		default:
			printf("Your selection is invalid!\n");
						
		}		



	return 0;
}