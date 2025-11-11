#include "wpis.h"

Wpis::Wpis() {}

QDateTime Wpis::getCreationDate() const{
    return m_creationDate;
}

bool Wpis::operator==(const Wpis& other){
    if(this->getCreationDate() == other.getCreationDate()){
        return true;
    }
    return false;
}

bool Wpis::operator!=(const Wpis& other){
    return !(*this == other);
}

bool Wpis::operator<(const Wpis& other){
    if(this->getCreationDate() < other.getCreationDate()){
        return true;
    }
    return false;
}

void Wpis::setContent(QString content){
    m_content = content;
}

void Wpis::setCreationDate(QDateTime creationDate){
    m_creationDate = creationDate;
}

QString Wpis::getContent() const {
    return m_content;
}
