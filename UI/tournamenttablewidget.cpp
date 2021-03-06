#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>

//For drag functionality
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QPixmap>


#include "tournamenttablewidget.h"
#include "tournamenttablerowwidget.h"
#include "player.h"

#include <QDebug>


TournamentTableWidget::TournamentTableWidget(QWidget *parent) : QGroupBox(parent),
    m_mainLayout(new QVBoxLayout), m_tablePosition(0)
{
    QHBoxLayout *buttonLayout = new QHBoxLayout;


    m_ready = new QPushButton;
    m_ready->setText(tr("Confirm"));
    buttonLayout->addWidget(m_ready);

    m_modify = new QPushButton;
    m_modify->setText(tr("Modify"));
    buttonLayout->addWidget(m_modify);
    //m_mainLayout->addLayout(buttonLayout);
    setLayout(m_mainLayout);
    setAcceptDrops(true);
}

TournamentTableWidget::~TournamentTableWidget()
{

}

/*!
 * \brief adds player to table
 * \param player player to be added
 */
void TournamentTableWidget::addPlayer(Player *player)
{
    ///\todo this is just for testing, seating should come from Swiss engine, most propably whole player list
    /// with seating order
    player->setTablePosition(m_players.count());

    m_players.append(player);
}

void TournamentTableWidget::setPlayers(QList<Player *> players)
{
    m_players = players;
    addPlayersToLayout();
}



void TournamentTableWidget::dragEnterEvent(QDragEnterEvent *event)
{

    if (event->mimeData()->hasFormat("application/tk-playerRow")) {
        if (children().contains(event->source())) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }

    } else {
        event->ignore();
    }
}

void TournamentTableWidget::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/tk-playerRow")) {
        if (children().contains(event->source())) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void TournamentTableWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/tk-playerRow")) {
        const QMimeData *mime = event->mimeData();

        QByteArray itemData = mime->data("application/tk-playerRow");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QString playerName;
        QPoint offset;
        dataStream >> playerName >> offset;
        TournamentTableRowWidget *newRow = new TournamentTableRowWidget();
        ///\todo seriously dangerous test code
        foreach (Player *player, m_players) {
            if(player->name() == playerName) {
                newRow->setPlayer(player);
            }
        }

        m_mainLayout->addWidget(newRow);


        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }

    }  else {
        event->ignore();
    }
}

void TournamentTableWidget::mousePressEvent(QMouseEvent *event)
{
    //we cast widget from position to Row Widget return if it fails
    QWidget *widget = childAt(event->pos());
    TournamentTableRowWidget *child = NULL;
    do {
        child = qobject_cast<TournamentTableRowWidget*>(widget);
        if(widget) {
            widget = widget->parentWidget();
        }
    } while (child == NULL && widget != NULL);

    if (child == NULL) {
        return;
    }

    // Gather data from widget
    QPoint hotSpot = event->pos() - child->pos();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << child->player()->name() << QPoint(hotSpot);


    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/tk-playerRow", itemData);


    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    QPixmap pixmap(child->size());
    child->render(&pixmap, QPoint());
    drag->setPixmap(pixmap);

    child->hide();

    int action = drag->exec(Qt::CopyAction, Qt::CopyAction);
    if (action == Qt::CopyAction)
        m_mainLayout->removeWidget(child);
    else
        child->show();
}


/*!
 * \brief helper functtion to populate layout with players
 */
void TournamentTableWidget::addPlayersToLayout()
{
    if(m_players.count() > 0) {
        foreach(Player* player, m_players) {
            if (player->tableId() == m_tableId) {
                TournamentTableRowWidget *row = new TournamentTableRowWidget;
                row->setPlayer(player);
                m_mainLayout->insertWidget(player->tablePosition(),row);
                qDebug() << "Player row: " << player->tablePosition();
                /*QLabel *label = new QLabel;
                label->setText(QString("Player %1").arg(player->tablePosition()+1));
                int playerPosition = player->tablePosition();
                QComboBox * rowPlayer = new QComboBox;
                int index = 0;
                foreach (Player* combPlayer, m_players) {

                    QVariant variant = QVariant::fromValue(combPlayer);
                    rowPlayer->addItem(combPlayer->name(),variant);
                    if(combPlayer->tableId() == m_tableId && playerPosition == combPlayer->tablePosition()) {
                        rowPlayer->setCurrentIndex(index);
                    }
                    index++;
                }


                m_mainLayout->addWidget(label,player->tablePosition(),0);
                m_mainLayout->addWidget(rowPlayer,player->tablePosition(),1);*/
            }
        }
    }
}
int TournamentTableWidget::tablePosition() const
{
    return m_tablePosition;
}

void TournamentTableWidget::setTablePosition(int tablePosition)
{
    m_tablePosition = tablePosition;
    setTitle(QString("Table %1").arg(tablePosition));
}

QUuid TournamentTableWidget::tableId() const
{
    return m_tableId;
}

void TournamentTableWidget::setTableId(const QUuid &tableId)
{
    m_tableId = tableId;
}



