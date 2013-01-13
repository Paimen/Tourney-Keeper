#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QIcon>

//for random icon
#include <QtGlobal>
#include <QTime>

#include "playerrowwidget.h"

PlayerRowWidget::PlayerRowWidget(const QString &a_playerName, QWidget *parent) :
    QWidget(parent)
{
    m_playerName = new QLabel(a_playerName);
    m_removeButton = new QPushButton(tr("Remove"),this);
    m_editButton = new QPushButton(tr("Edit"), this);
    connect(m_removeButton, SIGNAL(clicked()), this, SLOT(removeButtonClicked()));
    m_playerName->setFixedWidth(205);
    setFixedSize(QSize(420,45));
    QLabel *iconLabel = new QLabel();

    //just for testing
    // Create seed for the random
    // That is needed only once on application startup
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    // Get random value between 0-5
    int randomValue =  qrand() % ((5 + 1) - 0) + 0;

    switch (randomValue)
        {
        case 0:
        iconLabel->setPixmap(QPixmap("://House_Baratheon.resized.PNG"));
        break;

        case 1:
        iconLabel->setPixmap(QPixmap("://House_Greyjoy.resized.PNG"));
        break;
        case 2:
        iconLabel->setPixmap(QPixmap("://House_Martell.resized.PNG"));
        break;
        case 3:
        iconLabel->setPixmap(QPixmap("://House_Stark.resized.PNG"));
        break;
        case 4:
        iconLabel->setPixmap(QPixmap("://House_Lannister.resized.PNG"));
        break;
        case 5:
        iconLabel->setPixmap(QPixmap("://House_Targaryen.resized.PNG"));
        break;
        }

    //iconLabel->setPixmap(QPixmap("://House_Baratheon.resized.PNG"));
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(m_playerName);
    layout->addWidget(iconLabel);
    layout->addWidget(m_editButton);
    layout->addWidget(m_removeButton);
    setLayout(layout);


}


void PlayerRowWidget::removeButtonClicked()
{
    emit removeRow(this);
}
