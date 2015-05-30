#include <QVBoxLayout>
#include <QTimer>

#include "mainwindow.h"
#include "tournamentselector.h"
#include "tournamentwizard.h"
#include "tkengine.h"
#include "tournamenttablesview.h"
#include "tournamentstandigsview.h"
#include "tournamenttimer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

   m_engine = new TKEngine;
   m_viewStack = new QTabWidget;
   TournamentTablesView *rounndOne = new TournamentTablesView(m_engine->currentTournament());


   //Just for test
   m_viewStack->addTab(rounndOne, tr("Round 1"));
   TournamentTablesView *rounndTwo = new TournamentTablesView(m_engine->currentTournament());


   //Just for test
   m_viewStack->addTab(rounndTwo, tr("Round 2"));
   //QTimer::singleShot(0, this, SLOT(showStartupDialog()));
   setCentralWidget(m_viewStack);

   setDockOptions(QMainWindow::AnimatedDocks| QMainWindow::AllowNestedDocks);
   m_tournamentStandigsView = new TournamentStandingsView(m_engine->currentTournament());
   m_tournamentStandigsView->setAllowedAreas(Qt::RightDockWidgetArea);
   m_tournamentStandigsView->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable);
   addDockWidget(Qt::RightDockWidgetArea,m_tournamentStandigsView);

   m_timerView = new TournamentTimer;
   m_timerView->setAllowedAreas(Qt::RightDockWidgetArea);
   m_timerView->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetFloatable);
   addDockWidget(Qt::RightDockWidgetArea,m_timerView);

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
