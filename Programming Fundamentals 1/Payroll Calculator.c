#include <stdio.h>

int main() {
    // Declare Variables
    int numEmployees, empID;
    float hoursWorked, payRate, grossPay, taxAmount, netPay;
    float taxRate = 0.03525;
    
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    int count = 1;
    while (count <= numEmployees) { // Loop Until all Employees are Calculated
        // Collect Inputs
        printf("\nEnter Employee ID: ");
        scanf("%d", &empID);
        
        printf("Enter hourly pay rate: $");
        scanf("%f", &payRate);
        
        printf("Enter hours worked this week: ");
        scanf("%f", &hoursWorked);
        
        // Calculate gross pay with overtime
        if (hoursWorked > 40) {
            grossPay = (40 * payRate) + ((hoursWorked - 40) * (payRate * 1.5));
        } 
        else {
            grossPay = hoursWorked * payRate;
        }
        
        // Calculate tax and net pay
        taxAmount = grossPay * taxRate;
        netPay = grossPay - taxAmount;
        
        // Output results
        printf("\nEmployee ID: %d", empID);
        printf("\nHours Worked: %.2f", hoursWorked);
        printf("\nGross Pay: $%.2f", grossPay);
        printf("\nWithholding Tax (3.525%%): $%.2f", taxAmount);
        printf("\nNet Pay: $%.2f\n", netPay);
        
        count++;
    }

    printf("\nPayroll processing complete.\n");
    return 0;
}