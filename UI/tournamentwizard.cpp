#include "tournamentwizard.h"
#include "tournamentbasicinformationpage.h"
#include "tournamentaddplayerspage.h"
#include "tournamentsettingspage.h"


TournamentWizard::TournamentWizard(QWidget *parent) :
    QWizard(parent)
{
    addPage(new TournamentBasicInformationPage);
    addPage(new TournamentAddPlayersPage);
    addPage(new TournamentSettingsPage);

    setWindowTitle(tr("New Tournament"));
}

void TournamentWizard::accept()
{
QDialog::accept();
}
