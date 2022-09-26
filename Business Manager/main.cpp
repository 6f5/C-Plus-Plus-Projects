//==========================================================
//
// Author:     Abdulla Saeed
// Date:       12 November 2021
// Description:
//   This C++ console application manages information about
// businesses.  This application requires five files:
//   -This file
//   -AbstractClassBusiness-Header.h
//   -AbstractClassBusiness-Implementation.cpp
//   -ClassFarm-Header.h
//   -ClassFarm-Implementation.cpp
//
//==========================================================
#include <cstdlib>  // For several general-purpose functions
#include <fstream>  // For file handling
#include <iomanip>  // For formatted output
#include <iostream>  // For cin, cout, and system
#include <string>  // For string data type
#include <vector>
#include "ClassFarm-Header.h"

using namespace std;  // So "std::cout" may be abbreviated to "cout", for example.

//----------------------------------------------------------
// Globals
//----------------------------------------------------------

// Declare constants
const string BORDER = "----------------------------------------";
const string INPUT_FILE_NAME = "inputFile.txt";
const int COLFMT1 = 14;
const int COLFMT2 = 7;

//----------------------------------------------------------
// static field initializations
//----------------------------------------------------------
int Farm::count = 0;
int Farm::totalAcres = 0;

// Function prototypes
void populateData(vector<Farm> &farms);
void showMenu();
void handleSelection(int option, vector<Farm> &farms);
void printBusinesses(vector<Farm> &farms);
void editBusiness(vector<Farm> &farms);
void clr();
void pauseClr();


//----------------------------------------------------------
// main
//----------------------------------------------------------
int main() {

  vector<Farm> farms;

  try {

    // Read data from file
    // then populate the data to the vector
    populateData(farms);

    while(true){

      // Declare variables
      int option = 0;

      // Display menu
      showMenu();

      // Ask for input
      cout << "Selection: ";

      // Save input into option variable
      cin >> option;

      // Check if user wants to exit
      if(option == 9){

        // Display exit message
        cout << "Exiting program." << endl;
        return 0;
      }

      // Pass selection to handler
      handleSelection(option, farms);
    }

  } catch(const char *ex){

    // Display error
    cout << ex << endl;

    // End program
    return 1;
  }

  // Show application close
  cout << "\nEnd of Business Manager" << endl;
}

void populateData(vector<Farm> &farms){

  // Declare variables
  ifstream inputFile;

  // open file
  inputFile.open(INPUT_FILE_NAME);

  // Check if file is open
  if(inputFile.is_open()){

    // Declare variables
    string line;
    string mainCrop;
    int acres = 0;
    int linesRead = 0;

    // Tell user we're reading data from file
    cout << "\nReading lines from file '" << INPUT_FILE_NAME << "' ...\n"
    << endl;


    // Read each line until we reach EOF
    while(inputFile.good()){

      // Reading line and storing it in 'line' variable
      getline(inputFile, line);

      // Skip first line
      if(!linesRead){
        linesRead++;
        continue;
      }

      // Parse first column
      mainCrop = line.substr(0,COLFMT1);

      // Parse second column
      // stoi: converts string to int
      acres = stoi(line.substr(COLFMT1, COLFMT2));

      // Insert data into vector
      farms.emplace_back(mainCrop, acres);

      // Increment linesRead by 1
      linesRead++;
    }

    // Tell user how many lines we read from file
    cout << linesRead << " line(s) read from file '" << INPUT_FILE_NAME
    << "'.\n" << endl;

    // Close file
    inputFile.close();

  } else {

    // throw error if failed to open file
    throw string {"Error: Failed to open file: "} + INPUT_FILE_NAME;
  }

}

void showMenu(){
  // Show application header
  cout << "Welcome to Business Manager" << endl;
  cout << BORDER << endl;
  cout << "Business Manager Menu" << endl;
  cout << "1 - Print businesses" << endl;
  cout << "2 - Edit business" << endl;
  cout << "9 - Exit" << endl;
}

void printBusinesses(vector<Farm> &farms){
  cout << endl;
  cout << setw(COLFMT2) << left << "ID" << setw(COLFMT1) << left
  << "Business" << setw(COLFMT1) << left << "Main crop" << setw(COLFMT2)
  << right << "Acres" << endl;

  // Check if vector is empty
  if(farms.empty()){
    cout << "No data yet" << endl;

    // Pause and clear screen to make screen less cluttered
    pauseClr();
  } else {
    int id = 0;
    for(const auto &f: farms){
      cout << setw(COLFMT2) << left << id << setw(COLFMT1) << left
           << f.getType() << setw(COLFMT1) << left << f.getMainCrop() << setw(COLFMT2)
           << right << f.getAcres() << endl;

      // Increment id by 1
      id++;
    }
  }
  cout << endl;

  // Pause and clear screen to make screen less cluttered
  pauseClr();
}

void handleSelection(int option, vector<Farm> &farms){

  switch(option){
    case 1:
    {
      // Display businesses
      printBusinesses(farms);
      break;
    }
    case 2:
    {
      // Edit businesses
      editBusiness(farms);
      break;
    }
    default:
    {
      cout << "\nInvalid selection. Try again.\n" << endl;
    }
  }
}

void pauseClr(){

  // Pause until user presses any key
  system("pause");

  // Clear screen to make it less cluttered (windows command)
  system("cls");
}

void editBusiness(vector<Farm> &farms){

  // Declare variables
  int id;

  while(true){
    // Ask for farm id
    cout << "Enter farm ID (-1 to exit): ";

    // Save input from user to 'id' variable
    cin >> id;

    // Check if user wants to exit
    if(id == -1){

      // Break the loop
      break;
    }

    // Check if 'id' is >= 0 and < farms.size()
    if(id >= 0 && id < farms.size()){

      // Access the farm object using 'at' method
      // and call setInfo object method
      farms.at(id).setInfo();

      // Tell user that the update was successful
      cout << "\nUpdated farm with id: '" << id <<"' successfully.\n"
      << endl;
    } else {

      // Tell user that the there's not farm with id provided
      cout << "\nError: No farm found with id '" << id << "'. Try again.\n" << endl;
    }
  }

  // Clear the screen
  clr();
}

void clr(){

  // Clear screen
  system("cls");
}
