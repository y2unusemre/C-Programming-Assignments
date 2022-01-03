#include <stdio.h>
#include <math.h>

int isprime(int a);


int main(){
	int i,N;

	printf("Please enter an integer: ");
	scanf("%d",&N);


	for (i = 2; i < N; i++){
		if (isprime(i)==1){
			printf("%d is a prime number\n\n",i );
		}
		else
			printf("%d is not a prime number, it is dividible by %d \n\n",i, isprime(i));		// the  returned number from isprime function is the least divisor of the number

	}




	return 0;
}




int isprime(int a){

	int i;

	for (i = 2; i <= sqrt(a); i++){
		if (a%i == 0){
			return i;
		}
	}
	
	return 1;


}