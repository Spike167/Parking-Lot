# Parking System Project
![Screenshot of the running program](/C_project/parking_project.jpg)

# Video url of Project display
A short video to display the program running and accessing it's functionalities, all of them one by one, Along with the user details and GitHub Id, Date and Place [CS50 Parking Project](https://youtu.be/K52JUyQUNuQ)


# Description of Project:
This is a command line program in C to replicate a Real World Parking System for practice, real-world usage and implementation of theoritical knowledge into practical implications.


# Functionalities of Project:
1. You can park vehicles in the pre defined parking lot as defined in the codebase at your preffered postion.
2. You can remove vehicles from the parking lot at specified positions.
3. You can find your particular vehicle if you forgot where you parked it, just like in real life.
4. You can also display occupied and free parked spaces of the parking lot .
    [1] representing occupied space and [0] representing free space
5. You can also display information about the parking lot like total parking capacity, free parking spaces etc.
6. You can also display information of vehicles parked in the parking lot.


# User Defined structs in the Program
##   struct Parking_Position
User defined struct to replicate a real world position(co-ordinates) in two dimension, having two attributes the row and the column.

## struct Vehicle
User defined struct to replicate a real world vehicle with properties being the type of the vehicle and the vehicle plate/registration number.

##   struct Parking_lot
User defined struct to replicate a real world parking lot of size 26 X 10 to park cars.
Holds many attributes such has total parking space, the grid representing the parking lot (2D Array).
Data structures to hold the vehicle information of the vehicles parked and others.

# Functions Defined
1. display_parking: A function defined by the user to print the parking lot to give the user a visual representation of an actual parking grid, with each row named A to Z and every column numbered 1 to 10.

2. find_vehicle: Another user defined function that is used to find the postion where the particular vehicle is parked in the parking grid. It returns an object of type struct Parking_Postion defined in the beginning of the code file, containing attributes to define the particular row and column where the car has been parked based on searching the value of vehicle plate/registration number of the owner's car in the grid. Representing a real-world scenario where the owner foregts where he/she has parked his/her vehicle, which is also a functionality defined in this program.

# Header files used in the Project
1. <stdio.h> for basic input and output in the program.
2. <stdlib.h> for allocating memories to user defined structs and variables.
3. <string.h> for using string manipulating functions on string objects defined as (char *) equivalent to a string.
4. <time.h> to use time/date utilities for keeping a record when was the vehicle parked and when did it left the parking lot.
5. <stdbool.h> to use booleans in the program.
