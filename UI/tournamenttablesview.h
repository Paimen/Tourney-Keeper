#ifndef TOURNAMENTTABLESVIEW_H
#define TOURNAMENTTABLESVIEW_H

#include <QWidget>

class QGridLayout;

class TournamentTablesView : public QWidget
{
    Q_OBJECT
public:
    explicit TournamentTablesView(QWidget *parent = 0);
    ~TournamentTablesView();

signals:

public slots:

private: // functions

private: //member variables

    QGridLayout *m_mainLayout;


};

#endif // TOURNAMENTTABLESVIEW_H
