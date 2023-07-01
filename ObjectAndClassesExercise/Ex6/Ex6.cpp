#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Splender
{
    //Members
    char** m_oMap;
    pair<int, int> m_oCurrPos;
    pair<int, int> m_oT1Pos;
    pair<int, int> m_oT2Pos;
    bool m_bInReverseMove;
    bool m_bInBreakerMode;
    bool m_bInSouthMove;
    bool m_bInEastMove;
    bool m_bInNorthMove;
    bool m_bInWestMove;
    bool m_bIsDead;
    size_t m_nRows;

public:

    //Constructor/Destructor
    Splender(istream& iStr);
    ~Splender();

    //Getters/Seters
    pair<int, int> GetCurrPos() const;
    char GetCurrSymbol() const;
    bool IsReverse() const;
    bool IsBreaker() const;
    bool IsDead() const;
    void SwitchOnOffReverseMove(bool bSwitchOn);
    void SwitchOnOffBreakerMode(bool bSwitchOn);
    
    //Methods
    void Move();
    void TurnSouth();
    void TurnEast();
    void TurnNorth();
    void TurnWest();
    void Teleport();
    void MakeSuicide();

private:

    void MoveSouth();
    void MoveEast();
    void MoveNorth();
    void MoveWest();
    void NormalSwitch();
    void ReverseSwitch();
    bool CanMove(pair<int, int> oNextPos);
    void MeetObstacle();
    void BreakObstacle(pair<int, int> oNextPos);

};

Splender::Splender(istream& iStr)
    : m_bInReverseMove(false)
    , m_bInBreakerMode(false)
    , m_bInSouthMove(true)
    , m_bInEastMove(false)
    , m_bInNorthMove(false)
    , m_bInWestMove(false)
    , m_bIsDead(false)
    , m_oT1Pos(make_pair(0, 0))
    , m_oT2Pos(make_pair(0, 0))
{
    size_t nRows = 0, nCols = 0;
    iStr >> nRows >> nCols;
    iStr.ignore();

    m_oMap = new char* [nRows];
    m_nRows = nRows;

    for (size_t i = 0; i < nRows; i++)
    {
        m_oMap[i] = new char[nCols];

        string strRow;
        getline(iStr, strRow);

        for (size_t j = 0; j < nCols; j++)
        {
            m_oMap[i][j] = strRow.at(j);

            if (strRow.at(j) == '@')
                m_oCurrPos = make_pair(i, j);

            if (strRow.at(j) == 'T')
            {
                if (m_oT1Pos.first == 0 && m_oT1Pos.second == 0)
                {
                    m_oT1Pos.first = i;
                    m_oT1Pos.second = j;
                }
                else
                {
                    m_oT2Pos.first = i;
                    m_oT2Pos.second = j;
                }
            }
        }
    }
}

Splender::~Splender()
{
    for (size_t i = 0; i < m_nRows; i++)
        delete[] m_oMap[i];

    delete[] m_oMap;
}

pair<int, int> Splender::GetCurrPos() const
{
    return m_oCurrPos;
}

char Splender::GetCurrSymbol() const
{
    return m_oMap[m_oCurrPos.first][m_oCurrPos.second];
}

bool Splender::IsReverse() const
{
    return m_bInReverseMove;
}

bool Splender::IsBreaker() const
{
    return m_bInBreakerMode;
}

bool Splender::IsDead() const
{
    return m_bIsDead;
}

void Splender::SwitchOnOffReverseMove(bool bSwitchOn)
{
    m_bInReverseMove = bSwitchOn;
}

void Splender::SwitchOnOffBreakerMode(bool bSwitchOn)
{
    m_bInBreakerMode = bSwitchOn;
}

void Splender::Move()
{
    if (m_bInSouthMove)
    {
        pair<int, int> oNextPos = make_pair(m_oCurrPos.first + 1, m_oCurrPos.second);

        if (!CanMove(oNextPos))
        {
            MeetObstacle();
            return;
        }

        MoveSouth();
        return;
    }

    if (m_bInEastMove)
    {
        pair<int, int> oNextPos = make_pair(m_oCurrPos.first, m_oCurrPos.second + 1);

        if (!CanMove(oNextPos))
        {
            MeetObstacle();
            return;
        }

        MoveEast();
        return;
    }

    if (m_bInNorthMove)
    {
        pair<int, int> oNextPos = make_pair(m_oCurrPos.first - 1, m_oCurrPos.second);

        if (!CanMove(oNextPos))
        {
            MeetObstacle();
            return;
        }

        MoveNorth();
        return;
    }

    if (m_bInWestMove)
    {
        pair<int, int> oNextPos = make_pair(m_oCurrPos.first, m_oCurrPos.second - 1);

        if (!CanMove(oNextPos))
        {
            MeetObstacle();
            return;
        }

        MoveWest();
        return;
    }
}

void Splender::TurnSouth()
{
    m_bInSouthMove = true;
    m_bInEastMove = false;
    m_bInNorthMove = false;
    m_bInWestMove = false;
}

