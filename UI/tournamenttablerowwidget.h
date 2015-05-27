#ifndef TOURNAMENTTABLEROWWIDGET_H
#define TOURNAMENTTABLEROWWIDGET_H

#include <QWidget>

class QHBoxLayout;
class Player;
class QLabel;
class QSpinBox;

class TournamentTableRowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TournamentTableRowWidget(QWidget *parent = 0);
    ~TournamentTableRowWidget();

    Player *player() const;
    void setPlayer(Player *player);

signals:

public slots:


private:
    QHBoxLayout *m_mainlayout;
    Player *m_player;
    QLabel *m_nameLabel;
    QSpinBox *m_points;
};

#endif // TOURNAMENTTABLEROWWIDGET_H
