#include <QVBoxLayout>
#include <QTimer>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startview.h"
#include "tournamentselector.h"

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

}
