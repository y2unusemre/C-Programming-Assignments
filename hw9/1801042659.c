#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct Hospital{
	char* name;
	char citiesServed[3];
};
struct card {
	const char *face;
	const char *suit;
};

int numPathsHome(int street, int avenue);
int canOfferCovidCoverage(char _cities[6], char _locations[4][3], int _numHospitals, struct Hospital results[4]);

int index=0;
int main(){
	
	int street, avenue,i,j,_numHospitals;
	char _cities[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	char _locations[4][3] = { {'A', 'B', 'C'}, {'A', 'C', 'D'}, {'B', 'F'}, {'C', 'E', 'F'} };
	
	struct Hospital results[4];
	
	char suits [4][9]={"Hearts", "Diamonds", "Clubs", "Spades"};
	char faces [13][6]={"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	struct card deck[52],temp;
	srand(time(0));

		//part1 
	printf("Enter the street number: ");
	scanf("%d",&street);
	printf("Street:%d\n",street );
	printf("Enter the avenue number: ");
	scanf("%d",&avenue);
	printf("Avenue:%d\n",avenue );
	printf("Number of optimal paths to take back home: %d\n",numPathsHome(street,avenue));



	printf("\n\n\n\n");
	//part3 
	for (i = 0; i < 52; i++){						// first the deck is initiallised in order
			deck[i].face=faces[i%13];
			deck[i].suit=suits[i/13];
	}
	for (i = 0; i < 52; i++){						//then its shuffled

		j = rand()%52;								//randomly chosen a number for changing positions of two cards 
		temp.face = deck[i].face;
		deck[i].face=deck[j].face;
		deck[j].face=temp.face;

		temp.suit = deck[i].suit;
		deck[i].suit=deck[j].suit;
		deck[j].suit=temp.suit;
	}

	for (int i = 0; i < 52; ++i){					//printed
		printf(" %s\tof %s\n", deck[i].face, deck[i].suit);
	}

	//part2 is not working properly
	printf("Enter the maximum number of hospitals that can be constructed: ");
	scanf("%d",&_numHospitals);
	printf("\n");
	canOfferCovidCoverage(_cities, _locations, _numHospitals, results);

	return 0;
}


int numPathsHome(int street, int avenue){
	if (street==1 || avenue==1 ){							//if any of them is one it returns 1 i used the algorithm such as in https://www.youtube.com/watch?v=aSM8Wn8_A6E
		return 1;
	}
	return numPathsHome(street-1,avenue)+numPathsHome(street,avenue-1);
}

int canOfferCovidCoverage(char _cities[6], char _locations[4][3], int _numHospitals, struct Hospital results[4]){
	int i=0,j=0;
	char _altCities[6];
	strcpy(_altCities,_cities);

	if (strcmp("abcdef",_altCities)==0 ){
			return 0;
	}	
	for (i = 0; i < 6; i++){
		if (_locations[index][j] == _altCities[i]){
			_altCities[i] = _altCities[i]+32;
			j++;
		}
	}
	index++;
	canOfferCovidCoverage(_cities, _locations, _numHospitals, results);


	printf("%s\n",_altCities );
}