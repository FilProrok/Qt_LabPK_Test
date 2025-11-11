#ifndef MANAGERWPISOW_H
#define MANAGERWPISOW_H

#include <QObject>
#include <QList>
#include <wpis.h>

class ManagerWpisow: public QObject
{
    Q_OBJECT;
    QList<Wpis> m_listaWpisow;
    static bool predykatDoSortowaniaWpisow(Wpis& a, Wpis& b);

public:
    explicit ManagerWpisow(QObject *parent = nullptr);

    void dodajWpis(const Wpis& wpis);
    void aktualizujWidokListy();
    const QList<Wpis>& getWpisy() const;
    void sortujListeWpisow();

signals:
    void daneZmienione();

};

#endif // MANAGERWPISOW_H
