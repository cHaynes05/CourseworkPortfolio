#include <stdio.h>

float calculateCharge(float hours);

int main() {
    float hours, totalCharge;

    // Promt user and scan for hours
    printf("Enter number of hours parked: "); 
    scanf("%f", &hours);

    // Call calculateCharge
    totalCharge = calculateCharge(hours);

    printf("Total parking charge: $%.2f\n", totalCharge);

    return 0;
}

// calculateCharge Function Definition
float calculateCharge(float hours) {
    float charge;

    // Range Classification for Switch Statement
    int formula;
    formula = 1 + (hours > 2) + (hours >= 8);
    
    // Switch Statement with Formulas
    switch (formula) {
        case 1:
            charge = 7.50;
            break;
        case 2:
            charge = 7.50 + ((hours - 2) * 2.25);
            break;
        case 3:
            charge = 35.00;
            break;
    }

    return charge;
}