void Splender::TurnEast()
{
    m_bInSouthMove = false;
    m_bInEastMove = true;
    m_bInNorthMove = false;
    m_bInWestMove = false;
}

void Splender::TurnNorth()
{
    m_bInSouthMove = false;
    m_bInEastMove = false;
    m_bInNorthMove = true;
    m_bInWestMove = false;
}

void Splender::TurnWest()
{
    m_bInSouthMove = false;
    m_bInEastMove = false;
    m_bInNorthMove = false;
    m_bInWestMove = true;
}

void Splender::Teleport()
{
    if (m_oCurrPos == m_oT1Pos)
        m_oCurrPos = m_oT2Pos;
    else
        m_oCurrPos = m_oT1Pos;
}

void Splender::MakeSuicide()
{
    m_bIsDead = true;
}

void Splender::MoveSouth()
{
    m_oCurrPos.first += 1;
    cout << "SOUTH" << endl;
}

void Splender::MoveEast()
{
    m_oCurrPos.second += 1;
    cout << "EAST" << endl;
}

void Splender::MoveNorth()
{
    m_oCurrPos.first -= 1;
    cout << "NORTH" << endl;
}

void Splender::MoveWest()
{
    m_oCurrPos.second -= 1;
    cout << "WEST" << endl;
}

void Splender::NormalSwitch()
{
    pair<int, int> oNextPos = make_pair(m_oCurrPos.first + 1, m_oCurrPos.second);

    if (CanMove(oNextPos))
    {
        TurnSouth();
        MoveSouth();
        return;
    }

    oNextPos = make_pair(m_oCurrPos.first, m_oCurrPos.second + 1);

    if (CanMove(oNextPos))
    {
        TurnEast();
        MoveEast();
        return;
    }

    oNextPos = make_pair(m_oCurrPos.first - 1, m_oCurrPos.second);

    if (CanMove(oNextPos))
    {
        TurnNorth();
        MoveNorth();
        return;
    }

    oNextPos = make_pair(m_oCurrPos.first, m_oCurrPos.second - 1);

    if (CanMove(oNextPos))
    {
        TurnWest();
        MoveWest();
        return;
    }
}

void Splender::ReverseSwitch()
{
    pair<int, int> oNextPos = make_pair(m_oCurrPos.first, m_oCurrPos.second - 1);

    if (CanMove(oNextPos))
    {
        TurnWest();
        MoveWest();
        return;
    }

    oNextPos = make_pair(m_oCurrPos.first - 1, m_oCurrPos.second);

    if (CanMove(oNextPos))
    {
        TurnNorth();
        MoveNorth();
        return;
    }

    oNextPos = make_pair(m_oCurrPos.first, m_oCurrPos.second + 1);

    if (CanMove(oNextPos))
    {
        TurnEast();
        MoveEast();
        return;
    }

    oNextPos = make_pair(m_oCurrPos.first + 1, m_oCurrPos.second);

    if (CanMove(oNextPos))
    {
        TurnSouth();
        MoveSouth();
        return;
    }
}

bool Splender::CanMove(pair<int, int> oNextPos)
{
    if (m_oMap[oNextPos.first][oNextPos.second] == '#')
        return false;

    if (m_oMap[oNextPos.first][oNextPos.second] == 'X'
        && !m_bInBreakerMode)
        return false;

    if (m_oMap[oNextPos.first][oNextPos.second] == 'X'
        && m_bInBreakerMode)
        BreakObstacle(oNextPos);

    return true;
}

void Splender::MeetObstacle()
{
    if (!m_bInReverseMove)
    {
        NormalSwitch();
        return;
    }

    ReverseSwitch();
}

void Splender::BreakObstacle(pair<int, int> oNextPos)
{
    m_oMap[oNextPos.first][oNextPos.second] = ' ';
}


int main()
{
    Splender oMySplender(cin);

    while (true)
    {
        if (oMySplender.IsDead())
            break;

        oMySplender.Move();

        if (oMySplender.GetCurrSymbol() == '$')
            oMySplender.MakeSuicide();

        else if (oMySplender.GetCurrSymbol() == 'S')
            oMySplender.TurnSouth();

        else if (oMySplender.GetCurrSymbol() == 'E')
            oMySplender.TurnEast();

        else if (oMySplender.GetCurrSymbol() == 'N')
            oMySplender.TurnNorth();

        else if (oMySplender.GetCurrSymbol() == 'W')
            oMySplender.TurnWest();

        else if (oMySplender.GetCurrSymbol() == 'I')
        {
            if (!oMySplender.IsReverse())

                oMySplender.SwitchOnOffReverseMove(true);
            else
                oMySplender.SwitchOnOffReverseMove(false);
        }

        else if (oMySplender.GetCurrSymbol() == 'B')
        {
            if (!oMySplender.IsBreaker())
                oMySplender.SwitchOnOffBreakerMode(true);
            else
                oMySplender.SwitchOnOffBreakerMode(false);
        }

        else if (oMySplender.GetCurrSymbol() == 'T')
            oMySplender.Teleport();
    }

    return 0;
}
