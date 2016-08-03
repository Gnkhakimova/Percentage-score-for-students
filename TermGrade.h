#include <iostream>
#include <fstream>

using namespace std;


class TermGrade
{
    // PRE: None
    // POST: None
    // RETURNS: None
 
private: // initialize variables
    int ID;
    int assignmentScore;
    int exam1;
    int exam2;
    int finalExam;
    
public: // initialize variables
    double finalPerc;
    double afterExam2;
   
    // functions prototypes
    bool ReadData(istream& in); 
    const double MidsemseterScore();
    const double FinalScore();
    const char LetterGrade();
    double finalPercCalcul();
    double afterExam2Calcul();
    string menu();
    
    // getters and setters
    void setID(int _ID) 
    {
        ID = _ID;
    }
    
    int getID()
    {
        return ID;
    }

    void setAssignmentScore(int _AssigmentScore)
    {
        assignmentScore = _AssigmentScore;
    }
    int getAssignmentScore()
    {
        return assignmentScore;
    }

    void setExam1(int _exam1)
    {
        exam1 = _exam1;
    }
    int getExam1()
    {
        return exam1;
    }

    void setExam2(int _exam2)
    {
        exam2 = _exam2;
    }
    int getExam2()
    {
        return exam2;
    }

    void setFinalExam(int _finalExam)
    {
        finalExam = _finalExam;
    }
    int getFinalExam()
    {
        return finalExam;
    }


};