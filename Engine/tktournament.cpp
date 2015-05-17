#include "tktournament.h"
#include "player.h"

#include <algorithm>
#include <random>
#include <QTime>
#include <QDebug>


TKTournament::TKTournament(QObject *parent) :
    QObject(parent), m_tournamentTableSize(2)
{
    // Seed the random generator with current time
    QTime time = QTime::currentTime();
    qsrand((uint)time.msecsSinceStartOfDay());
}
QList<Player *> TKTournament::tournamentPlayers()
{
    return m_tournamentPlayers;
}

void TKTournament::setTournamentPlayers(const QList<Player *> &tournamentPlayers)
{
    m_tournamentPlayers = tournamentPlayers;
}

bool TKTournament::generateRound(bool randomRound)
{
    m_activeTables.clear();
    if(m_tournamentPlayers.isEmpty()) {
        //Nothing to do no players yet
        return false;
    }



    return generateRandomRound();
}

bool TKTournament::generateRandomRound()
{
    //Create Mersenne twister engine, with random seed.
    std::mt19937 urng( qrand());
    //Shuffle the player list
    QList<Player*> roundPlayers = m_tournamentPlayers;
    std::shuffle(roundPlayers.begin(),roundPlayers.end(),urng);
    qDebug() << roundPlayers;
    qDebug() << m_tournamentPlayers;
    //assign table id's for player
    int divider =  0;
    QUuid tableId;
    foreach (Player* player, roundPlayers) {

        if ( divider == 0 ) {

            tableId = QUuid::createUuid();
            m_activeTables.append(tableId);
            qDebug() << tableId;
            divider ++;
        } else if( divider == m_tournamentTableSize-1){
            divider = 0;
        } else {
            divider ++;
        }
        player->setTableId(tableId);
        player->setTablePosition(divider);


    }



    return true;
}

QList<QUuid> TKTournament::activeTables() const
{
    return m_activeTables;
}


