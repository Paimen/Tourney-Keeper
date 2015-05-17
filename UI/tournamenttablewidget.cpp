#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

#include "tournamenttablewidget.h"
#include "player.h"



TournamentTableWidget::TournamentTableWidget(QWidget *parent) : QWidget(parent), m_mainLayout(new QGridLayout)
{
    m_ready = new QPushButton;
    m_ready->setText(tr("Confirm"));
    m_mainLayout->addWidget(m_ready,0,2);

    m_modify = new QPushButton;
    m_modify->setText(tr("Modify"));
    m_mainLayout->addWidget(m_modify,1,2);
    setLayout(m_mainLayout);
}

TournamentTableWidget::~TournamentTableWidget()
{

}

/*!
 * \brief adds player to table
 * \param player player to be added
 */
void TournamentTableWidget::addPlayer(Player *player)
{
    ///\todo this is just for testing, seating should come from Swiss engine, most propably whole player list
    /// with seating order
    player->setTablePosition(m_players.count());

    m_players.append(player);
}

void TournamentTableWidget::setPlayers(QList<Player *> players)
{
    m_players = players;
    addPlayersToLayout();
}


/*!
 * \brief helper functtion to populate layout with players
 */
void TournamentTableWidget::addPlayersToLayout()
{
    if(m_players.count() > 0) {
        foreach(Player* player, m_players) {
            if (player->tableId() == m_tableId) {
                QLabel *label = new QLabel;
                label->setText(player->name());
                m_mainLayout->addWidget(label,player->tablePosition(),0);
            }
        }
    }
}
QUuid TournamentTableWidget::tableId() const
{
    return m_tableId;
}

void TournamentTableWidget::setTableId(const QUuid &tableId)
{
    m_tableId = tableId;
}



