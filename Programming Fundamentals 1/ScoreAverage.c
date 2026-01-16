#include <stdio.h>

// Reverses the order of the values
void reverseValues(float values[], int count) {
    int i;
    for (i = 0; i < count / 2; i++) {
        float temp = values[i];
        values[i] = values[count - 1 - i];
        values[count - 1 - i] = temp;
    }
}

// Calculates and returns the average
float averageValues(float values[], int count) {
    float sum = 0.0f;
    int i;

    for (i = 0; i < count; i++) {
        sum += values[i];
    }
    return sum / count;
}

int main() {
    int count;
    char sentinel = 'y';

    // Main Loop
    while (sentinel == 'y' || sentinel == 'Y') {

        printf("\nEnter number of values (0 to quit): ");
        scanf("%d", &count);

        if (count == 0) {
            return 0;
        }

        float values[count];

        int i;

        // Fill array with the user input
        for (i = 0; i < count; i++) {
            printf("Enter value %d: ", i + 1);
            scanf("%f", &values[i]);
        }

        // Reverse and display
        reverseValues(values, count);

        printf("\nReversed values:\n");
        for (i = 0; i < count; i++) {
            printf("%.2f ", values[i]);
        }
        printf("\n");

        // Compute average of reversed values
        float average = averageValues(values, count);

        printf("\nAverage = %.2f\n", average);
        printf("\nValue   | Distance From Average\n");
        printf("---------------------------------\n");

        for (i = 0; i < count; i++) {
            float diff = values[i] - average;
            if (diff < 0) diff = -diff;
            printf("%.2f   |   %.2f\n", values[i], diff);
        }
        
        printf("\nEnter another set? (y/n): ");
        scanf(" %c", &sentinel);
    }
    return 0;
}
