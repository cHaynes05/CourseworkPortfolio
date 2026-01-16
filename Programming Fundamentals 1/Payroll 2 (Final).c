#include <stdio.h>

// Function prototypes
float calcManager(float yearlySalary);
float calcHourly(float hours, float rate);
float calcCommission(float sales);

int main() {
    int totalEmployees;

    // Fixed values
    float taxRate = 0.09275;
    float insSingle = 50.00;
    float insFamily = 115.00;

    // Ask how many employees to process
    printf("Enter total number of employees: ");
    scanf("%d", &totalEmployees);

    // Per Emplyoyee Data
    int id[totalEmployees];
    float grossPay[totalEmployees];
    float taxPaid[totalEmployees];
    float insuranceCost[totalEmployees];
    float netPay[totalEmployees];

    int payCode, insuranceChoice, insuranceType;
    float yearlySalary, hours, rate, sales;
    float totalCompanyPay = 0;

    printf("\n--- Enter Employee Payroll Information ---\n");

    for (int i = 0; i < totalEmployees; i++) {
        printf("\nEnter Employee %d ID: ", i + 1);
        scanf("%d", &id[i]);

        printf("Enter Paycode (1=Manager, 2=Hourly, 3=Commission): ");
        scanf("%d", &payCode);

        switch (payCode) {
            case 1:
                printf("Enter Yearly salary: ");
                scanf("%f", &yearlySalary);
                grossPay[i] = calcManager(yearlySalary);
                break;

            case 2:
                printf("Enter hours worked this week: ");
                scanf("%f", &hours);
                printf("Enter hourly rate: ");
                scanf("%f", &rate);
                grossPay[i] = calcHourly(hours, rate);
                break;

            case 3:
                printf("Enter weekly sales: ");
                scanf("%f", &sales);
                grossPay[i] = calcCommission(sales);
                break;
        }

        // Determine insurance choice
        printf("Do they want insurance? (1=Yes, 2=No): ");
        scanf("%d", &insuranceChoice);

        if (insuranceChoice == 1) {
            printf("Insurance type? (1=Single $50, 2=Family $115): ");
            scanf("%d", &insuranceType);
            if (insuranceType == 1) {
                insuranceCost[i] = insSingle;
            } else {
                insuranceCost[i] = insFamily;
            }
        } else {
            insuranceCost[i] = 0;
        }

        // Deduct insurance cost then calculate tax and net pay
        float taxableIncome = grossPay[i] - insuranceCost[i];
        if (taxableIncome < 0) taxableIncome = 0;

        taxPaid[i] = taxableIncome * taxRate;
        netPay[i] = taxableIncome - taxPaid[i];

        totalCompanyPay += netPay[i];
    }

    // Payroll Report
    printf("\n\n======================== Payroll Report ========================\n");
    printf("%-10s %-12s %-12s %-12s %-12s\n",
           "ID", "Gross Pay", "Insurance", "Tax Paid", "Net Pay");
    printf("-------------------------------------------------------------------\n");

    for (int i = 0; i < totalEmployees; i++) {
        printf("%-10d $%-11.2f $%-11.2f $%-11.2f $%-11.2f\n",
               id[i], grossPay[i], insuranceCost[i], taxPaid[i], netPay[i]);
    }

    printf("-------------------------------------------------------------------\n");
    printf("%-42s $%-11.2f\n", "Total Company Net Pay:", totalCompanyPay);
    printf("===================================================================\n");

    return 0;
}

// Payroll Calculation Functions
float calcManager(float yearlySalary) {
    return yearlySalary / 52;
}

float calcHourly(float hours, float rate) {
    if (hours > 40)
        return (40 * rate) + ((hours - 40) * rate * 1.5);
    else
        return hours * rate;
}

float calcCommission(float sales) {
    return 375 + (sales * 0.072);
}
