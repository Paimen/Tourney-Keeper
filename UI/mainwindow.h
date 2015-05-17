#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class TKEngine;
class TournamentTablesView;

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
    TournamentTablesView *m_tablesView;

};

#endif // MAINWINDOW_H
