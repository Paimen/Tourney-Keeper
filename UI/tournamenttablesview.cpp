/*!
 * \brief View to show up tournament tables
 * \class TournamentTablesView
 * \ingroup UI
 * \author Jukka Raninen
 * \copyright Copyright 2015 Juka Raninen All rights reserved.
 *
 *
 */
#include <QGridLayout>

#include "tournamenttablesview.h"
#include "tournamenttablewidget.h"

#include "tktournament.h"
#include "player.h"



/*!
 * \brief basic constructor
 * \param parent
 */
TournamentTablesView::TournamentTablesView(TKTournament *tournament, QWidget *parent) :
    QWidget(parent), m_mainLayout(new QGridLayout), m_tournament(tournament)
{
    TournamentTableWidget *table;
    int row=0;
    foreach (QUuid id, m_tournament->activeTables()) {
        table = new TournamentTableWidget;
        table->setTableId(id);
        table->setPlayers(m_tournament->tournamentPlayers());
        m_mainLayout->addWidget(table,row,0);
        row++;
        table->setTablePosition(row);
    }

    setLayout(m_mainLayout);
}

/*!
 * \brief basic destructor
 */
TournamentTablesView::~TournamentTablesView()
{

}

