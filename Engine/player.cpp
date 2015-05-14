#include "player.h"

Player::Player(QObject *parent) : QObject(parent), m_name("player"), m_points(0), m_sos(0), m_playedGames(0)
{

}

Player::~Player()
{

}
QString Player::name() const
{
    return m_name;
}

void Player::setName(const QString &name)
{
    m_name = name;
}
int Player::points() const
{
    return m_points;
}

void Player::setPoints(int points)
{
    m_points = points;
}
int Player::sos() const
{
    return m_sos;
}

void Player::setSos(int sos)
{
    m_sos = sos;
}
int Player::playedGames() const
{
    return m_playedGames;
}

void Player::setPlayedGames(int playedGames)
{
    m_playedGames = playedGames;
}

/*!
 * \brief gets position in table
 * \return position as integer
 */
int Player::tablePosition() const
{
    return m_tablePosition;
}

/*!
 * \brief basic setter for players table position
 * \param tablePosition as integer
 */
void Player::setTablePosition(int tablePosition)
{
    m_tablePosition = tablePosition;
}
QUuid Player::tableId() const
{
    return m_tableId;
}

void Player::setTableId(const QUuid &tableId)
{
    m_tableId = tableId;
}







