#ifndef TOURNAMENTADDPLAYERSPAGE_H
#define TOURNAMENTADDPLAYERSPAGE_H

#include <QWidget>
#include <QWizardPage>


class QString;
class QScrollArea;
class QLabel;
class QPushButton;
class QImage;
class QComboBox;
class QVBoxLayout;
class HintComboBox;
class QSignalMapper;

class TournamentAddPlayersPage : public QWizardPage
{
    Q_OBJECT
public:
    explicit TournamentAddPlayersPage(QWidget *parent = 0);
    
signals:
    
public slots:
    void playerSelectionComboboxActivated(int index);
    void removePlayerClicked(QWidget *a_widget);


private:
    void populatePlayerComboBox();
     void openPlayerCreationDialog(QString &a_id, QString &a_name);
     void addPlayerRow(const QString &a_id, const QString &a_name);

private:
    QScrollArea *m_scrollArea;
    HintComboBox *m_playerComboBox;
    QWidget *m_scrollableGrid;
    QVBoxLayout *m_layout;
    QSignalMapper *m_deletePlayerSignalMapper;

    int m_playerCount;

    
};

#endif // TOURNAMENTADDPLAYERSPAGE_H
