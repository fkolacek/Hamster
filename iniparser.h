#ifndef INIPARSER_H
#define INIPARSER_H

#include <QObject>
#include <QHash>
#include <QStringList>
#include <QFile>

class iniFile{

public:
    iniFile();
    virtual ~iniFile();

    void addSection(QString);
    bool isSection(QString);

    void setValue(QString, QString, QString);
    QString getValue(QString, QString);

    QStringList getSections();
    QHash<QString, QString> getSection(QString);
private:
    QHash<QString, QHash<QString, QString> > data;
};

class iniParser : public QObject
{
    Q_OBJECT
public:
    static iniFile load(QString);
    static void save(iniFile, QString);
};

#endif // INIPARSER_H
