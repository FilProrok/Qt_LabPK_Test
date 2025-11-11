#ifndef WPIS_H
#define WPIS_H

#include <QDateTime>

class Wpis
{
private:
    QString m_content;
    QDateTime m_creationDate;
public:
    Wpis();
    bool operator==(const Wpis& other);
    bool operator!=(const Wpis& other);
    bool operator<(const Wpis& other);
    void setContent(QString setContent);
    QString getContent() const;
    void setCreationDate(QDateTime dateTime);
    QDateTime getCreationDate() const;
};

#endif // WPIS_H
