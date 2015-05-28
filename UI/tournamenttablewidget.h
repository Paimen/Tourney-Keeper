#ifndef TOURNAMENTTABLEWIDGET_H
#define TOURNAMENTTABLEWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QUuid>


class QGridLayout;
class QVBoxLayout;
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

protected:
    void dragEnterEvent(QDragEnterEvent *event) Q_DECL_OVERRIDE;
    void dragMoveEvent(QDragMoveEvent *event) Q_DECL_OVERRIDE;
    void dropEvent(QDropEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private: //Functions
    void addPlayersToLayout();


private: //Member variables
    QUuid m_tableId;
    QVBoxLayout *m_mainLayout;
    QList<Player *> m_players;
    QPushButton *m_ready;
    QPushButton *m_modify;
    QList<QComboBox*> m_playerRows;
    int m_tablePosition;

};

#endif // TOURNAMENTTABLEWIDGET_H
