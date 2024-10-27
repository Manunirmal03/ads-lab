#include<stdio.h>
#include<conio.h>

// Function prototypes
void input();
void setunion();
void intersection();
void difference();
void output(int c[]);

// Global arrays to hold sets a, b, and c
int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Holds set A (indexed from 1 to 9)
int b[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Holds set B (indexed from 1 to 9)

int main() {
    int ch, wish;
    clrscr();
    // Main menu loop
    do {
	printf("\nMENU\n");
	printf("1. Input\n2. Union\n3. Intersection\n4. Difference\n");
	printf("Enter your choice: ");
	scanf("%d", &ch);

	// Switch to call the appropriate function based on user's choice
	switch (ch) {
	    case 1: input(); break;
	    case 2: setunion(); break;
	    case 3: intersection(); break;
	    case 4: difference(); break;
	    default: printf("Wrong choice");
	}

	// Ask the user if they wish to continue
	printf("\nDo you wish to continue? (1 for yes / 0 for no): ");
	scanf("%d", &wish);
    } while (wish == 1);

    getch();
    return 0;  // End of program
}

// Function to input elements of two sets
void input() {
    int n, ele, i;

    // Input for first set
    printf("Enter the size of first set: ");
    scanf("%d", &n);
    printf("Enter the elements (1 to 9 only):\n");
    for (i = 1; i <= n; i++) {
	scanf("%d", &ele);
	if (ele >= 1 && ele <= 9) {  // Ensure element is in the valid range
            a[ele] = 1;
        } else {
            printf("Invalid element, only numbers 1-9 are allowed.\n");
        }
    }

    // Input for second set
    printf("Enter the size of second set: ");
    scanf("%d", &n);
    printf("Enter the elements (1 to 9 only):\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &ele);
        if (ele >= 1 && ele <= 9) {  // Ensure element is in the valid range
            b[ele] = 1;
        } else {
            printf("Invalid element, only numbers 1-9 are allowed.\n");
        }
    }

    // Display the two sets
    printf("\nFirst set: ");
    for (i = 1; i <= 9; i++) {
        printf("%d ", a[i]);
    }

    printf("\nSecond set: ");
    for (i = 1; i <= 9; i++) {
        printf("%d ", b[i]);
    }
}

// Function to output the elements of the resulting set
void output(int c[]) {
    int i;
    printf("\nResulting set: ");
    for (i = 1; i <= 9; i++) {
        if (c[i] != 0) {
            printf("%d ", i);  // Print the element (index) if it's part of the set
        }
    }
    printf("\n");
}

// Function to compute the union of sets A and B
void setunion() {
    int i, c[10];
    for (i = 1; i <= 9; i++) {
        c[i] = a[i] | b[i];  // Union operation using OR
    }
    printf("\nUnion: ");
    for (i = 1; i <= 9; i++) {
        printf("%d ", c[i]);
    }
    output(c);  // Output the set
}

// Function to compute the intersection of sets A and B
void intersection() {
    int i, c[10];
    for (i = 1; i <= 9; i++) {
        c[i] = a[i] & b[i];  // Intersection operation using AND
    }
    printf("\nIntersection: ");
    for (i = 1; i <= 9; i++) {
        printf("%d ", c[i]);
    }
    output(c);  // Output the set
}

// Function to compute the difference of set A - set B
void difference() {
    int i, c[10];
    for (i = 1; i <= 9; i++) {
        c[i] = (a[i] == 1 && b[i] == 0) ? 1 : 0;  // Difference operation A - B
    }
    printf("\nDifference (A - B): ");
    for (i = 1; i <= 9; i++) {
        printf("%d ", c[i]);
    }
    output(c);  // Output the set
}