#ifndef TOURNAMENTBASICINFORMATIONPAGE_H
#define TOURNAMENTBASICINFORMATIONPAGE_H

#include <QWidget>
#include <QWizardPage>

class QLabel;
class QLineEdit;
class QDateEdit;
class QComboBox;
class QCalendarWidget;

class TournamentBasicInformationPage : public QWizardPage
{
    Q_OBJECT
public:
    explicit TournamentBasicInformationPage(QWidget *parent = 0);
    
signals:
    
public slots:

private:

    QLabel *m_nameLabel;
    QLabel *m_dateLabel;
    QLabel *m_placeLabel;
    QLabel *m_typeLabel;

    QLineEdit *m_nameLineEdit;
    QLineEdit *m_placeLineEdit;
    QDateEdit *m_dateEdit;
    QCalendarWidget *m_calendarWidget;
    QComboBox *m_typeEdit;







    
};

#endif // TOURNAMENTBASICINFORMATIONPAGE_H
