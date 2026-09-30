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

#ifdef PRE_RELEASE
    string email;
#endif
};

int main()
{
	// vector to store student data
    vector<STUDENT_DATA> students;

   
    // select file based on prerelease
#ifdef PRE_RELEASE
    cout << "Running PRE-RELEASE version" << endl;
    ifstream inputFile("StudentData_Emails.txt");
#else
    cout << "Running STANDARD version" << endl;
    //open file
    ifstream inputFile("StudentData.txt");
#endif

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

            // Get the last name
            student.lastName = line.substr(0, commaPosition);

#ifdef PRE_RELEASE
            // find second comma
            size_t secondComma = line.find(',', commaPosition + 1);

            if (secondComma != string::npos)
            {
				// get first name
                student.firstName = line.substr(
                    commaPosition + 1,
                    secondComma - commaPosition - 1
                );

                // get email address
                student.email = line.substr(secondComma + 1);
            }
#else
           
            student.firstName = line.substr(commaPosition + 1);
#endif

            // add to vector
            students.push_back(student);
        }
    }

    // close file
    inputFile.close();

    // code will run only in debug mode
#ifdef _DEBUG

    cout << "DEBUG MODE - Student Information" << endl;
    cout << "--------------------------------" << endl;

    for (const STUDENT_DATA& student : students)
    {
        cout << "First Name: " << student.firstName
            << ", Last Name: " << student.lastName;

#ifdef PRE_RELEASE
        cout << ", Email: " << student.email;
#endif

        cout << endl;
    }

#endif

    return 0;
}