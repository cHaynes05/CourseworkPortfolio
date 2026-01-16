#include <stdio.h>

int main() {
    float milesTraveled, gallonsUsed, mpg;
    
    // Prompt User to Input Miles Traveled
    printf("Enter miles traveled: ");
    scanf("%f", &milesTraveled);

    // Prompt User to Input Gallons Used
    printf("Enter gallons used: ");
    scanf("%f", &gallonsUsed);

    // Divide Miles by Gallons
    mpg = milesTraveled / gallonsUsed;

    // Display Calculated Result to User
    printf("Miles per gallon: %.2f\n", mpg);
    return 0;
}

