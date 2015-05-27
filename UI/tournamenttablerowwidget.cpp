#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>

#include "tournamenttablerowwidget.h"
#include "player.h"

TournamentTableRowWidget::TournamentTableRowWidget(QWidget *parent) : QWidget(parent), m_mainlayout(new QHBoxLayout),
    m_nameLabel(new QLabel), m_points(new QSpinBox)
{
    setLayout(m_mainlayout);
    m_mainlayout->addWidget(m_nameLabel);
    m_mainlayout->addWidget(m_points);
    ///\todo range from settings/plugin
    m_points->setRange(0,5);
}

TournamentTableRowWidget::~TournamentTableRowWidget()
{

}
Player *TournamentTableRowWidget::player() const
{
    return m_player;
}

void TournamentTableRowWidget::setPlayer(Player *player)
{
    m_player = player;
    m_nameLabel->setText(player->name());
    m_points->setValue(m_player->points());
}


