#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ROW 20																		//ROW and COL is hardcoded so the mapsize can be changed easily
#define COL 20
int insert_word (char map[ROW][COL] ,char word[13]); 								//inserting the word to the map
void insert_random(char map[ROW][COL]);												//filling other places with random chars
void print_map(char map[ROW][COL]);													//printing map
int check_word(char map[ROW][COL],char words[10][13],char input[16],int dir[10]);	//checking if the user's input is true or not

int main(){
	
	int i,j,temp,counter=0,counterprev,cntrl=1,dir[10],words_found=0;				
	char map[ROW][COL];
	char words[10][13],buffer[13],input[16];
	FILE *fp = fopen ("words.txt", "r");	

 	srand(time(0));

 	for (i = 0; i < ROW; i++){									//filling the map with dots for preventing segmentation fault
		for (j = 0; j < COL; j++){
			map[i][j]='.';
		}
 	}

 	for (i = 0; i < 10; i++){
		temp=rand()%10+1;										//here i chose the words randomly with algorithm such as: first randomly 5 is generated 5th word is taken
		counterprev=counter;									//than randomly a number between 1-10 is generated again and added to 5 this way a chosen word will not be chosen again
		counter+=temp;											
		for (j = counterprev; j < counter; j++){
			fgets(buffer,13,fp);
		}
		strcpy(words[i], buffer);								
	}	

	for (i = 0; i < 10; i++){
		dir[i]=insert_word(map,words[i]);
	}
 
	insert_random(map);											//you can turn off random chars by taking this line to a commend line for easier understanding

 	while(1){
		print_map(map);
		printf("WORDS:\n");
		for (i = 0; i < 10; i++){
			printf("%s",words[i]);
		}	

		printf("\nPlease enter the coordinate and the word(enter exit if you want to exit):");
		gets(input);

		if (input[1]=='x'){ // normally user should the second char a number if it is not an integer and equal to x that means user most probably entered exit
			break;
		}
		words_found += check_word(map,words,input,dir);	//words_found hold the number of found words if it becomes 10 that means user has found all of the words.
		
		if (words_found==10){
			break;
		}


		input[0]='\0';
	}


	return 0;
}

int insert_word (char map[ROW][COL],char word[13]){

	int i=0,length,dir,orgrow,orgcol,check=0;

	length=strlen(word)-1;

	while(check==0){
		dir=rand()%8+1;										//direction and origin coordinates are randomly taken
		orgrow=rand()%ROW;									//all if operations below checks if the word can be placed there if not while loop continues and tries again until finds a place
		orgcol=rand()%COL;
	
		if (dir==1){
			if (orgcol+length<COL){
				check=1;
			}

		}
		else if (dir==2){
			if (orgcol-length>0){
				check=1;
			}
		}
		else if (dir==3){
			if (orgrow+length<ROW){
				check=1;
			}
		}
		else if (dir==4){
			if (orgrow-length>0){
				check=1;
			}
		}
		else if (dir==5){
			if (orgcol+length< COL && orgrow+length< ROW){
				check=1;
			}
		}	
		else if (dir==6){
			if (orgcol-length>0 && orgrow-length>0){
				check=1;
			}
		}	
		else if (dir==7){
			if (orgcol-length>0 && orgrow+length<ROW){
				check=1;
			}
		}	
		else if (dir==8){
			if (orgcol+length<COL && orgrow-length>0){
				check=1;
			}
		}	

		for (i = 0; i < length; i++){													//if the word accrosed another word it again finds a new place
			if (dir==1){
				if (map[orgrow][orgcol+i]!='.' && map[orgrow][orgcol+i]!=word[i] ){
					check=0;
				}
			}
			if (dir==2){
				if (map[orgrow][orgcol-i]!='.' && map[orgrow][orgcol-i]!=word[i] ){
					check=0;
				}
			}
			if (dir==3){
				if (map[orgrow+i][orgcol]!='.' && map[orgrow+i][orgcol]!=word[i] ){
					check=0;
				}
			}
			if (dir==4){
				if (map[orgrow-i][orgcol]!='.' && map[orgrow-i][orgcol]!=word[i] ){
					check=0;
				}
			}
			if (dir==5){
				if (map[orgrow+i][orgcol+i]!='.' && map[orgrow+i][orgcol+i]!=word[i] ){
					check=0;
				}
			}
			if (dir==6){
				if (map[orgrow-i][orgcol-i]!='.' && map[orgrow-i][orgcol-i]!=word[i] ){
					check=0;
				}
			}
			if (dir==7){
				if (map[orgrow+i][orgcol-i]!='.' && map[orgrow+i][orgcol-i]!=word[i] ){
					check=0;
				}
			}
			if (dir==8){
				if (map[orgrow-i][orgcol+i]!='.' && map[orgrow-i][orgcol+i]!=word[i] ){
					check=0;
				}
			}

		}

	}

		
	i=0;

	 //if program comes here then it means it  found an available place for the word and places it

		if (dir==1){							
			while(word[i]!='\n'){
				map[orgrow][orgcol+i]=word[i];
				i++;
			}
		}
		if (dir==2){
			while(word[i]!='\n'){
				map[orgrow][orgcol-i]=word[i];
				i++;
			}
		}
		if (dir==3){
			while(word[i]!='\n'){
				map[orgrow+i][orgcol]=word[i];
				i++;
			}
		}
		if (dir==4){
			while(word[i]!='\n'){
				map[orgrow-i][orgcol]=word[i];
				i++;
			}
		}
		if (dir==5){
			while(word[i]!='\n'){
				map[orgrow+i][orgcol+i]=word[i];
				i++;
			}
		}
		if (dir==6){
			while(word[i]!='\n'){
				map[orgrow-i][orgcol-i]=word[i];
				i++;
			}
		}
		if (dir==7){
			while(word[i]!='\n'){
				map[orgrow+i][orgcol-i]=word[i];
				i++;
			}
		}
		if (dir==8){
			while(word[i]!='\n'){
				map[orgrow-i][orgcol+i]=word[i];
				i++;
			}
		}

		return dir;								//returns direction in order to make the use it in gameplay
}

