#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//  To clear the screen at certain points
void clearScreen() {
  system("clear||cls");
}


// initializing the structure of the date of the trip.
struct date {
        int day;
        int month;
        int year;
        
} trip[5]; // trip is the name of the structure.



int main()
// showing the routes of the bus where the user can choose from.
{ 
    char *routes[] = {"Hyderabad to Bangalore Bus", 
                       "Hyderabad to Vijayawada Bus", 
                       "Hyderabad to Tirupathi Bus", 
                       "Hyderabad to Mumbai Bus", 
                       "Hyderabad to Visakhapatnam Bus", 
                       "Vijayawada to Bangalore Bus", 
                       "Vijayawada to Visakhapatnam Bus", 
                       "Bangalore to Hyderabad Bus", 
                       "Bangalore to Chennai Bus", 
                       "Mumbai to Aurangabad Bus", 
                       "Manali to Delhi Bus", 
                       "Delhi to Chandhigarh Bus", 
                       "Delhi to Lucknow Bus", 
                       "Delhi to Kanpur Bus"};


        
    // Initializing almost all the variables.
    int choice; 
    int k = 0; // To keep the record of the number of tickets in array of structure
    int choice_list[20]; // To keep the record of the name of  the route chosen by the user
    int num_passengers;


    // The prices of the tickets as per routes array.
    float prices[] = {1000.0, 800.0, 700.0, 1500.0, 1200.0, 900.0, 1000.0, 1200.0, 1500.0, 2000.0, 2500.0, 3000.0, 2500.0, 2000.0};
    

    
    bool work = true; // To keep the program running until the user wants to exit.

    printf("                                            ------------------------------> BLUE-BUS ONLINE TICKET GENERATOR <------------------------------\n\n");
    printf("                                                                            -> Book Bus Tickets in India <-\n\n");



    while (work) // To keep the program running until the user wants to exit.
    {
        
         // Shows the user the options available and ask for the choice.
        printf("Top Routes in India you can choose from: \n\n");

        for (int i = 0; i < 14; ++i) {
            printf("%d. %s - Rs.%.2f\n",i+1,  routes[i], prices[i]); // shows all the routes available.
        }

        printf("\nWhere do you wish to travel? [Enter the number of the route] \n");
        scanf("%d", &choice);
        choice_list[k] = choice;

        printf("Okay! So you're choosing to go from %s.\n", routes[choice-1]);

        printf("When do you wish to go? [Enter date in the format dd/mm/yyyy] \n"); //Ask for the date of the trip
        scanf("%d/%d/%d", &trip[k].day, &trip[k].month, &trip[k].year);

        printf("\nAlright, the date is: %d/%d/%d\n", trip[k].day, trip[k].month, trip[k].year);

        printf("How many passengers do you have? \n"); // number of passengers
        scanf("%d", &num_passengers);

        printf("\nAlright, you're booking %d passengers.\n", num_passengers);
        
        // Calculating the total price of the tickets.
        float total_price = num_passengers * prices[choice-1];
        printf("\nThe total price for %d passengers is Rs.%.2f\n", num_passengers, total_price); // total price


        // Confirms the user's booking.
        char final;
        
        

        
            printf("\nSo this is all you booked: \n1. From-> %s\n2. On date-> %d/%d/%d\n3. Number of passengers -> %d\n4. Total price -> Rs.%.2f\n\nIs that right and all? [y/n] ->", 
                    routes[choice-1], trip[k].day, trip[k].month, trip[k].year, num_passengers, total_price);
            scanf(" %c", &final);
        // Re confirms to add the tickets to the array of structure.
            if (final == 'y') {
                printf("\n\nYour %d tickets from %s on %d/%d/%d are booked.\n\nThank You for booking from BLUE-BUS😀!!\n", num_passengers, routes[choice - 1],  trip[k].day, trip[k].month, trip[k].year);
                k = k+1;
            }
            else
            {
                printf("Bookings Cancelled!!");
                work = false;
            }
            
  
            bool confirm = true;

            
            while (confirm)
            { 
                // Ask the user to make a choice of what they want to do with the tickets.

    printf("\n\nWhat would you like to do?\n");
    printf("1. Book another ticket\n");
    printf("2. View all tickets\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    
    int make;
    scanf("%d", &make);

    switch (make)
     {
        case 1:
            // Book another ticket
            clearScreen();  // to clear the screen
            confirm = false;
            break;
        case 2:
            // View all tickets
            printf("Here are all your booked tickets:\n");
            for (int i = 0; i < k; i++) {
                printf("\tTicket No. %d\t From: %s\t Dated: %d/%d/%d\n",
                       i+1, routes[choice_list[i]], trip[i].day, trip[i].month, trip[i].year);
            }
            
            break;
        case 3:
            // Exit
            confirm = false;
            work = false;
            printf("\nThank you for using BLUE-BUS Online Ticket Generator!\n");
            break;
        //create a case for only deleting the tickets from the array of structure.
        case 4:
            // Delete tickets
                // Delete the tickets
                printf("Here are all your booked tickets:\n");
                for (int i = 0; i < k; i++) {
                    printf("\tTicket No. %d\t From: %s\t Dated: %d/%d/%d\n",
                       i+1, routes[choice_list[i]], trip[i].day, trip[i].month, trip[i].year);
                       }
                       printf("\n\n");
                       
                       printf("Enter the ticket number you wish to delete: "); 
                       int delete;
                       scanf("%d", &delete);
                       printf("\n");
                       
                    // To delete the tickets
                       for (int i = delete-1; i < k; i++) {
                           choice_list[i] = choice_list[i+1];
                           trip[i] = trip[i+1];
                           
                       }
                       k--;
                       k = k-1;
                       
                       break;



        default:
            // For invalid user input
            printf("\nInvalid choice. Please enter a valid option.\n");
            break;
    
}

            }
            
            
            
            
    }

    
    return 0;
}