#include <QLabel>
#include <QTime>
#include <QTimer>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include "tournamenttimer.h"


TournamentTimer::TournamentTimer(QWidget *parent) : QDockWidget(tr("Round Time"),parent), m_timeText(new QLabel),
    m_resetButton(new QPushButton), m_startStopButton(new QPushButton), m_started(false)
{
    setFixedSize(240,240);

    QWidget *helper = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *buttonsRowLayout = new QHBoxLayout;

    m_timer = new QTimer();
    m_countDownTime = new QTime(0,45,0);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    m_timeText->setText(m_countDownTime->toString("mm:ss"));
    m_timeText->setAlignment(Qt::AlignCenter);
    m_timeText->setStyleSheet("font: 18pt;");

    m_resetButton->setText(tr("Reset"));
    connect(m_resetButton,SIGNAL(clicked()),this,SLOT(resetTime()));
    buttonsRowLayout->addWidget(m_resetButton);
    m_startStopButton->setText(tr("Start"));
    connect(m_startStopButton,SIGNAL(clicked()),this,SLOT(startStopTime()));
    buttonsRowLayout->addWidget(m_startStopButton);


    layout->addWidget(m_timeText);
    layout->addLayout(buttonsRowLayout);
    helper->setLayout(layout);
    setWidget(helper);
}

TournamentTimer::~TournamentTimer()
{

}

void TournamentTimer::updateTime()
{

    m_countDownTime->setHMS(0,m_countDownTime->addSecs(-1).minute(),m_countDownTime->addSecs(-1).second());
    m_timeText->setText(m_countDownTime->toString("mm:ss"));

}

void TournamentTimer::resetTime()
{
    m_countDownTime->setHMS(0,1,0);
    m_timeText->setText(m_countDownTime->toString("mm:ss"));
}

void TournamentTimer::startStopTime()
{
    if (m_started) {
        m_startStopButton->setText(tr("Start"));
        m_timer->stop();
        m_started = false;
    } else  {
        m_startStopButton->setText(tr("Stop"));
        m_timer->start(1000);
        m_started = true;
    }
}

