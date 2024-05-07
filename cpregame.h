#ifndef CPREGAME_H
#define CPREGAME_H
#include <iostream>
#include <vector>
using namespace std;
enum OperatorS { Add = 0, Sub };

struct question
{
    int num1;
    OperatorS operatorS;
    int num2;
};


typedef  vector<question> QuestionArray;

class CPreGame
{
public:
    CPreGame();
    bool RightOrWrong( int index,int temp_answer = 10);
    int GetTotalNum();
    void PrintEquation(int dex);

private:
    void GenarateQuestion();
    int m_rightNum;
    int m_allNum;
    QuestionArray m_questionArray;
};

#endif // CPREGAME_H
