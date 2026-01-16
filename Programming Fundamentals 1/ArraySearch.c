#include <stdio.h>

int main() {

    int nums[7];
    int searchValue;
    int foundIndex = -1;

    // Initialize array using index * 5
    for (int i = 0; i < 7; i++) {
        nums[i] = i * 5;
    }

    // Ask user for input
    printf("Enter a number to search for: ");
    scanf("%d", &searchValue);

    // Search the array
    for (int i = 0; i < 7; i++) {
        if (nums[i] == searchValue) {
            foundIndex = i;
            break;
        }
    }

    // Output results
    if (foundIndex != -1) {
        printf("I found your value in index %d\n", foundIndex);
    } else {
        printf("Your value was not found in the array.\n");
    }

    return 0;

}
