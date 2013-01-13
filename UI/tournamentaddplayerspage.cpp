#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDate>
#include <QCalendarWidget>
#include <QTimer>
#include <QScrollArea>
#include <QImage>
#include <QPushButton>
#include <QSignalMapper>


#include "tournamentaddplayerspage.h"
#include "hintcombobox.h"
#include "playerrowwidget.h"

TournamentAddPlayersPage::TournamentAddPlayersPage(QWidget *parent) :
    QWizardPage(parent)
{
    setTitle(tr("Add Players"));
    m_scrollArea = new QScrollArea;
    m_scrollableGrid = new QWidget;
    m_playerComboBox = new HintComboBox;
    m_playerComboBox->setHintText(tr("Choose or create player here"));
    m_playerComboBox->setMaximumWidth(220);
    //Layout setup
    QVBoxLayout *mainLayout = new QVBoxLayout;
    m_layout = new QVBoxLayout;
    m_layout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    populatePlayerComboBox();
    connect(m_playerComboBox,SIGNAL(activated(int)),this,SLOT(playerSelectionComboboxActivated(int)));

    m_layout->addWidget(m_playerComboBox);


    m_scrollableGrid->setLayout(m_layout);
    m_scrollArea->setWidget(m_scrollableGrid);
    m_layout->setSizeConstraint(QLayout::SetMinimumSize);

    mainLayout->addWidget(m_scrollArea);
    setLayout(mainLayout);

    m_playerCount = 0;


}
void TournamentAddPlayersPage::playerSelectionComboboxActivated(int index)
{
    QString name;
    QString id;
    if(index==0)
        {
        openPlayerCreationDialog(id, name);
        }
    else
        {

        name = m_playerComboBox->itemText(index);
        m_playerComboBox->removeItem(index);
        }
    addPlayerRow("puppu",name);
}

void TournamentAddPlayersPage::removePlayerClicked(QWidget *a_widget)
{
    m_layout->removeWidget(a_widget);
    a_widget->deleteLater();
    a_widget->setParent(0);
    delete a_widget;


}

void TournamentAddPlayersPage::addPlayerRow(const QString &a_id, const QString &a_name)
{
    m_layout->removeWidget(m_playerComboBox);

    PlayerRowWidget *row = new PlayerRowWidget(a_name,this);
    connect(row,SIGNAL(removeRow(QWidget*)),this, SLOT(removePlayerClicked(QWidget*)));
    m_layout->addWidget(row);



    m_playerComboBox->insertItem(0,tr("Choose or create player here"));

    m_layout->addWidget(m_playerComboBox);
    m_playerComboBox->setCurrentIndex(0);

}

void TournamentAddPlayersPage::populatePlayerComboBox()
{
    m_playerComboBox->addItem(tr("Choose or create player here"));
    m_playerComboBox->addItem(tr("New Player"));
    m_playerComboBox->insertSeparator(2);
    m_playerComboBox->addItem(tr("Jukka"));
    m_playerComboBox->addItem(tr("Antti"));
    m_playerComboBox->addItem(tr("Pekka"));
    m_playerComboBox->addItem(tr("Joukahainen"));
    m_playerComboBox->addItem(tr("Lanni"));
    m_playerComboBox->addItem(tr("Starkki"));

}

 void TournamentAddPlayersPage::openPlayerCreationDialog(QString &a_id, QString &a_name)
{
     a_name.append(tr("Uusi-Puusi"));
}
