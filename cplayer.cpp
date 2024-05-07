#include "cplayer.h"

CPlayer::CPlayer():
    m_level(1)
{}

void CPlayer::SetLevel(int level)
{
    m_level = level;
}
