#include <iostream>
#include <fstream>
#include <cstdlib>
#include "TermGrade.h"
#include <sstream>
#include <iomanip>
#include <math.h>

using namespace std;


bool TermGrade::ReadData(istream& in) // reads data from input file
{
    // PRE: stream
    // POST: Values assigned in the class
    // RETURNS: True if success, false if not.
    // Error checking: None
    int data[5];

    if (in.eof() == true)
    {
        return false;
    }
        ID = assignmentScore = exam1 = exam2 = finalExam = 0;
        for (int i = 0; i < 5; i++)
        {
            in >> data[i];
            ID = data[0];
            assignmentScore = data[1];
            exam1 = data[2];
            exam2 = data[3];
            finalExam = data[4];            
        }
        finalPercCalcul();
        afterExam2Calcul();
        return true;
}


const double TermGrade::MidsemseterScore() // calculates average of 3 exams. 
{
        // PRE: None
        // POST: Average score is assigned.
        // RETURNS: Average score
        // Error checking: None
    double avrgScore = (assignmentScore + exam1 + exam2) / 3.0;
    return avrgScore;
    
}

const double TermGrade::FinalScore() // calculates average of all exams.
{
    // PRE: None
    // POST: Average score for all exams is assigned.
    // RETURNS: Average score of all exams
    // Error checking: None
    double avrgFinal = (assignmentScore + exam1 + exam2 + finalExam) / 4.0;
    return avrgFinal;
}

const char TermGrade::LetterGrade() // assign letter grade
{
    // PRE: None
    // POST: None
    // RETURNS: Letter grade
    // Error checking: None
    char charValue;
    if (finalPerc >= 90)
    {
        charValue = 'A';
    }
    else if (finalPerc < 90 && finalPerc >= 80)
    {
        charValue = 'B';
    }
    else if (finalPerc < 80 && finalPerc >= 70)
    {
        charValue = 'C';
    }
    else
    {
        charValue = 'D';
    }

    return charValue;
}

double TermGrade::finalPercCalcul() // calculate final percentage
{
    // PRE: None
    // POST: Final percentage is set
    // RETURNS: Final percentage
    // Error checking: None
    finalPerc = ((assignmentScore*0.20) + (exam1*0.25) + (exam2*0.25) + (finalExam*0.30));
    
  
    return finalPerc;
}

double TermGrade::afterExam2Calcul() // calculate percentage after 2 exams.
{
    // PRE: None
    // POST: Percentage after two exams is set
    // RETURNS: Percentage after two exams.
    // Error checking: None
    afterExam2 = ((assignmentScore*0.20) + (exam1*0.25) + (exam2*0.25));
    return afterExam2;
}
