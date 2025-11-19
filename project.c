#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int row_position;
    int column_position;

} Parking_Position;

typedef struct
{
    char *vehicle_plate;
    char *vehicle_type;

} Vehicle;

typedef struct
{
    int parking_grid[26][10];
    int occupied_parking_spaces;
    int free_parking_spaces;
    char *parked_vehicle_info[26][10];

} Parking_lot;


void display_parking(Parking_lot parking_lot);
Parking_Position find_vehicle(Parking_lot parking_lot, char *vehicle_plate);

int main(void)
{
    Parking_lot parking_lot;

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            parking_lot.parking_grid[i][j] = 0;
            parking_lot.parked_vehicle_info[i][j] = malloc(sizeof(char) * 11);
        }
    }

    parking_lot.free_parking_spaces = 260;
    parking_lot.occupied_parking_spaces = 0;


    while (true)
    {
        printf("\t\t\t\t ************************************\n");
        printf("\t\t\t\t\t Parking System\n");
        printf("\t\t\t\t ************************************\n");

        printf("1. Park vehicle in Parking lot\n");
        printf("2. Remove vehicle from Parking lot\n");
        printf("3. Find your vehicle in Parking lot\n");
        printf("4. Display Parking lot\n");
        printf("5. Parking lot Info\n");
        printf("6. Parked vehicles Info\n");

        int choice;
        printf("Please select: ");
        if (scanf("%d", &choice) != 1)
        {
            printf(":( could not read integer\n");
            return 1;
        }

        if (choice == 1)
        {
            if (parking_lot.free_parking_spaces > 0)
            {
                printf("\t *********** Park Vehicle ***********\n");

                char *vehicle_plate = malloc(sizeof(char) * 11);
                printf("Enter vehicle plate: ");
                if (scanf("%s", vehicle_plate) != 1)
                {
                    printf(":( could not read vehicle plate number\n");
                }

                char *vehicle_type = malloc(sizeof(char) * 11);
                printf("Enter vehicle type: ");
                if (scanf("%s", vehicle_type) != 1)
                {
                    printf(":( could not read vehicle type\n");
                }

                Vehicle vehicle;
                vehicle.vehicle_plate = vehicle_plate;
                vehicle.vehicle_type = vehicle_type;

                time_t car_enter_time = time(NULL);
                printf("Vehicle entered parking at: %s\n", asctime(localtime(&car_enter_time)));

                int row, col;
                printf("Enter position where you want to park your vehicle: ");
                if (scanf("%d,%d", &row, &col) != 2)
                {
                    printf(":( could not read position\n");
                }

                if (row > 25 || row < 0 || col > 9 || col < 0)
                {
                    printf(":( invalid postion to park try again\n");
                }

                if (parking_lot.parking_grid[row][col] == 1)
                {
                    printf(":( vehicle already parked at this position, try another position\n");
                }

                parking_lot.parking_grid[row][col] = 1;
                strcpy(parking_lot.parked_vehicle_info[row][col], vehicle_plate);
                parking_lot.occupied_parking_spaces++;
                parking_lot.free_parking_spaces--;

                free(vehicle_plate);
                free(vehicle_type);
            }
            else
            {
                printf(":( Sorry, no more parking space available!\n");
            }
        }

        else if (choice == 2)
        {
            if (parking_lot.occupied_parking_spaces < 1)
            {
                printf("Parking lot already empty!\n");
            }
            else
            {
                printf("\t *********** Withdraw Vehicle ***********\n");

                char *vehicle_plate = malloc(sizeof(char) * 11);
                printf("Enter vehicle plate: ");
                if (scanf("%s", vehicle_plate) != 1)
                {
                    printf(":( could not read plate number\n");
                }

                int row, col;
                printf("Enter postion where vehicle is parked: ");
                if (scanf("%d,%d", &row, &col) != 2)
                {
                    printf(":( could not read the position of vehicle\n");
                }

                if (row > 25 || row < 0 || col > 9 || col < 0)
                {
                    printf(":( Invalid position\n");
                }

                if (parking_lot.parking_grid[row][col] == 1 &&
                    strcmp(vehicle_plate, parking_lot.parked_vehicle_info[row][col]) == 0)
                {
                    time_t car_exit_time = time(NULL);
                    printf("Vehicle exiting parking at: %s\n", asctime(localtime(&car_exit_time)));

                    parking_lot.parking_grid[row][col] = 0;
                    strcpy(parking_lot.parked_vehicle_info[row][col], "");
                    parking_lot.free_parking_spaces++;
                    parking_lot.occupied_parking_spaces--;
                }
                else
                {
                    printf("Vehicle Plate or Position does not match\n");
                }

                free(vehicle_plate);
            }
        }

        else if (choice == 3)
        {
            printf("\t *********** Searching Vehicle ***********\n");

            char *vehicle_plate = malloc(sizeof(char) * 11);
            printf("Enter vehicle plate number: ");
            if (scanf("%s", vehicle_plate) != 1)
            {
                printf(":( could not read vehicle plate number\n");
            }

            Parking_Position position = find_vehicle(parking_lot, vehicle_plate);
            if (position.row_position == -1 && position.column_position == -1)
            {
                printf(":( No such vehicle found in parking lot\n");
            }
            else
            {
                printf("Vehicle found parked at: %c,%d\n", (char) (position.row_position + 65),
                       position.column_position + 1);
            }

            free(vehicle_plate);
        }

        else if (choice == 4)
        {
            display_parking(parking_lot);
        }

        else if (choice == 5)
        {
            printf("\t *********** Parking Lot Info ***********\n");

            printf("Free Parking Spaces: %d\n", parking_lot.free_parking_spaces);
            printf("Occupied Parking Spaces: %d\n", parking_lot.occupied_parking_spaces);
            printf("Total Capacity: %d\n", 260);
        }

        else if (choice == 6)
        {
            printf("\t *********** Parked Vehicles Info ***********\n");

            int count = 0;
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (parking_lot.parking_grid[i][j] == 1)
                    {
                        printf("%d. Vehicle: %s, Parked at: %c,%d\n", count + 1,
                               parking_lot.parked_vehicle_info[i][j], (char) (i + 65), j + 1);
                        count++;
                    }
                }
            }

            if (count == 0)
            {
                printf("No vehicles parked yet!\n");
            }
        }

        else
        {
            printf("Invalid Choice\n");
            return 1;
        }
    }
    return 0;
}

Parking_Position find_vehicle(Parking_lot parking_lot, char *vehicle_plate)
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (strcmp(parking_lot.parked_vehicle_info[i][j], vehicle_plate) == 0)
            {
                Parking_Position parking_position;
                parking_position.row_position = i;
                parking_position.column_position = j;
                return parking_position;
            }
        }
    }

    Parking_Position parking_position;
    parking_position.row_position = -1;
    parking_position.column_position = -1;
    return parking_position;
}

void display_parking(Parking_lot parking_lot)
{
    char serial[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                       'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    printf("\t *********** Parking Lot ***********\n");
    printf("  ");

    for (int k = 0; k < 10; k++)
    {
        printf("  %d   ", k + 1);
    }
    printf("\n");

    for (int i = 0; i < 26; i++)
    {
        printf("%c ", serial[i]);
        for (int j = 0; j < 10; j++)
        {
            printf("[ %d ] ", parking_lot.parking_grid[i][j]);
        }
        printf("\n");
    }
}
