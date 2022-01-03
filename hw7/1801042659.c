#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_GAME 2000					//max values can be changed here
#define MAX_GENRE 12
#define MAX_PLATFORM 10
void list_genres(char genres [MAX_GENRE][20]);
void list_platforms(char platforms [MAX_PLATFORM][20]);
void game_thru_years(char nofgame[MAX_GAME][100], float info[MAX_GAME][7]);
void all_info(char nofgame[MAX_GAME][100],char genres[MAX_GENRE][20],char platforms[MAX_PLATFORM][20],float info [MAX_GAME][7]);
void avrg_score(float info[MAX_GAME][7]);
void geo_info(char nofgame[MAX_GAME][100], float info[MAX_GAME][7]);
void freq_genre(char genres[MAX_GENRE][20], float info[MAX_GAME][7]);
void freq_platform(char platforms[MAX_PLATFORM][20], float info[MAX_GAME][7]);

int main(){

	int i,k,x=1,choice,genre_count=0,platform_count=0,exist;
	char nofgame[MAX_GAME][100],buffer[200],genres[MAX_GENRE][20],platforms[MAX_PLATFORM][20],temp_genre[20],temp_platform[20],temp_year[5],temp_na[6],temp_eu[6],temp_glob[6],temp_score[6];
	char * end;
	float info[MAX_GAME][7];
	FILE * fp = fopen("Video_Games.txt","r");
	
	fgets (buffer, 200, fp);// this one is to avoid the first line

	for (k = 0; k < MAX_GAME; k++){

		fgets (buffer, 200, fp);	//gets a line and sscanf divides them into parts
		sscanf(buffer,"%100[^,],%20[^,],%20[^,],%5[^,],%5[^,],%5[^,],%5[^,],%5[^,]",nofgame[k],temp_genre,temp_platform,temp_year,temp_na,temp_eu,temp_glob,temp_score);// 0 yerine k gelecek
		
		exist=0;
			for (i = 0; i < MAX_GENRE; i++){
				if (strcmp(temp_genre,genres[i])==0){		//if genre already exist it stops and makes exist integer 1. 
					exist=1;
					break;
				}
				else if(genres[i][0]=='\0'){
					break;
				}
			}
			if (exist){
				info[k][0]=i;								//if exist it changes to info to i value which represents the number 
			}
			else{
				strcpy(genres[i], temp_genre);				//if doesnt it copies to the genres array and changes the info
				info[k][0]=i;		
			}

		exist=0;
			for (i = 0; i < MAX_PLATFORM; i++){				//same procedure as above is used for platforms too
				if (strcmp(temp_platform,platforms[i])==0){
					exist=1;
					break;
				}
				else if(platforms[i][0]=='\0'){
					break;
				}
			}
			if (exist){
				info[k][1]=i;
			}
			else{
				strcpy(platforms[i], temp_platform);
				info[k][1]=i;		
			}
			info[k][2] = strtod( temp_year, &end );			//then the rest of the info table  is filled 
			info[k][3] = strtod( temp_na, &end );
			info[k][4] = strtod( temp_eu, &end );
			info[k][5] = strtod( temp_glob, &end );
			
			if (end[0]=='n'){								//here if global_sales not available it attaches -1 to use it later
				info[k][5]=-1.0;
			}
			info[k][6] = strtod( temp_score, &end );
			
	}

	while(x){ //x is 1 so the loop contiunes until user enters 8


		printf("\n\n0: List of the Genres\n1: List of the Platforms\n2: List of the Games Through the Years\n3: All Information of a Single Game\n");
		printf("4: Average of the User Scores\n5: Georographical Information of a Single Game\n6: Frequency of the Genres\n7: Frequency of the Platforms\n8: Exit\n\n\n");
		printf("Please select an operation:");
		scanf("%d",&choice);

		switch (choice)
	    {
			case 0:
				list_genres(genres);
				break;
			case 1:
				list_platforms(platforms);
				break;
			case 2:
				game_thru_years(nofgame,info);
				break;
			case 3:
				all_info(nofgame,genres,platforms,info);
				break;
			case 4:
			 	avrg_score(info);
				break;
			case 5:
				geo_info(nofgame,info);
				break;
			case 6:
				freq_genre(genres,info);
				break;
			case 7:
				freq_platform(platforms,info);
				break;
			case 8:
				x=0;						//here x becomes 0 and loop ends
				break;
	        default:
				printf("TRY AGAIN.\n");
	    }
	}

	return 0;
}

