# Flower Classifier

## About The Project

This project is the client-side of the Flower Classifier project. 
For further information on the project read the 
server's README.md which contains additional information. It can be found [here](https://github.com/yuvalgrofman/Ass_Two).

## The Client

This part of the README.md is dedicated to the client.

## Getting Started

### 1) Prerequisites

This project requires CMake (3.16 or above) in order to function properly.
To install CMake, follow the instructions [here](https://cmake.org/install/). In addition, a cpp compiler that supports c++11 is required.

### 2) Install And Run Project

Firstly, clone the project from the GitHub repository:

        git clone 'https://github.com/OldRimStalker/Ass_Two_Client'

Then, to run the project execute the following commands (in the terminal):

        mkdir -p build && cd build
        cmake ..
        make -j
        ./AssTwo.out <argument 1> <argument 2>


The first argument is the file path to a .csv file of unclassified flowers, 
while the second argument is the file path to the output csv file which contains the predicted file paths.

### 3) Set .csv Files

This project relies on two .csv files to properly function.

1. Unclassified.csv - contains the data of unclassified flowers.

This file contains the following columns (separated by a comma):

- width - the width of the flower
- sepal length - the length of the flower's sepal
- sepal width - the width of the flower's sepal
- petal length - the length of the flower's petal

2. Classified.csv - an empty file.

This file will contain the predicted flower types.

Both files can be placed anywhere in the computer and absolute paths as well as relative paths can be used. 
Note, that if relative paths are used, that they are relative to Ass_Two_Client\cmake-build-debug\AssOne.out 
because that is where the file will be run.
Although, we recommend placing the files in the Data and Output folders of the project. 

## Output

The output of the program is a csv file containing the predicted flower types.
The file is named: Classified.csv and is located in Ass_Two_Client/Output/Classified.csv.

## Algorithm

The algorithm works, by reading the classified.csv file thus creating a database of flowers.
Then it predicts every unpredicted flower using one of the distance functions, and a specified number of neighbours.
Subsequently, it sorts the database using merge sort, from closest to farthest (by distance).
Finally, it retrieves the k closest neighbours, finds their most common classification and returns aforementioned classification as the "predicted type".

## Authors

[Yuval Grofman](https://github.com/yuvalgrofman)

[Jonathan Moiseyev](https://github.com/OldRimStalker)