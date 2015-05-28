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
    QStringList playerNames;
    playerNames << "Jukka" << "Heikki" << "Jeppe" << "Matti" << "Santtu" << "Riina"  << "Emmi" << "Ansa" << "Tapani" << "Katri";
    for(int i = 0 ; i< 10 ; i++) {
        test = new Player;
        test->setName(playerNames.at(i));
        players.append(test);
    }
    m_currentTournament->setTournamentPlayers(players);
    m_currentTournament->generateRound(true);


}

TKTournament *TKEngine::currentTournament()
{
    return m_currentTournament;
}
