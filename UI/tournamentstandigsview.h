#ifndef TOURNAMENTSTANDINGSVIEW_H
#define TOURNAMENTSTANDINGSVIEW_H

#include <QDockWidget>
#include <QWidget>

class TournamentStandingsView : public QDockWidget
{
    Q_OBJECT
public:
    explicit TournamentStandingsView(QWidget *parent = 0);
    ~TournamentStandingsView();

signals:

public slots:
};

#endif // TOURNAMENTSTANDINGSVIEW_H
