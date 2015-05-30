#include "tournamentstandigsview.h"
#include "tktournament.h"
#include "player.h"

TournamentStandingsView::TournamentStandingsView(TKTournament *tournament, QWidget *parent)
    : QDockWidget(tr("Standings"),parent), m_tournament(tournament)
{
    setFixedSize(240,240);
    m_players = m_tournament->tournamentPlayers();
}

TournamentStandingsView::~TournamentStandingsView()
{

}

