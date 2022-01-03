#include <stdio.h>

void menu();
void read_news(char buffer[500], char file_path[11], int is_Only_Title);
void append_file(char* file_path, char c);
void list_readed(char* file_path);
void read_magic_numbers(char buffer_magic[10], char buffer_news[500]);
double f_func(int x);
double g_func(double f(int x), int a);

int main(){
	
	menu();
	
	return 0;
}

void menu (){
 int i,x=1; //x is for breaking the loop, it is initially 1 so the while loop continues if user says no it becomes 0 thus loop is broken 
 char choice, choice_cont,buffer[500],buffer_magic[10],file_path[11]="news/0.txt";



 	printf("**********Daily Press*************\n\n");
	printf("Today's news are listed for you:\n\n");
	read_news(buffer,"news/1.txt",1);
 	read_news(buffer,"news/2.txt",1);
 	read_news(buffer,"news/3.txt",1);
 	read_news(buffer,"news/4.txt",1);
 	printf("\n");
	
	while(x){

	printf("What do you  want to do? \n");
	printf("a-) Read a new\n");
	printf("b-) List the readed news \n");
	printf("c-) Get decrypted information from the news\n");
	scanf(" %c",&choice);
	
	switch(choice){

      	case 'a':
      			printf("Which new do you want to read?\n");
      			scanf(" %c",&file_path[5]);					//file_path is initially "news/0.txt" so the 5th char represents the new number i have used this in a lot of places
      			read_news(buffer,file_path,0);
        	break;
        case 'b':
        		list_readed("readed_news_id.txt");
        	break;
        case 'c':
        		read_magic_numbers(buffer_magic,buffer);
        	break;
        default:
        	printf("Wrong entry!\n");
        	break;
		}
		printf("Do you want to continue? Yes(y)/No(n):\n");
		scanf(" %c",&choice_cont);
		if (choice_cont=='n'){
			printf("Good Bye!\n");
			x=0;											//x becomes 0 thus the loop is broken
		}
		

 }

}

void read_news(char buffer[500], char file_path[11], int is_Only_Title){

	int i=0, counter=0,check=1, readed_news[4]={0,0,0,0};

	FILE * fpnew = fopen (file_path, "r");
	FILE * fpread = fopen ("readed_news_id.txt","r");
	
	if (is_Only_Title==1){											// if the only title is 1 the it reads first line and returns 
	 	fgets(buffer,500,fpnew);
	 	printf("Title of %c. new: %s",file_path[5],buffer);
		return;
	}

	while(!(feof(fpread))){
 		fscanf(fpread,"%d", &readed_news[i]);						//readed news are taken to an array
		i++;
	}
	


	for (i = 0; i < 4; i++){
		if(readed_news[i] == (int)file_path[5] -48 ){				//here the file is checked if readed or not if readed check becomes 0
			check=0;
		}
	}
	if (check==1){
		append_file("readed_news_id.txt",file_path[5]);				//if check is 1 that means we havent read the new so it is written to readed_news_id
	}

	if (check==0){
		printf("This new is readed. Do you want to read again? Yes(1) / No(0):\n");	//here we ask if the user wants to read again if so check becomes 1
		scanf("%d",&check);
 	}

 	if (check==1){													//the new is taken to buffer
		while(!(feof(fpnew))){
			fscanf(fpnew,"%c",&buffer[counter]);
			counter++;	
		}
		buffer[counter]='\0';										//counter is for putting \0 to the and of the buffer
		printf("%s\n",buffer);

 	} 	

 buffer[0]='\0';													//when the whole proccess is done buffer  is emptyed

}

void append_file(char* file_path, char c){
	
	FILE * fp = fopen(file_path,"a");
	fseek(fp,0,SEEK_END);
	fprintf(fp,"%c\n",c);					//the file had 2\n written to it so i designed it that  way if it only had 2 i would have write fprintf(fp,"\n%c",c);
	fclose(fp);

}

void list_readed(char* file_path){
	int new_num;
	FILE * fp = fopen(file_path, "r");

	while(1){
		fscanf(fp,"%d",&new_num);
		if ((feof(fp))){									// i have terminated the loop this way because other ways would print the last thing twice
			break;
		}
		printf("%d. new is readed\n",new_num );
	}
}

void read_magic_numbers(char buffer_magic[10], char buffer_news[500]){
	
	int counter=0,counter_magic=0;
	double sum=0;
	char file_path[11]="news/0.txt";
	printf("Which new would you like to decrypt?:");
	scanf(" %c",&file_path[5]);									// again file_path[5] is used to determine the new user wants
	FILE * fp = fopen(file_path,"r");
	
	while(!(feof(fp))){

			fscanf(fp,"%c",&buffer_news[counter]);
			
			if (buffer_news[counter-1]=='#'){					//if the '#' is found +1 char is copyed to buffer_magic	
				buffer_magic[counter_magic]=buffer_news[counter];
				counter_magic++;
			}
			counter++;
	}
	buffer_news[counter]='\0';									//this is for preventing the news from overlapsing
	counter_magic=0;											//this is reset to 0 to not declare another counter

	while(buffer_magic[counter_magic]!='\0'){
		sum+=g_func(f_func,(int)buffer_magic[counter_magic]-48); //magic numbers are typecasted and sent to g_func one by one
		counter_magic++;
	}

	printf("%s\n",buffer_news );
	switch(file_path[5]){											//used switch case to determine the secret info type

      	case '1':
      		printf("The number of tests performed=");
      		break;
        case '2':
        	printf("The number of sick people=");
        	break;
        case '3':
  			printf("The number of deaths=");
        	break;
        case '4':
       		printf("The expected number of sick people=");
        	break;        
        }
	printf("%.2lf\n\n", sum);
	buffer_news[0]='\0';										//again the buffer is emptyed to prevent overlapsing 
	sum=0;														//such as buffer sum is emptyed too

}

double f_func(int x){			
	return (x*x*x)-(x*x)+2;
}
double g_func(double f(int x), int a){
	return f(a)*f(a);
}