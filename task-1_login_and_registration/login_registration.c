#include <stdio.h>
#include <stdlib.h>


void clearScreen() {

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

    char username[20];
    char password[20];
    char email[20];
    char phone[20];
    char address[20];
    int age;

void printFancyRegistrationArt() {
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*         Welcome to My App Registration    *\n");
    printf("*                                           *\n");
    printf("*********************************************\n");
    printf("\n");
}

void printFancyLoginArt() {
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*         Welcome to My App Login           *\n");
    printf("*                                           *\n");
    printf("*********************************************\n");
    printf("\n");
}

void registerUser() {
    char regUsername[20];
    char regPassword[20];
    char regEmail[20];
    char regPhone[20];
    char regAddress[20];
    int regAge;

    printf("Enter username: ");
    scanf("%s", regUsername);

    printf("Enter password: ");
    scanf("%s", regPassword);

    printf("Enter email: ");
    scanf("%s", regEmail);

    printf("Enter phone: ");
    scanf("%s", regPhone);

    printf("Enter address: ");
    scanf("%s", regAddress);

    printf("Enter age: ");
    scanf("%d", &regAge);

    strcpy(username, regUsername);
    strcpy(password, regPassword);
    strcpy(email, regEmail);
    strcpy(phone, regPhone);
    strcpy(address, regAddress);
    age = regAge;

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

    if (strcmp(loginUsername, username) != 0 || strcmp(loginPassword, password) != 0) {
        printf("Invalid username or password!\n");
        return;
    }

    printf("Login successful!\n");

    printf("Welcome, %s!\n", username);
    printf("Your email is %s\n", email);
    printf("Your phone is %s\n", phone);
    printf("Your address is %s\n", address);
    printf("Your age is %d\n", age);

    printf("\n");
    printf("Returning to main menu...\n");
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

