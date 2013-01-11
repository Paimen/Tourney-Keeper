#ifndef TOURNAMENTWIZARD_H
#define TOURNAMENTWIZARD_H

#include <QWidget>
#include <QWizard>

class TournamentWizard : public QWizard
{
    Q_OBJECT
public:
    explicit TournamentWizard(QWidget *parent = 0);
    
signals:
    
public slots:
    void accept();
    
};

#endif // TOURNAMENTWIZARD_H
