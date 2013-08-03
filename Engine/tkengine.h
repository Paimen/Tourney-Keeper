#ifndef TKENGINE_H
#define TKENGINE_H

#include <QObject>

class TKTournament;

class TKEngine : public QObject
{
    Q_OBJECT
public:
    explicit TKEngine(QObject *parent = 0);
    
signals:
    
public slots:

public:
QList<TKTournament *> m_tournaments;

    
};

#endif // TKENGINE_H
