#ifndef TKTOURNAMENT_H
#define TKTOURNAMENT_H

#include <QObject>
#include <QUuid>

class Player;

class TKTournament : public QObject
{
    Q_OBJECT
public:
    explicit TKTournament(QObject *parent = 0);

    
    QList<Player *> tournamentPlayers();
    void setTournamentPlayers(const QList<Player *> &tournamentPlayers);

    QList<QUuid> activeTables() const;

signals:
    
public slots:
    bool generateRound(bool randomRound);

private: //Functions

    bool generateRandomRound();

private: //Member variables
    QList<Player *> m_tournamentPlayers;
    int m_tournamentTableSize;
    QList<QUuid> m_activeTables;

    
};

#endif // TKTOURNAMENT_H
