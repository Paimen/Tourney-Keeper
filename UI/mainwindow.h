#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class StartView;

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

    StartView *m_startView;

};

#endif // MAINWINDOW_H
