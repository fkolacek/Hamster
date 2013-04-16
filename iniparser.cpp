#include "iniparser.h"

iniFile::iniFile(){
    this->data.clear();
}

iniFile::~iniFile(){

}

void iniFile::addSection(QString sectionName){
    if(!this->isSection(sectionName))
        this->data.insert(sectionName, QHash<QString, QString>());
}

bool iniFile::isSection(QString sectionName){
    return this->data.contains(sectionName);
}

void iniFile::setValue(QString sectionName, QString directive, QString value){
    if(this->isSection(sectionName))
        this->addSection(sectionName);

    if(this->data[sectionName].find(directive) == this->data[sectionName].end())
        this->data[sectionName].insert(directive, value);
    else
        this->data[sectionName][directive] = value;
}

QString iniFile::getValue(QString sectionName, QString directive){
    if(this->isSection(sectionName))
        return "";

    return (this->data[sectionName].find(directive) == this->data[sectionName].end())? "" : this->data[sectionName][directive];
}

QStringList iniFile::getSections(){
    QStringList sections;

    for(QHash<QString, QHash<QString, QString> >::const_iterator p = this->data.begin(); p != this->data.end(); p++)
        sections.push_back(p.key());

    return sections;
}

QHash<QString, QString> iniFile::getSection(QString sectionName){
    return (this->isSection(sectionName))? this->data[sectionName] : QHash<QString, QString>();
}

iniFile iniParser::load(QString fileName){
    if(!QFile::exists(fileName))
        throw 1;

    QFile handler(fileName);

    if(!handler.open(QIODevice::ReadOnly))
        throw 2;

    QString line;
    QString section = "General";
    iniFile data;

    while(!handler.atEnd()){
          line = handler.readLine().trimmed();

    }

    handler.close();

    return data;
}

void iniParser::save(iniFile data, QString fileName){

    QFile handler(fileName);

    if(!handler.open(QIODevice::WriteOnly | QIODevice::Truncate))
        throw 2;

    QStringList sections = data.getSections();
    foreach(QString sectionName, sections){
        handler.write(QString("<" + sectionName + ">\n").toAscii());

        QHash<QString, QString> section = data.getSection(sectionName);
        for(QHash<QString, QString>::const_iterator p = section.begin(); p != section.end(); p++)
            handler.write(QString(p.key() + "=" + p.value()).toAscii());
    }

    handler.close();
}
