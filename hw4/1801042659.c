#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void decrypt_and_print (char* file_path);						//part1
char decrypt_numbers (int number);
void deep_decrypt_and_print (char* file_path);					//part2
void track_machine ();											//part3
void refresh_position (int *X, int *Y, double *D, double *R);
void encrypt_messages (char* file_path);						//part4
void menu();													//part5


int main(){

	srand(time(0));
	menu();
	return 0;
}

void decrypt_and_print (char* file_path){						

	char number;
	FILE * fp = fopen (file_path, "r");

	while(!(feof(fp))){
		fscanf(fp,"%c",&number);								// this function reads the file char by char 
		printf("%c",decrypt_numbers( (int) number - 48 ) );		// turns them into integers and sends them tı decrypt_numbers function
	}

}

char decrypt_numbers (int number){								//returns the character that represents the number


	switch(number){

		case 0:
			return ' ';
		case 1:
			return '-';
        case 2:
			return '_';
        case 3:
        	return '|';
        case 4:
       		return '/';
        case 5:
        	return '\\';
        case 6:
        	return 'O';

		}
		return '\n';

}

void deep_decrypt_and_print (char* file_path){

	int i,value,sum=0,j,inp_c=0;
	char number;
	FILE * fp = fopen (file_path, "r");


    
    fscanf(fp,"%c",&number);
	while(!(feof(fp))){
 		

		for (j = 0; j < 3; j++){   

				inp_c++;													//this integer helps how many inputs are taken from the file later it will help us

				if (number != '\n'){										//if the pointer is not at the end of the line this part takes 3 integers and add them to sum
					value = (int) number;
					value = value -48;
					sum = sum + value;
                    if(j==2) {												//if j is 2 that means we have already taken 3 inputs so decrypt_numbers func is called
                      printf("%c",decrypt_numbers( sum%7 ));
                      fseek(fp,-2,SEEK_CUR);
                    }
				}
				else{														//if the pointer is at the end of a line 

					j=3;
                  	if(inp_c==3) {											//in this part inp_c is checked to figure out how many inputs are read by now. fseek is used togo back according to that
                    	printf("%c",decrypt_numbers( sum%7 ));
                    	fseek(fp,-2,SEEK_CUR);
                    }
					else if (inp_c==2){
				        printf("%c",decrypt_numbers( sum%7 ));
						fseek(fp,-1,SEEK_CUR);
					}
					else if (inp_c==1){
                        printf("\n");	
					}

					
				
				}

                               fscanf(fp,"%c",&number);

                
		}
                         sum = 0;
			inp_c=0;
		
	}
	

}


void track_machine (){

	int i,j,X=0,Y=0,counter=0;
	double D,R;
	char command = 'R';			// initially R to prevent junk value
          
        
 while(command != 'E'){			// while command isnt E loop continues

    if(counter==0) {
		for (i = 1; i <= 11; i++){			// these 2 for loops is for printing initially
			for (j = 1; j <= 11; j++){
					
				if (i==6 && j==6){
					printf("O");
				}
				else if (i==X && j==Y){
					printf("E");
				}
				else{
					printf(".");
				}
				printf("\t");
			}	
			printf("\n");
		}
		counter++;			// counter is iterated so it doesn't print 2 times the initial 
		       
    }
       

    else  if(command=='R') {
              
		refresh_position(&X,&Y,&D,&R);					//sending addresses of values

	    for (i = 1; i <= 11; i++){

			for (j = 1; j <= 11; j++){
			
				if (i==6 && j==6){
					printf("O");						//printing our place
				
					if (i==X && j==Y){					// if enemy and we are at the same place it prints OE
						printf("E");
					}
				}
				else if (i==X && j==Y){
					printf("E");						//printing enemy's place
				}

				else{
					printf(".");						//printing anywhere else
				}
				printf("\t");
			}	
		printf("\n");
		}
        printf("X position:%d Y position:%d Displacement:%.2lf Distance to our camp:%.2lf\n",X,Y,D,R);
	}

        else {
           printf("Please enter again\n\n");
        }
       
    printf("Command waiting ...:");
    scanf(" %c",&command);


	}
	

}


void refresh_position (int *X, int *Y, double *D, double *R){

	int latestX,latestY;

	latestX = *X;					//last coorddinates are saved to calculate the displacement
	latestY = *Y; 
 
	 *X = rand() %11 +1; 			//new location is randomly generated +1 is for preventing it to be out of map
	 *Y = rand() %11 +1; 

        

         *D= sqrt( ((*X-latestX)*(*X-latestX)) + ((*Y-latestY)*(*Y-latestY)) );		//displacement and distance are calculated and stored
         *R= sqrt( ((*X-6) * (*X-6)) + ((*Y-6) * (*Y-6)) );
   }       









void encrypt_messages (char* file_path){


	char input;
	FILE * fip = fopen (file_path, "r");
	FILE * fop = fopen ("encrypted_p4.img", "w");
	while(!(feof(fip))){
		fscanf(fip,"%c",&input);
		switch(input){

      	case ' ':
      	    fprintf(fop, "%d", 0);
      	 	break;
        case '-':
	     	fprintf(fop, "%d", 1);
         	break;
        case '_':
    	 	fprintf(fop, "%d", 2);
         	break;
        case '|':
         	fprintf(fop, "%d", 3);
         	break;
        case '/':
         	fprintf(fop, "%d", 4);
         	break;
        case '\\':
         	fprintf(fop, "%d", 5);        
         	break;
        case 'o':
         	fprintf(fop, "%d", 6);
         	break;
        default:
        	printf("Wrong entry please try again!\n");
		}


	}
}

void menu (){
 int choice,x=1; //x is for making 5th option it is initially 1 so the while loop continues if user choses 5 it becomes 0 thus loop is broken 



	while(x){

	printf("1-) decrypt and print encrypted_p1.img \n");
	printf("2-) decrypt and print encrypted_p2.img \n");
	printf("3-) Switch on the tracking machine \n");
	printf("4-) Encrypt the message\n");
	printf("5-) Switch off\n\n");
	printf("Please make your choice:\n");
	scanf("%d",&choice);
	
	switch(choice){

      	case 1:
      	decrypt_and_print("encrypted_p1.img");
        	break;
        case 2:
        deep_decrypt_and_print("encrypted_p2.img");
        	break;
        case 3:
        track_machine();
        	break;
        case 4:
        //encrypt_messages("decrypted_p4.img");
        	printf("\nThis part is not working properly\n\n");
        	break;
        case 5:
			x=0;        	
        	break;
        default:
        	printf("Wrong entry please try again!\n");
        	break;
		}
}

}