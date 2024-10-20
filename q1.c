#include <stdio.h>

int main()
{

    // Step 1: Create and open a file for writing
    FILE *file = fopen("demo.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1; // Exit if file can't be opened
    }

    // Step 2: Write to the file
    fprintf(file, "Hello, Welcome to CSE department!\n"); // Write a string to the file

    // Step 3: Close the file
    fclose(file);

    // Step 4: Open the file for reading
    file = fopen("demo.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file for reading");
        return 1; // Exit if file can't be opened
    }

    //Step 5:Read and print the content of the file
    char buffer[100]; // Buffer to hold the line read
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }

    // Step 6: Close the file
    fclose(file);
    return 0;
}

