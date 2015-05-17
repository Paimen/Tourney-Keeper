#ifndef TOURNAMENTTABLESVIEW_H
#define TOURNAMENTTABLESVIEW_H

#include <QWidget>

class QGridLayout;
class TournamentTableWidget;
class TKTournament;

class TournamentTablesView : public QWidget
{
    Q_OBJECT
public:
    explicit TournamentTablesView(TKTournament *tournament, QWidget *parent = 0);
    ~TournamentTablesView();

signals:

public slots:

private: // functions

private: //member variables

    QGridLayout *m_mainLayout;
    QList<TournamentTableWidget *> m_tables;
    TKTournament* m_tournament;


};

#endif // TOURNAMENTTABLESVIEW_H
