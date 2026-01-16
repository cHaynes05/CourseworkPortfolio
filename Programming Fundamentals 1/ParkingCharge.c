#include <stdio.h>
#include <math.h>

int main() {
    float hoursParked, parkingFee;

    // Prompt User to Input hoursParked
    printf("Enter number of hours parked: ");
    scanf("%lf", &hoursParked);

    // Calculate Fee Based on Hours Parked
    if (hoursParked <= 2) {
        parkingFee = 7.50;
    } 
    else if (hoursParked >= 10) {
        parkingFee = 20.00; 
    } 
    else {
        parkingFee = 7.50 + (ceil(hoursParked - 2) * 2.25);
    }

    // Output result (parkingFee)
    printf("Total Parking Fee: $%.2f\n", parkingFee);

    return 0;
}
