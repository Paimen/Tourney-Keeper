#include <QGridLayout>

#include "tournamenttablewidget.h"
#include "player.h"



TournamentTableWidget::TournamentTableWidget(QWidget *parent) : QWidget(parent), m_mainLayout(new QGridLayout)
{

}

TournamentTableWidget::~TournamentTableWidget()
{

}

/*!
 * \brief adds player to table
 * \param player player to be added
 */
TournamentTableWidget::addPlayer(Player *player)
{
    ///\todo this is just for testing, seating should come from Swiss engine, most propably whole player list
    /// with seating order
    player->setTablePosition(m_players.count());

    m_players.append(player);
}

void TournamentTableWidget::setPlayers(QList<Player *> &players)
{
    m_players = players;
}

/*!
 * \brief helper functtion to populate layout with players
 */
TournamentTableWidget::addPlayersToLayout()
{

}


