#include <stdio.h>
#define MAX 500

void generate_hofstadters_sequence (int *arr, int n);
int find_max (int arr[], int index, int max_value);
int sum_array (int arr[]);
double std_array (int arr[], double *mean, int n, int index);
void menu_part1();
void menu();

char* remove_duplicates (char* str);

int main(){

	menu();
	
	//char *str="Thxiiiiiisssss";
	
	//str=remove_duplicates(str);
	//	printf("%s\n", str); 

	return 0;
}

void generate_hofstadters_sequence (int *arr, int n){
	

	if (n==0){
		arr[0]=1;
		return;
	}
	if(n==1){
		arr[0]=1;
		arr[1]=1;
		return;
	}else{
		generate_hofstadters_sequence(arr,n-1);
		arr[n]=arr[n-arr[n-1]]+arr[n-arr[n-2]];
		return;
	}
}
int find_max (int arr[], int index, int max_value){

	if (arr[index]==0 || index==MAX){
		return max_value;
	}
	else{
		max_value=arr[index];
		return find_max(arr,index+1,max_value);
	}
}
int sum_array (int arr[]){
	int sum=0,index;

	if (*arr==0 || arr==NULL){
		return sum;
	}
	else{
		sum=*arr;
		return sum+sum_array(arr+1);
	}

}
double std_array (int arr[], double *mean, int n, int index){

}


char* remove_duplicates (char* str){
	int i=0;
	if (str[0]=='\0'){
		return str;
	}
	if (str[0]==str[1]){
		while(str[i]!='\0'){
			str[i]=str[i+1];
			i++;
		}
		str=remove_duplicates(str);

	}
	str= remove_duplicates(str+1); 
	printf(".\n");

}
void menu_part1(){
	int x=1,choice,hofsQ[MAX]={0},i,n;
	while(x){ //x is 1 so the loop contiunes until user enters 8


		printf("\nPlease make your choice\n");
		printf("-----------------------\n");
		printf("1: Fill Array\n2: Find biggest number\n3: Calculate sum\n4: Calculate Standard deviation\n5: Exit\n\n\n");
		scanf("%d",&choice);

		switch (choice)
	    {
			
			case 1:
				printf("Please enter a number for n elements: ");
				scanf("%d",&n);
				generate_hofstadters_sequence(hofsQ,n-1);
				for (i = n ; i < MAX; i++){
					hofsQ[i]=0;
				}
				break;
			case 2:
				printf("Biggest number is: %d\n",find_max(hofsQ,0,-1) );
				break;
			case 3:
				printf("Sum is : %d\n",sum_array(hofsQ) );
				break;
			case 4:
			
				break;
			case 5:
				x=0;						//here x becomes 0 and loop ends
				break;
	        default:
				printf("TRY AGAIN.\n");
	    }
	}

}
void menu(){
	int x=1,choice;

	while(x){ //x is 1 so the loop contiunes until user enters 8


		printf("\nWelcome to Homework 8, please choose one of the parts to continue\n");
		printf("---------------------------------------------\n");
		printf("1: Execute part 1\n2: Execute part 2\n3: Execute part 3\n4: Exit\n\n\n");
		scanf("%d",&choice);

		switch (choice)
	    {
			
			case 1:
				menu_part1();
				break;
			case 2:
				printf("part 2 is not done\n");
				break;
			case 3:
				printf("part 3 is not working\n");
				break;
			case 4:
				x=0;						//here x becomes 0 and loop ends
				break;
	        default:
				printf("TRY AGAIN.\n");
	    }
	}
}