void list_genres(char genres [MAX_GENRE][20]){		//listing the genres
	
	int i;
	for (i = 0; i < MAX_GENRE; i++){
		printf("%s\n",genres[i]);
	}
	printf("\n\n");
}
void list_platforms(char platforms [MAX_PLATFORM][20]){	// listing the platforms
	int i;
	for (i = 0; i < MAX_PLATFORM; i++){
		printf("%s\n",platforms[i]);
	}
	printf("\n\n");
}
void game_thru_years(char nofgame[MAX_GAME][100], float info[MAX_GAME][7]){
	int i,year,choice,check=1;

	while(check){							//check is initially 1 if there is no game according to the inputs it contiunues
		printf("Enter a year:\n");
		scanf("%d",&year);
		printf("Until(0) or Since(1) %d:\n",year );
		scanf("%d",&choice);
		
		if (choice==1){ 								
			for (i = 0; i < MAX_GAME; i++){
				if (info[i][2]>year){		// all games are checked if even one of  it is printed check becomes 0 thus loop ends
					printf("%s\n",nofgame[i] );
					check=0;
				}
			}
		}
		else if(choice==0){
			for (i = 0; i < MAX_GAME; i++){
				if (info[i][2]<year){
					printf("%s\n",nofgame[i] );
					check=0;
				}
			}	
		}
		if (check==1){
			printf("TRY AGAIN.\n");
		}
	}	
	printf("\n\n");
}
void all_info(char nofgame[MAX_GAME][100],char genres[MAX_GENRE][20],char platforms[MAX_PLATFORM][20],float info [MAX_GAME][7]){
	char user_game[100];
	int check,i;
	while(check!=1){
		printf("Please enter the name of a game:\n");
		scanf("%s",user_game);
		for (i = 0; i < MAX_GAME; i++){
			if (strcmp(nofgame[i],user_game)==0){
				check=1;									//if game is found check becomes 1
				break;
			}
		}
		if (check==1){
			printf("Name:\t\t %s\n",nofgame[i]);						//using i, informations of the game is printed
			printf("Genre:\t\t %s \n",genres[(int)info[i][0]] );
			printf("Platform:\t %s\n", platforms[(int)info[i][1]] );
			printf("Year:\t\t %.0f\n", info[i][2]);
			printf("Sales in NA:\t %f\n", info[i][3]);
			printf("Sales in EU:\t %f\n", info[i][4]);
			if (info[i][5]<0){
				printf("Total Sales:\t Not Available\n");				//if global sales is -1 it prints not available
			}
			else{
				printf("Total Sales:\t %f\n",info[i][5] );
			}
			printf("User Score:\t %f\n",info[i][6] );
		}
		else
			printf("There is no such game. TRY AGAIN\n");
	}
	printf("\n\n");
}
void avrg_score(float info[MAX_GAME][7]){
	int i;
	float sum=0,result;
	for (i = 0; i < MAX_GAME; i++){
		sum=sum+info[i][6];												//all scores are summed
	}
	printf("Average :%f\n\n\n",sum/MAX_GAME);
}
void geo_info(char nofgame[MAX_GAME][100], float info[MAX_GAME][7]){
	char user_game[100];
	int check,i;
	while(check!=1){													//checks wheter the game exist as in above funciton
		printf("Please enter the name of a game:\n");
		scanf("%s",user_game);
		for (i = 0; i < MAX_GAME; i++){
			if (strcmp(nofgame[i],user_game)==0){
				check=1;
				break;
			}
		}
		if (check==1){
			if (info[i][3]==info[i][4]){
				printf("This game had equal popularity in North America and Europe.\n");
			}
			else if (info[i][3]>info[i][4]){
				printf("This game was more popular in North America.\n");
			}
			else
				printf("This game was more popular in Europe.\n");
		}
		else
			printf("There is no such game. TRY AGAIN\n");

	}
	printf("\n\n");
}
void freq_genre(char genres[MAX_GENRE][20], float info[MAX_GAME][7]){
	int i,j,counter;
		
		for (i = 0; i < MAX_GENRE; i++){
			counter=0;									//counts the number of repetaion and used in printing
			for (j = 0; j < MAX_GAME; j++){
				if(i==info[j][0]){
					counter++;
				}
			}
			printf("%-15s %d\n",genres[i],counter);						
		}
		printf("\n\n");
}

void freq_platform(char platforms[MAX_PLATFORM][20], float info[MAX_GAME][7]){ // same algorithm as above
	int i,j,counter;
		
		for (i = 0; i < MAX_PLATFORM; i++){		
			counter=0;
			for (j = 0; j < MAX_GAME; j++){
				if(i==info[j][1]){
					counter++;
				}
			}
			printf("%-15s %d\n",platforms[i],counter);
		}
		printf("\n\n");
}