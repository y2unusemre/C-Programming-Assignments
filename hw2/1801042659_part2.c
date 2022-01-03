#include <stdio.h>
#include <math.h>


int number_length(int number);
int find_digit(int number, int index);

int main(){
	
	int number, index;
	printf("Enter a number (maximum 6 digits)\n");
	scanf("%d",&number);
	printf("Your number has %d digits\n\n", number_length(number));  
	printf("When your number is written 100 times next to each other, which digit of this number would you like to see? :\n");
	scanf("%d",&index);
	printf("\n");
	find_digit(number, index);



	return 0;
}


int number_length(int number){



	return log10(number)+1;


}
int find_digit(int number, int index){


	int digit,result;	
	digit = number_length(number);

	if (index > number_length(number)*100){					// if the index is larger than the long number sequence 
		printf("Error! The number is not that long.\n");
		return 0;
	}

	if (index % digit == 0)	{
		result = number % 10;
	}
	else {
		result =  number / pow(10,digit-(index%digit)); 	// for example if the number is 123456 and required digit is 3 result will be equal to 123 in this  equation
		result = result % 10; 								// and here it will be equal to 3
	}

	printf("%d.th digit of the big number sequence is : %d\n",index , result);
	return result;


}