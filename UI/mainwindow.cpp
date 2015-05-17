#include <QVBoxLayout>
#include <QTimer>

#include "mainwindow.h"
#include "tournamentselector.h"
#include "tournamentwizard.h"
#include "tkengine.h"
#include "tournamenttablesview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

   m_engine = new TKEngine;
   m_tablesView = new TournamentTablesView(m_engine->currentTournament());

   //QTimer::singleShot(0, this, SLOT(showStartupDialog()));
   setCentralWidget(m_tablesView);

}

MainWindow::~MainWindow()
{
    if (m_engine) {
        delete m_engine;
        m_engine = NULL;
    }
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
