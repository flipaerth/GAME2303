// Austin Ozan
// GAME 2303
// Week 3 Assignment

/*
* OBJECTIVE *

- You need to create a class called Student that holds a student's first name, last name, and grade

- Your program should be able read a file that looks like the file "example.txt" included below.
  It should contain names of students and their grades, and resemble something like:
  
  Dave Grohl 95
  Taylor Hawkins 75

- Your program should read each line from the text file, and store that line's data in a 
  Student object (which should then be added to a vector of Students). You'll need to break 
  down each line into the proper components (a firstName, lastName, and grade) by using string 
  functions we previously discussed.

- Once you've gotten each student into your list, sort it by highest grade to lowest, 
  and display the sorted list of students with their grades. Also print out the average grade.
  Your output should look something like:
  
  Dave Grohl: 95
  Chris Shiflett: 90
  Rami Jaffee: 85
  Nate Mendel: 80
  Taylor Hawkins: 75
  Pat Smear: 70
  
  Average: 82
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Student {
private:
	string firstName;
	string lastName;
	int grade;

public:
	// Setter for first name
	void SetFirst(string f) {
		firstName = f;
	}

	// Setter for last name
	void SetLast(string l) {
		lastName = l;
	}

	// Setter for grade
	void SetGrade(int g) {
		grade = g;
	}

	// Getter for first name
	string GetFirst() {
		return firstName;
	}

	// Getter for last name
	string GetLast() {
		return lastName;
	}

	// Getter for grade
	int GetGrade() {
		return grade;
	}

};

int main()
{
	// Create Vector
	vector<string> students;

	// Opens the example text file
	ifstream studentFiles("example.txt");

	// Variable to hold each string in as the file is stepped through
	string currentLine;

	// Create Object
	Student info;

	// Variables
	int numStudents = 0;
	int average = 0;
	int total = 0;

	// If the file is open, we can write to it
	if (studentFiles.is_open())
	{
		// Reads and outputs each line from the file
		while (getline(studentFiles, currentLine)) {

			// Adds 1 to the total number of students per iteration
			numStudents += 1;

			// Adds the current line to the vector of students
			students.push_back(currentLine);

			// Finds the first space
			int firstSpace = currentLine.find(" ");
			// Sets the first name
			info.SetFirst(currentLine.substr(0, firstSpace));
			// Removes the first name after setting it
			currentLine.erase(0, firstSpace + 1);

			// Finds the second space
			int secondSpace = currentLine.find(" ");
			// Sets the last name
			info.SetLast(currentLine.substr(0, secondSpace));
			// Removes the last name after setting it
			currentLine.erase(0, secondSpace + 1);

			// Converts the remainder of the string to an int and sets to grade
			info.SetGrade(stoi(currentLine));

			total += info.GetGrade();
		}

		// Closes the file
		studentFiles.close();
	}
	// Validation if the file cannot be opened
	else
	{
		cout << "Unable to open the student's files." << endl;
	}

	// Display the vector list
	for (int i = 0; i < students.size(); i++) {
		cout << students[i] << endl;
	}

	// Average formula
	average = total / numStudents;

	// Display
	cout << endl;
	cout << "Average: " << average << endl;

	return(0);
}