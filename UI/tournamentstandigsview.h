#ifndef TOURNAMENTSTANDINGSVIEW_H
#define TOURNAMENTSTANDINGSVIEW_H

#include <QDockWidget>
#include <QWidget>

class Player;
class TKTournament;

class TournamentStandingsView : public QDockWidget
{
    Q_OBJECT
public:
    explicit TournamentStandingsView(TKTournament *tournament, QWidget *parent = 0);
    ~TournamentStandingsView();

signals:

public slots:

private:
    QList<Player *> m_players;
    TKTournament *m_tournament;
};

#endif // TOURNAMENTSTANDINGSVIEW_H
