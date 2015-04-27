#ifndef TOOLS_H
#define TOOLS_H

#include <QObject>

namespace HmiGui {

class Tools : public QObject
{
    Q_OBJECT
public:
    static Tools* instance();
    ~Tools();

    static bool findJsonValue(const QString &key,
                              QJsonObject &sourceObject,
                              QJsonValue &result);
    static bool generateJsonDocument(const QString &jsonFile, QJsonDocument &result);

private:
    explicit Tools(QObject *parent = 0);
};

}
#endif // TOOLS_H
