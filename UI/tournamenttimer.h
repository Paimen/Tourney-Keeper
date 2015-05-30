#ifndef TOURNAMENTTIMER_H
#define TOURNAMENTTIMER_H

#include <QDockWidget>

class QTimer;
class QTime;
class QLabel;
class QPushButton;

class TournamentTimer : public QDockWidget
{
    Q_OBJECT
public:
    explicit TournamentTimer(QWidget *parent = 0);
    ~TournamentTimer();

signals:

public slots:
    void updateTime();
    void resetTime();
    void startStopTime();
private:
    QTimer* m_timer;
    QTime*  m_countDownTime;
    QLabel *m_timeText;
    QPushButton *m_resetButton;
    QPushButton *m_startStopButton;
    bool m_started;
};

#endif // TOURNAMENTTIMER_H
