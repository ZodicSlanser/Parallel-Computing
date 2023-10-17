#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10

struct User {
    char username[20];
    char password[20];
    char email[20];
    char phone[20];
    char address[20];
    int age;
};

struct User users[MAX_USERS];
int userCount = 0;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printFancyLoginArt() {
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*         Welcome to My App Login           *\n");
    printf("*                                           *\n");
    printf("*********************************************\n");
    printf("\n");
}

void printFancyRegistrationArt() {
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*         Welcome to My App Registration    *\n");
    printf("*                                           *\n");
    printf("*********************************************\n");
    printf("\n");
}

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("Maximum number of users reached!\n");
        return;
    }

    struct User newUser;

    printf("Enter username: ");
    scanf("%s", newUser.username);

    printf("Enter password: ");
    scanf("%s", newUser.password);

    printf("Enter email: ");
    scanf("%s", newUser.email);

    printf("Enter phone: ");
    scanf("%s", newUser.phone);

    printf("Enter address: ");
    scanf("%s", newUser.address);

    printf("Enter age: ");
    scanf("%d", &newUser.age);

    users[userCount++] = newUser;

    printf("\nRegistration successful!\n");
    printf("Press any key to continue...");
    getchar();
}

void loginUser() {
    char loginUsername[20];
    char loginPassword[20];
    printf("Enter username: ");
    scanf("%s", loginUsername);

    printf("Enter password: ");
    scanf("%s", loginPassword);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(loginUsername, users[i].username) == 0 &&
            strcmp(loginPassword, users[i].password) == 0) {
            printf("Login successful!\n");

            printf("Welcome, %s!\n", users[i].username);
            printf("Your email is %s\n", users[i].email);
            printf("Your phone is %s\n", users[i].phone);
            printf("Your address is %s\n", users[i].address);
            printf("Your age is %d\n", users[i].age);

            printf("\n");
            printf("Returning to main menu...\n");
            return;
        }
    }

    printf("Invalid username or password!\n");
}

int main(void) {
    int choice;

    while (1) {
        clearScreen();

        printf("=============================================\n");
        printf("|             Login & Registration          |\n");
        printf("=============================================\n");
        printf("\n");

        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printFancyLoginArt();
                loginUser();
                break;
            case 2:
                printFancyRegistrationArt();
                registerUser();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        if (choice == 3) {
            break;
        }

        getchar(); 
        printf("Press Enter to continue...");
        getchar(); 
    }

    return 0;
}