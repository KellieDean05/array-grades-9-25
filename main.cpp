// Kellie Henderson
//A program to work with arrays and functions.
#include <cstdlib> 
#include <iostream>
#include <iomanip>
#include <string>
#include "Input_Validation_Extended.h"
#include<sstream> //for string manipulation and comparison
using namespace std;

void welcomeMessage();
int letterCounter(string);
void inputGradesArray(double[] , double);
void printArray(double[], int); //pass array as parameter, and its size... void: cleaner call and does not return data
void sortArrDesc(double[], int);

int main() 
{
  int size = 0;
  welcomeMessage();

  
do
{  
  cout << "\nHow many Grades would you like to enter: ";
  size = validateInt(size);
  
  if(size < 0)
  {
    cout << "\nPlease enter a value greater than zero." << endl;
    
  }
}while(size < 0); //loop until you give me a positive number

    const int maxSize = size;
    double gradesArray[maxSize];
    inputGradesArray(gradesArray, maxSize);
    sortArrDesc(gradesArray, maxSize);
  

  return 0;

}

void welcomeMessage()
{
  string name ="teststring";
  cout << "\nPlease tell me your name : "<<endl;
  getline(cin, name);

  cout << "Welcome, " << name << endl;

  cout << letterCounter(name) << endl;
 
}

int letterCounter(string name) 
{
  string color="";
  int j=30;

  string reset = "\x1b[0m"; 
  
 for(int i =0; i < name.length(); i++)

 {
   color = "\x1b[" + to_string(j) + ";1m";

   cout << color; 
   cout << name[i] << "\n";
   cout << reset;
   j++; 
 } 

 cout << name << ", There are this many letters in your name: ";

 return name.length();

}

//function definition
void inputGradesArray(double array[], double size)
{

  double grade = 0.0; //my input storage variable
  double sum = 0.0;
  double average = 0.0;
  string reset = "\x1b[0m";
  string color = "\x1b[" + to_string(32) + ";7m"; //green and underline
  for(int i = 0; i < size; i++) //p1
  {
    do
   {
    cout << "\nPlease insert a grade number " << (i + 1) << " of " << size << ":" << endl;
    grade = validateDouble(grade);
    //stores the validated values in the array.
  if(array [i] < 0.00)
    {
     array[i] = grade;
     sum += array[i];
    }
    else
    {
      cout << "\nOnly numbers greater than 0.0 are allowed!" << endl;
    }
   }while(array[i] < 0.0);
  }

  average = sum/size ;

  cout << fixed << setprecision(4);
  cout << "The average of the " << size << " grades you entered is " << color << average << reset << endl;
  

}

//function definition
void sortArrDesc(double array[], int size)
{
  
  cout << "\nPrinted Descending Sorted Values: " << endl;
  int temp = 0; //needed for swap process
  for(int left = 0; left < size; left++)
  {

    for(int right = left + 1; right < size; right++)
    {
      //the swap magic happens here :)
      //Bubble sort: compare the left num to the right num
      //swap if neccessary.
      if(array[left] < array[right]) //hint > is ASC, and < is DESC
      {
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
      }

    }
  }
  //Print the array after sorting the array.
  printArray(array, size);
}

//function definitions.
void printArray(double array[], int size)
{
  string reset = "\x1b[0m";
  string color = "\x1b[" + to_string(32) + ";4m"; //green and underline

  //cout << "\nPrinted values: " << endl;
  //print the array values.
  for(int i = 0; i < size; i++)
  {
    cout << color << array[i] << reset << endl;
  }
}






