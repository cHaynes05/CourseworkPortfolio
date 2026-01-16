#include <stdio.h>

int main(void)
{
    float gallons, miles, mpg, averageMPG;
    float totalMiles = 0.0, totalGallons = 0.0;

    // Prompt user for the first input
    printf("Enter the gallons used (-1 to end): ");
    scanf("%f", &gallons);

    // Loop until user enters -1
    while (gallons != -1) {
        printf("Enter the miles driven: ");
        scanf("%f", &miles);

        // Compute mpg for this tank
        mpg = miles / gallons;
        printf("The miles/gallon for this tank was %.2f\n", mpg);

        // Add to the totals
        totalMiles += miles;
        totalGallons += gallons;

        // Ask for next input
        printf("Enter the gallons used (-1 to end): ");
        scanf("%f", &gallons);
    }

    // After loop, compute average of all tanks
    if (totalGallons > 0) {
        averageMPG = totalMiles / totalGallons;
        printf("The overall average miles/gallon was %.2f\n", averageMPG);
    }
    else {
        printf("No data was entered.\n");
    }

    return 0;
}