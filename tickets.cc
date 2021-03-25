/*
 *        File: tickets.cc
 *      Author: Anthony DeLuca
 *        Date: 03/23/21
 * Description: Tickets
 */

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>


using namespace std;

// function prototypes
void numviolations(int &count, string userlicense, string num);
bool isValid (string num);
string toUpperCase(string num);
int search(const string licenses[], string &target, int &count);
void print(string userlicense, int &occurr, int &countt);

int main(int argc, char const *argv[]) {
    string filename;
    ifstream inStream;
    string num;
    string licenses[32];
    int countt;
    string userlicense;
    int occurr =0;



    cout << "Enter the data file name: ";
    cin >> filename;
    inStream.open(filename);
    if (inStream.fail()){
        cout << "Error opening the file";
        exit(0);
        }
//Asks for file





    while(userlicense != "Q" && userlicense != "q"){

    cout << "Enter your license #: ";
    cin >> userlicense;

    toUpperCase(userlicense);
//Calls uppercase conversion function

    isValid(userlicense);
//Calls function to verify if the license is valid

    if(isValid(userlicense) == false){
        if(userlicense != "Q" && userlicense != "q"){
        cout << "Error: " << userlicense << " is an invalid license number." << endl;
        exit(0);
        }
    }
    

    inStream >> num;
    for (int i = 0; i <32; i++){
        licenses[i] = num;
        inStream >> num;
    }
//Reading the data and converting to array

    for (int i = 0; i < 32; i++){ 
        numviolations(countt, userlicense, licenses[i]);
    }


    search(licenses, userlicense, occurr);
    if(occurr == 0){
        return 0;
    }
//Calls search function to find number of occurrances

    print(userlicense, occurr, countt);

//Calls print function
    }
//End of loop

cout << "There are 3 suspended licenses.";

    
}  // main




void numviolations(int &count, string userlicense, string num){
    if(toUpperCase(num) == toUpperCase(userlicense)){
        count++;
    }
}


string toUpperCase(string num){
    char ch;
    string new_num;
    int length = num.length();
    for(int i = 0; i< length; i++){
        ch = num[i];
        if (isalpha(ch) && islower(ch)){
            new_num += toupper(ch);
        }
        else{
            new_num += ch;
        }
    }
    return new_num;
}


bool isValid (string num){
    if(num.length() !=8){
        return false;
    }
    else if (!isalpha(num[0]) || !isalpha(num[1]) || !isdigit(num[2]) || !isdigit(num[3]) || !isdigit(num[4]) || !isdigit(num[5]) || !isdigit(num[6]) || !isdigit(num[7])){
        return false;
    }
    else{
        return true;
    }
}


int search(const string licenses[], string &target, int &count){
    for (size_t i = 0; i < 32; i++)
    {
        if (toUpperCase(target) == toUpperCase(licenses[i]))
        {
            
            count++;
        }
    } return count;
    
}

void print(string userlicense, int &occurr, int &countt){
    cout << "Driver license " << userlicense << " has " << occurr << " violations." << endl;
        if(occurr == 0){
            cout << "License not found." << endl;
        }

    if(countt >= 6){
            cout << "Driver license " << userlicense << " should be suspended." << endl;
    }




}