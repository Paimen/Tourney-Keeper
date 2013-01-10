#ifndef TOURNAMENTSELECTOR_H
#define TOURNAMENTSELECTOR_H

#include <QDialog>

class QPushButton;
class QComboBox;

class TournamentSelector : public QDialog
{
    Q_OBJECT
    
public:
    explicit TournamentSelector(QWidget *parent = 0);
    ~TournamentSelector();

signals:
    void openNewTournament();

private slots:
    void newTournamentClicked();



private:

QPushButton *m_newTournamentButton;
QPushButton *m_openTournamentButton;
QComboBox *m_tournamentListComboBox;

};


#endif // TOURNAMENTSELECTOR_H