void insert_random(char map[ROW][COL]){
	int i,j;
	for (i = 0; i < ROW; i++){
		for (j = 0; j < COL; j++){
			if (map[i][j]=='.'){				//random chars inserted instead of dots
				map[i][j]=(rand()%26)+97;
			}
		}
	}		
}

void print_map(char map[ROW][COL]){
	int i,j;
	char row='A';

	printf("\n\t");
	for ( i = 0; i < 20; i++){
		if (i<10){								//preventing slipping of column numbers
		printf("%d  ",i );
		}
		else
			printf("%d ",i );
	}
	printf("\n\n");
	for (i = 0; i < 20; i++){
		printf("%c\t",row++);
		for (j = 0; j < 20; j++){
			printf("%c  ",map[i][j]);
		}
		printf("\n\n");
	}
	printf("\n");

}

int check_word(char map[ROW][COL],char words[10][13],char input[16],int dir[10]){
	char row,word[13];
	int rownum, colnum,word_num,exist=0,i;

	sscanf( input, "%c%d %s",&row, &colnum,word );				// breaking down the input so it becomes usable

	rownum=(int)row-65;
	strncat(word, "\n", 2); 									// adding \n to word  string in order to compare later because fgets has taken the words with end line character
	
	for (i = 0; i < 10; i++){
		if (strcmp(word,words[i])==0){							//if word user entered exist it continues else it prints error.
			word_num=i;	
			exist=1;
		}
	}

	if (exist){
		if (map[rownum][colnum]!=word[0]){						//checks the first letter
				return 0;
		}
		else{

			for (i = 0; i < strlen(word)-1; i++){				//-1 is because of  end line character

				if (dir[word_num]==1){
					if (map[rownum][colnum+i]==word[i]){		//according to direction loop continues to uppercase the letters
						map[rownum][colnum+i]-=32;
					}
				}
				else if (dir[word_num]==2){
					if (map[rownum][colnum-i]==word[i]){
						map[rownum][colnum-i]-=32;
					}
				}
				else if (dir[word_num]==3){
					if (map[rownum+i][colnum]==word[i]){
						map[rownum+i][colnum]-=32;
					}
				}
				else if (dir[word_num]==4){
					if (map[rownum-i][colnum]==word[i]){
						map[rownum-i][colnum]-=32;
					}
				}
				else if (dir[word_num]==5){
					if (map[rownum+i][colnum+i]==word[i]){
						map[rownum+i][colnum+i]-=32;
					}
				}
				else if (dir[word_num]==6){
					if (map[rownum-i][colnum-i]==word[i]){
						map[rownum-i][colnum-i]-=32;
					}
				}
				else if (dir[word_num]==7){
					if (map[rownum+i][colnum-i]==word[i]){
						map[rownum+i][colnum-i]-=32;
					}
				}
				else if (dir[word_num]==8){
					if (map[rownum-i][colnum+i]==word[i]){
						map[rownum-i][colnum+i]-=32;
					}
				}
				else{
				printf("Wrong coordinates!\n");
				return 0;			
				}
			}

		  
		}
		
	}
	else{
		printf("This word does not exist!\n");
	}
	return 1;
}