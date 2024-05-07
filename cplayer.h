#ifndef CPLAYER_H
#define CPLAYER_H

class CPlayer
{
public:
    CPlayer();
    void SetLevel(int level);

private:
    int m_level;
    int m_sec;
};

#endif // CPLAYER_H
// 当前等级
// 正确题数
// 总题数 目前共计26道
// 题目       堆栈
    // 第一个数
    // 运算符 +/-
    // 第二个数
// 正确答案     堆栈
// 玩家答案
// 当前秒数
