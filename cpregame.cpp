#include "cpregame.h"
#include "stdlib.h"

CPreGame::CPreGame():m_allNum(26)
{
    m_questionArray.resize(m_allNum);
    GenarateQuestion();
}
OperatorS getOperatorSValue(int value) {
    if (value == 0) {
        return OperatorS::Add;
    } else if (value == 1) {
        return OperatorS::Sub;
    }
    return OperatorS::Add;

}

void CPreGame::GenarateQuestion()
{
    srand(time(NULL)); // 使用当前时间作为种子
    for(int i=0;i<m_allNum;i++)
    {
        //随机生成num1
        m_questionArray[i].num1 = rand()%10;
        //随机生成操作符
        m_questionArray[i].operatorS = getOperatorSValue(rand()%2);
        //随机生成num2
        switch(m_questionArray[i].operatorS)
        {
        case OperatorS::Add:
            m_questionArray[i].num2 = rand() % (10 - m_questionArray[i].num1);
            break;
        case OperatorS::Sub:
            m_questionArray[i].num2 = rand() % ( m_questionArray[i].num1 + 1);
            break;
        }
        if(m_questionArray[i].num2 == 0 && m_questionArray[i].num1==0)
        {
            i--;
            continue;
        }
    }

}

bool CPreGame::RightOrWrong( int index, int temp_answer)
{
    switch(m_questionArray[index].operatorS)
    {
    case OperatorS::Add:
        if(m_questionArray[index].num1 + m_questionArray[index].num2  == temp_answer)
            return true;
    case OperatorS::Sub:
        if(m_questionArray[index].num1 - m_questionArray[index].num2  == temp_answer)
            return true;
    }
    return false;
}

int CPreGame::GetTotalNum()
{
    return m_allNum;
}

void CPreGame::PrintEquation(int index)
{
    cout<<"the index is "<<index<<" : ";
    switch(m_questionArray[index].operatorS)
    {
    case OperatorS::Add:
        cout<<m_questionArray[index].num1<<" + "<<m_questionArray[index].num2<<endl;
        return;
    case OperatorS::Sub:
        cout<<m_questionArray[index].num1<<" - "<<m_questionArray[index].num2<<endl;
        return;
    }

}
