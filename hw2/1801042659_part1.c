#include <stdio.h>
#include <math.h>

int draw_triangle(int side1,int side2, int side3);
void type_triangle(int side1,int side2, int side3);
int perimeter_triangle(int side1,int side2, int side3);
double area_triangle(int side1,int side2, int side3,int perimeter);

int main(){
	
	int side1,side2,side3,perimeter;

	printf("The length of the first side:\n");
	scanf("%d",&side1);
	printf("The length of the second side:\n");
	scanf("%d",&side2);
	printf("The length of the third side:\n");
	scanf("%d",&side3);
	printf("\n");
	if (draw_triangle(side1,side2,side3)){								// if the triangle can't be drawn there is no area, no perimeter and no type thus there is no need to proceed
		printf("\n");
		type_triangle(side1,side2,side3);
		perimeter=perimeter_triangle(side1,side2,side3);
		area_triangle(side1,side2,side3,perimeter);
	}



	return 0;
}



int draw_triangle(int side1,int side2, int side3){

	if (side1+side2 > side3 && side1+side3 > side2 && side2+side3 > side1){	
		printf("According to the triangle inequality theorem, this triangle can be drawn.\n" );
		return 1;
	}
	else 
		printf("According to the triangle inequality theorem, this triangle cannot be drawn.\n");
		return 0;


}

void type_triangle(int side1,int side2, int side3){
	if (side1 == side2 && side2 == side3){								// if all  the sides are equal to each other
		printf("It is a equiliteral triangle.\n");
	}
	else if (side1 == side2 || side2 == side3 || side1 == side3){		// if only two sides are equal to each other
		printf("It is a isosceles triangle.\n");
	}
	else 																// if non of the sides are equal
		printf("It is a scalene triangle.\n");
}

int perimeter_triangle(int side1,int side2, int side3){					

	printf("The perimeter of the triangle is : %d\n", side1+side2+side3);

	return side1+side2+side3;

}
double area_triangle(int side1,int side2, int side3,int perimeter){

	printf("The area of the triangle is : %f\n", sqrt(  (perimeter/2) * ((perimeter/2)-side1) * ((perimeter/2)-side2) * ((perimeter/2)-side3)  ) );

	return sqrt(  (perimeter/2) * ((perimeter/2)-side1) * ((perimeter/2)-side2) * ((perimeter/2)-side3)  ) ;

}
