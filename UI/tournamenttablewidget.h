#ifndef TOURNAMENTTABLEWIDGET_H
#define TOURNAMENTTABLEWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QUuid>


class QGridLayout;
class QPushButton;
class QLabel;
class QComboBox;

class Player;




class TournamentTableWidget : public QGroupBox
{
    Q_OBJECT
public:
    explicit TournamentTableWidget(QWidget *parent = 0);
    ~TournamentTableWidget();



    QUuid tableId() const;
    void setTableId(const QUuid &tableId);

    int tablePosition() const;
    void setTablePosition(int tablePosition);

signals:

public slots:
    void addPlayer(Player *player);
    void setPlayers(QList<Player *> players);

private: //Functions
    void addPlayersToLayout();


private: //Member variables
    QUuid m_tableId;
    QGridLayout *m_mainLayout;
    QList<Player *> m_players;
    QPushButton *m_ready;
    QPushButton *m_modify;
    QList<QComboBox*> m_playerRows;
    int m_tablePosition;

};

#endif // TOURNAMENTTABLEWIDGET_H
