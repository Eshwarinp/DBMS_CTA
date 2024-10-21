#include <stdio.h>

#define arrSIZE 10  // Defining a constant size for the array

// Function to display the array

void display(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert a value at a specific index

void insert(int arr[], int *size, int index, int value) {
    if (index > *size || index < 0) {
        printf("Invalid index!\n");
        return;
    }
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    (*size)++;
    printf("Inserted %d at index %d\n", value, index);
}g

// Function to delete a value from a specific index

void delete(int arr[], int *size, int index) {
    if (index >= *size || index < 0) {
        printf("Invalid index!\n");
        return;
    }
    printf("Deleted %d from index %d\n", arr[index], index);
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

// Function to search for a value using its index
int searchByIndex(int arr[], int size, int index) {
    if (index >= size || index < 0) {
        printf("Invalid index!\n");
        return -1;
    }
    return arr[index];
}

int main() {
    int arr[arrSIZE], size, choice, index, value;

    // Taking input for the initial size of the array
    printf("Enter the initial size of the array (max %d): ", arrSIZE);
    scanf("%d", &size);

    if (size > arrSIZE) {
        printf("Size exceeds the maximum limit!\n");
        return 1;
    }

    // Taking input for the array elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display initial array
    printf("Initial array:\n");
    display(arr, size);

    // Menu-driven program for performing operations
    do {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Search by index\n");
        printf("4. Display array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert an element
                printf("Enter the index to insert (0 to %d): ", size);
                scanf("%d", &index);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(arr, &size, index, value);
                display(arr, size);
                break;
            
            case 2: // Delete an element
                printf("Enter the index to delete (0 to %d): ", size - 1);
                scanf("%d", &index);
                delete(arr, &size, index);
                display(arr, size);
                break;
            
            case 3: // Search by index
                printf("Enter the index to search (0 to %d): ", size - 1);
                scanf("%d", &index);
                value = searchByIndex(arr, size, index);
                if (value != -1) {
                    printf("Value at index %d: %d\n", index, value);
                }
                break;
            
            case 4: // Display the array
                display(arr, size);
                break;
            
            case 5: // Exit
                printf("Exiting the program.\n");
                break;
            
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
