#ifndef TOURNAMENTTABLEWIDGET_H
#define TOURNAMENTTABLEWIDGET_H

#include <QWidget>



class QGridLayout;
class QPushButton;

class Player;


class TournamentTableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TournamentTableWidget(QWidget *parent = 0);
    ~TournamentTableWidget();



signals:

public slots:
    addPlayer(Player *player);
    void setPlayers(QList<Player *> &players);

private: //Functions
    addPlayersToLayout();


private: //Member variables
    QGridLayout *m_mainLayout;
    QList<Player *> m_players;

};

#endif // TOURNAMENTTABLEWIDGET_H
