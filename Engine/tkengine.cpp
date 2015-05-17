/*!
 * \brief This is main engine that handles all data in Tourney Keeper.
 *
 * This engine will list all tournaments and handles tournaments and players.
 *
 */

#include <QDebug>


#include "tkengine.h"
#include "tktournament.h"
#include "player.h"

/*!
 * \brief basic constructor
 * \param parent
 */


TKEngine::TKEngine(QObject *parent) :
    QObject(parent)
{
//lets just make some test players
    m_currentTournament = new TKTournament;
    Player *test;
    QList<Player *> players;
    for(int i = 0 ; i< 10 ; i++) {
        test = new Player;
        QString name(QString("Test %1").arg(i));
        test->setName(name);
        players.append(test);
    }
    m_currentTournament->setTournamentPlayers(players);
    m_currentTournament->generateRound(true);





}

TKTournament *TKEngine::currentTournament()
{
    return m_currentTournament;
}
