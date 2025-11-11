#include "managerwpisow.h"
#include <algorithm>

ManagerWpisow::ManagerWpisow(QObject *parent) : QObject(parent) {}



void ManagerWpisow::dodajWpis(const Wpis& wpis){

    for(int i = 0; i < m_listaWpisow.size(); i++){
        if(m_listaWpisow[i] == wpis){
            m_listaWpisow.removeAt(i);
        }
    }

    m_listaWpisow.append(wpis);

    emit daneZmienione();
}

const QList<Wpis>& ManagerWpisow::getWpisy() const{
    return m_listaWpisow;
}

/*
bool predykatDoSortowaniaWpisow(Wpis& a, Wpis& b){
    return a.getCreationDate() < b.getCreationDate();
}
*/

void ManagerWpisow::sortujListeWpisow(){
    std::sort(m_listaWpisow.begin(), m_listaWpisow.end(), [](const Wpis& a, const Wpis& b) {return a.getCreationDate() < b.getCreationDate();});
}
