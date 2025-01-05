#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data for buses and available seats
char buses[5][50] = {"Goa Express", "Mumbai Express", "Chennai Express", "Gujrat Express", "Delhi Express"};
int seatsAvailable[5] = {30, 25, 20, 15, 10}; 
int bookedSeats[5][32] = {0};

// Function to cancel a booking
void cancle() {
    int seat_no, busNumber;
    
    system("cls");
    printf("\n\n\t\t\t\t\t ========== Ticket canceling ==========\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s \n", buses[0]);
    printf("\t\t\t\t\t[2]  =>  %s \n", buses[1]);
    printf("\t\t\t\t\t[3]  =>  %s \n", buses[2]);
    printf("\t\t\t\t\t[4]  =>  %s \n", buses[3]);
    printf("\t\t\t\t\t[5]  =>  %s \n", buses[4]);
    printf("\n\n\n======================================================================================================\n\n");
    printf("\t\t\t\t Enter the bus number (1-5) to cancel tickets: ");
    scanf("%d", &busNumber);

    // Validate bus number input
    if (busNumber < 1 || busNumber > 5) {
        printf("Invalid bus number! Please enter a number between 1 and 5.\n");
        getchar();
        printf("Press Enter to continue...");
        getchar();
        return;
    }

    printf("\n\n\t\t\t\t Enter the seat number you want to cancel (1-32): ");
    scanf("%d", &seat_no);

    // Validate seat number input
    if (seat_no < 1 || seat_no > 32) {
        printf("Invalid seat number! Please enter a number between 1 and 32.\n");
        getchar();
        printf("Press Enter to continue...");
        getchar();
        return;
    }

    // Check if the seat is booked
    if (bookedSeats[busNumber - 1][seat_no - 1] == 1) {
        bookedSeats[busNumber - 1][seat_no - 1] = 0; // Mark the seat as empty
        seatsAvailable[busNumber - 1]++; // Increase available seat count
        printf("\n\n\t\t\t\t   ========================================\n");
        printf("\t\t\t\t    Booking successfully canceled for seat %d.\n", seat_no);
        printf("\t\t\t\t   ========================================\n");
    } else {
        printf("\n\n\t\t\t\t   ========================================\n");
        printf("\t\t\t\t    Seat %d is already empty.\n", seat_no);
        printf("\t\t\t\t   ========================================\n");
    }

    printf("\n\n\n Press Enter to continue...");
    getchar();
    getchar();
}

// Function for user login
void login() {
    char username[10], password[10];
    int i = 0;

    printf("\n\n\t\t\t\t\t   ======== LOGIN ========\n");
    printf("\n\t\t\t\t\t  Username: ");
    scanf("%s", username);
    printf("\n\t\t\t\t\t  Password: ");

    // Use getch() to read password without displaying it
    while (1) {
        password[i] = getch(); // Get character without displaying it
        if (password[i] == '\r') { // Enter key
            break;
        }
        printf("*"); // Print asterisk for each character entered
        i++;
    }
    password[i] = '\0'; // Null-terminate the password string

    if (strcmp(username, "user") == 0 && strcmp(password, "pass") == 0) {
        printf("\n\n\t\t\t\t\t   ======== Login successful! ======== \n");
    } else {
        printf("\n\t\t\t\t\t  Login failed! Exiting...\n");
        exit(0);
    }
    printf("\n\n\n Press Enter to continue...");
    getchar();
    getchar();
}

// Function to view bus list
void viewBuses() {
    system("cls");
    printf("\n\n\n=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s \n", buses[0]);
    printf("\t\t\t\t\t[2]  =>  %s \n", buses[1]);
    printf("\t\t\t\t\t[3]  =>  %s \n", buses[2]);
    printf("\t\t\t\t\t[4]  =>  %s \n", buses[3]);
    printf("\t\t\t\t\t[5]  =>  %s \n", buses[4]);
    getchar();
    printf("Press Enter to continue...");
    getchar();
}

// Function to book tickets
void booking() {
    int busNumber, tickets;

    system("cls");
    printf("\n\n\t\t\t\t\t ========== Ticket Booking ==========\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s \n", buses[0]);
    printf("\t\t\t\t\t[2]  =>  %s \n", buses[1]);
    printf("\t\t\t\t\t[3]  =>  %s \n", buses[2]);
    printf("\t\t\t\t\t[4]  =>  %s \n", buses[3]);
    printf("\t\t\t\t\t[5]  =>  %s \n", buses[4]);
    printf("\n\n\n======================================================================================================\n\n");
    printf("\t\t\t\t Enter the bus number (1-5) to book tickets: ");
    scanf("%d", &busNumber);

    // Validate bus number input
    if (busNumber < 1 || busNumber > 5) {
        printf("\t\t\t\t\n\n Invalid bus number! Please enter a number between 1 and 5.\n");
        getchar();
        printf("\n\n Press Enter to continue...");
        getchar();
        return;
    }

    printf("\n\n\t\t\t\t Enter the number of tickets to book: ");
    scanf("%d", &tickets);

    // Check if enough seats are available
    if (tickets <= seatsAvailable[busNumber - 1]) {
        seatsAvailable[busNumber - 1] -= tickets;
//        printf("\n\n\t Booking successful! You have booked %d ticket(s) on %s.\n", tickets, buses[busNumber - 1]);

        // Mark the seats as booked
        int i;
        for ( i = 0; i < tickets; i++) {
            int seat_no;
            printf("\n\t\t\t\tEnter seat number for ticket %d (1-32): ", i + 1);
            scanf("%d", &seat_no);

            // Validate seat number input
            if (seat_no < 1 || seat_no > 32) {
                printf("Invalid seat number! Please enter a number between 1 and 32.\n");
                i--; // Adjust counter to re-enter this seat number
                continue;
            }

            if (bookedSeats[busNumber - 1][seat_no - 1] == 0) {
                bookedSeats[busNumber - 1][seat_no - 1] = 1; // Mark seat as booked
                printf("\t\t\t\tSeat %d successfully booked.\n", seat_no);
            } else {
                printf("\t\t\t\tSeat %d is already booked, please choose another.\n", seat_no);
                i--; // Adjust counter to re-enter this seat number
            }
        }
    } else {
        printf("\n\n\t Sorry, only %d seats are available on %s.\n", seatsAvailable[busNumber - 1], buses[busNumber - 1]);
    }

    getchar();
    printf("\n\n Press Enter to continue...");
    getchar();
}

int main() {
    login();
    int num;

    do {
        system("cls");
        printf("\n\n\n====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n");
        printf("\t\t\t\t\t[1]=> View Bus\n");
        printf("\t\t\t\t\t[2]=> Book Tickets\n");
        printf("\t\t\t\t\t[3]=> Cancel Booking\n");
        printf("\t\t\t\t\t[4]=> Exit\n\n");
        printf("===============================================================================================================\n\n");
        printf("\t\t\tEnter Your Choice: ");
        scanf("%d", &num);

        switch (num) {
            case 1:
                viewBuses();
                break;
            case 2:
                booking();
                break;
            case 3:
                cancle();
                break;
            case 4:
                printf("Thank you for using the system!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (num != 4);

    system("cls");
    printf("\n\t\t\t\t \n Thank you for using the Bus Reservation System!\n");

    return 0;
}

