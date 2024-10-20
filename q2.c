#include <stdio.h>
#define MAX_NUMBERS 10

int main()
{
int numbers[MAX_NUMBERS];
int count = 0;
int choice;

do {
printf("\nMenu:\n");
printf("1. Add Number\n");
printf("2. Search Number\n");
printf("3. Display All Numbers\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {

case 1: // Add Number

if (count < MAX_NUMBERS) 
{
printf("Enter a number: ");
scanf("%d", &numbers[count]);
count++;
printf("Number added.\n");
} 

else 
{
printf("Number limit reached.\n");
}
break;

case 2: // Search Number

{
int searchNum, found = 0;
printf("Enter number to search: ");
scanf("%d", &searchNum);

for (int i = 0; i < count; i++) 
{
if (numbers[i] == searchNum) 
{
printf("Number %d found at index %d.\n", searchNum, i);
found = 1;
break;
}
}

if (!found) {
printf("Number not found.\n");
}

}
break;

case 3: // Display All Numbers

printf("All Numbers:\n");
for (int i = 0; i < count; i++) 
{
printf("%d ", numbers[i]);
}
printf("\n");

break;

case 4: // Exit
printf("Exiting...\n");
break;
default:
printf("Invalid choice. Please try again.\n");
} //end of switch

} 
while (choice != 4);
return 0;
}