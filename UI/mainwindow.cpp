#include <QVBoxLayout>
#include <QTimer>

#include "mainwindow.h"
#include "tournamentselector.h"
#include "tournamentwizard.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{



   QTimer::singleShot(0, this, SLOT(showStartupDialog()));

}

MainWindow::~MainWindow()
{

}


void MainWindow::showStartupDialog()
{
  TournamentSelector d;
  d.setWindowTitle("");
  connect(&d,SIGNAL(openNewTournament()),this,SLOT(openTournamentWizard()));
  d.exec();
}

void MainWindow::openTournamentWizard()
{
    TournamentWizard wizard;
    wizard.exec();
}
