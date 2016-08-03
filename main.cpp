/*

Name:	Gulnoza Khakimova
Course: CS 201R
Program: Percentage score for students.
Due Date:	02/14/2016
Description:  This program takes file and generate a new file with
percentage score for each student after exam2 (consisting of the assignments, 
exam 1, and exam 2) for the instructor record in the middle of the semester, 
percentage score for each student after final exam, and the final grade 
of each student.
Inputs:	Read the input file ("grade1"), choose calculation of persentage after 
two exams or after final exam or both.
Outputs: Student ID, assignment score, exam1 score, exam2 score, final exam score,  
percentages aftertwo exams and after final exam, letter grade, number of A's and B's.
Algorithm:
1- Define class TermGrade which will include different functions to get the percentage 
after exam2, percentage after final exam, and the overall grade of each student. Also
this class will define the variables needed in implementing the program. It will need 
the following methods:
a. ReadData(istream& in). This reads the ID number and scores 
(one line of data) from thefile. It returns true if the attempt to read data was 
successful, false otherwise.
b. MidsemseterScore(). It returns the average of the assignments and first two exams. It
returns a double. (Beware of integer division: 89/3 = 29; 89/3.0 = 29.66666667). This is a
const method.
c. FinalScore(). This returns the average of all grade components, as a double. This is a
const method.
d. LetterGrade(). This method returns ‘A’, ‘B’, ‘C’, ‘D’, or ‘F’ (character values). This is a
const method.
2- Input data from grade1.txt and output data to finalgrade.txt.
3- Add menu to the instructor to choose (1- percent after exam 2, 2- percent after final exam, 3- all
the above).
4- Assignments weight 20%, Exam1 weight 25%, Exam2 weight 25%, and Final exam weight 30%.
5- Calculate % after Exam 2 period, and after the final exam.
6- Include grade of students, grade depends on the final score percentage:
- A: Final percentage greater than or equal 90
- B: Final percentage between 80 and 90.
- C: Final percentage between 70 and 80.
- D: For other percentages.

*/

#include <iostream>
#include <fstream>
#include "TermGrade.h"
#include <array>
#include <string>
#include <iomanip>
#include <sstream>


using namespace std;

void outputData(string ValueToWrite);
int menu();

int main()
{
    // PRE: File "grade1.txt" must be located here:
    // "C:\\Users\\Gulnoza\\Documents\\UMKC2016\\CS201R\\Visual Studio\\Program2\\Debug\\grade1.txt"
    // if it is not there change the path on line 71.
    // POST: Output file "FinalGrade.txt" will be saved here:
    // "C:\\Users\\Gulnoza\\Documents\\UMKC2016\\CS201R\\Visual Studio\\Program2\\Debug\\finalgrade.txt"
    // change the location of output file as needed.
    // RETURNS: 0.
    string resultOutput = ""; //this will be the string with out output
    int choice = menu();
    
    //TermGrade arrOfTerms[100]; //used array class instaed (it has .size())
    array<TermGrade, 100> arrOfTerms;
    int i = 0;
    TermGrade S;
    
    ifstream fin("C:\\Users\\Gulnoza\\Documents\\UMKC2016\\CS201R\\Visual Studio\\Program2\\Debug\\grade1.txt");
   //ifstream fin("grade1.txt");
    
    while (S.ReadData(fin))
    {
        arrOfTerms[i] = S;
        //It is not used anywhere. Put it below to show that it is working
        double MidsemseterScore = S.MidsemseterScore();
        //FinalScore also not used anywhere
        double FinalScore = S.FinalScore();
        i++;
    }

    fin.close(); //close file
    
    
    int TotalAs=0;
    int TotalBs=0;

    
    //format string
    for (int i2 = 0; i2 < arrOfTerms.size() && arrOfTerms[i2].getID() > 0; i2++)
    {
            resultOutput += to_string(arrOfTerms[i2].getID());
            resultOutput += "\t";
            resultOutput += to_string(arrOfTerms[i2].getAssignmentScore());
            resultOutput += "\t";
            resultOutput += to_string(arrOfTerms[i2].getExam1());
            resultOutput += "\t"; 
            resultOutput += to_string(arrOfTerms[i2].getExam2());
            resultOutput += "\t";
            resultOutput += to_string(arrOfTerms[i2].getFinalExam());
            if (choice == 1)
            {
                resultOutput += "\tAfter exam 2 ";
                std::stringstream tmpString;
                tmpString << fixed << setprecision(2) << arrOfTerms[i2].afterExam2;
                resultOutput += tmpString.str() + " %";
                
            }
            else if (choice == 2)
            {
                resultOutput += "\tAfter final ";
                std::stringstream tmpString;
                tmpString << fixed << setprecision(2) << arrOfTerms[i2].finalPerc;
                resultOutput += tmpString.str() + " %";
            }
            else if (choice == 3)
            {
                resultOutput += "\tAfter exam 2 ";
                std::stringstream tmpString;
                tmpString << fixed << setprecision(2) << arrOfTerms[i2].afterExam2;
                resultOutput += tmpString.str() + " %";
                
                resultOutput += "\tAfter final ";
                std::stringstream tmpString2;
                tmpString2 << fixed << setprecision(2) << arrOfTerms[i2].finalPerc;
                resultOutput += tmpString2.str() + " %";        
            }
            resultOutput += "\tOverall grade is ";
            resultOutput += arrOfTerms[i2].LetterGrade();
            if (arrOfTerms[i2].LetterGrade() == 'A')
            {
                TotalAs++;
            }
            if (arrOfTerms[i2].LetterGrade() == 'B')
            {
                TotalBs++;
            }
            resultOutput += "\n";
    }
    resultOutput += "Total A's is ";
    resultOutput += to_string(TotalAs);
    resultOutput += "\nTotal B's is ";
    resultOutput += to_string(TotalBs);
    outputData(resultOutput);
    cout << "File saved." << endl;
    system("pause");
    return 0;
}

int menu()
{
    // PRE: None
    // POST: None
    // RETURNS: 1,2 or 3 depending on user's input.
    // Error checking: If user enters anything except 1,2 or 3
    // user is asked to enter a valid number.
    int choice = 0;
    int answer = 0;

    while (answer == 0)
    {
        cout << "Choose persentage score to calculate." << endl;
        cout << "1 - persentage after Exam 2." << endl;
        cout << "2 - persentage after Final exam." << endl;
        cout << "3 - all of the above." << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            answer = 1; break;
        case 2:
            answer = 2; break;
        case 3:
            answer = 3; break;
        default:
            cout << "Choose again." << endl;
            break;
        }
    }
    return answer;
}



void outputData(string ValueToWrite)
{
        // PRE: None
        // POST: File is saved in 
        // C:\\Users\\Gulnoza\\Documents\\UMKC2016\\CS201R\\Visual Studio\\Program2\\Debug\\finalgrade.txt"
        // if needed change path.
        // RETURNS: None
        // Error checking: None
     
   
    ofstream fout("C:\\Users\\Gulnoza\\Documents\\UMKC2016\\CS201R\\Visual Studio\\Program2\\Debug\\finalgrade.txt");
   
    fout << ValueToWrite;
    fout.close();
}


