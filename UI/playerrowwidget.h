#ifndef PLAYERROWWIDGET_H
#define PLAYERROWWIDGET_H

#include <QWidget>

class QLabel;
class QPushButton;

class PlayerRowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlayerRowWidget(const QString &a_playerName, QWidget *parent = 0);
    
signals:
    void removeRow(QWidget *a_widget);

public slots:
        void removeButtonClicked();
private:
    QLabel *m_playerName;
    QPushButton *m_removeButton;
    QPushButton *m_editButton;
    QString m_name;
    
};

#endif // PLAYERROWWIDGET_H
