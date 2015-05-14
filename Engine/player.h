#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QUuid>

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = 0);
    ~Player();

    QString name() const;
    void setName(const QString &name);

    int points() const;
    void setPoints(int points);

    int sos() const;
    void setSos(int sos);

    int playedGames() const;
    void setPlayedGames(int playedGames);


    int tablePosition() const;
    void setTablePosition(int tablePosition);

    QUuid tableId() const;
    void setTableId(const QUuid &tableId);

signals:

public slots:

private:
    QString m_name;
    int m_points;
    int m_sos;
    int m_playedGames;
    int m_tablePosition;
    QUuid m_tableId;
};

#endif // PLAYER_H
