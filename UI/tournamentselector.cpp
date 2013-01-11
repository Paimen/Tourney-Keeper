#include <QPushButton>
#include <QLayout>
#include <QComboBox>

#include "tournamentselector.h"

TournamentSelector::TournamentSelector(QWidget *parent) :
    QDialog(parent)
{

    QGridLayout *layout = new QGridLayout;
    m_newTournamentButton = new QPushButton(tr("&New Tournament"));
    m_newTournamentButton->setDefault(true);
    m_openTournamentButton = new QPushButton(tr("&Open Tournament"));
    m_openTournamentButton->setDefault(false);
    m_tournamentListComboBox = new QComboBox(this);
    layout->addWidget(m_openTournamentButton,1,2);
    layout->addWidget(m_tournamentListComboBox,1,1);
    layout->addWidget(m_newTournamentButton,2,1);
    connect(m_newTournamentButton, SIGNAL(clicked()),this,SLOT(newTournamentClicked()));

    this->setLayout(layout);
}

TournamentSelector::~TournamentSelector()
{
}

void TournamentSelector::newTournamentClicked()
{
emit openNewTournament();
emit accept();
}
