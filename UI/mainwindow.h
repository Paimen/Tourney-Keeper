#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class TKEngine;
class TournamentTablesView;
class TournamentStandingsView;
class TournamentTimer;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openTournamentWizard();

private slots:
  void showStartupDialog();


private:

    TKEngine *m_engine;

    TournamentStandingsView *m_tournamentStandigsView;
    TournamentTimer *m_timerView;
    QTabWidget *m_viewStack;

};

#endif // MAINWINDOW_H
