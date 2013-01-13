#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QDate>
#include <QCalendarWidget>
#include <QTimer>

#include "tournamentbasicinformationpage.h"

TournamentBasicInformationPage::TournamentBasicInformationPage(QWidget *parent) :
    QWizardPage(parent)
{
    //Title setup
    setTitle(tr("New Tournament"));
    setSubTitle(tr("Basic information for tournament"));

    //Creating widgets
    m_nameLabel = new QLabel(tr("Name"));
    m_placeLabel = new QLabel(tr("Place"));
    m_dateLabel = new QLabel(tr("Date"));
    m_typeLabel = new QLabel(tr("Game type"));

    m_nameLineEdit = new QLineEdit;
    m_placeLineEdit = new QLineEdit;

    m_dateEdit = new QDateEdit(QDate::currentDate(),this);
    m_calendarWidget = new QCalendarWidget(this);
    m_dateEdit->setDisplayFormat("yyyy.MM.dd"); //ToDo:add this to settings so user can setup preferred date format.
    m_dateEdit->setCalendarPopup(true);
    m_dateEdit->setCalendarWidget(m_calendarWidget);

    m_typeEdit = new QComboBox(this);
    m_typeEdit->addItem(tr("Joust"));
    m_typeEdit->addItem(tr("Melee"));


    //Layout setup
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_nameLabel,1,1);
    layout->addWidget(m_nameLineEdit,1,2);
    layout->addWidget(m_placeLabel,2,1);
    layout->addWidget(m_placeLineEdit,2,2);
    layout->addWidget(m_dateLabel,3,1);
    layout->addWidget(m_dateEdit,3,2);
    layout->addWidget(m_typeLabel,4,1);
    layout->addWidget(m_typeEdit,4,2);
    layout->setSpacing(20);

    setLayout(layout);
    setTabOrder(m_nameLineEdit, m_placeLineEdit);
    setTabOrder(m_placeLineEdit, m_dateEdit);
    setTabOrder(m_dateEdit, m_typeEdit);

    QTimer::singleShot(0, m_nameLineEdit, SLOT(setFocus()));
}

