#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// struct to store student data
struct STUDENT_DATA
{
    string firstName;
    string lastName;
};

int main()
{
	// vector to store student data
    vector<STUDENT_DATA> students;

    // opens file
    ifstream inputFile("StudentData.txt");

	// checck if file is open
    if (!inputFile.is_open())
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    string line;

	// read file line by line
    while (getline(inputFile, line))
    {
		// comma between first and last name
        size_t commaPosition = line.find(',');

        if (commaPosition != string::npos)
        {
            STUDENT_DATA student;

            // separate first and last name
            student.firstName = line.substr(0, commaPosition);
            student.lastName = line.substr(commaPosition + 1);

            // Add student to vector
            students.push_back(student);
        }
    }

    // close file
    inputFile.close();

    return 0;
}