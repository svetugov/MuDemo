#include <QDebug>
#include <QDir>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>

#include "qcoreapplication.h"
#include "tools.h"

using namespace HmiGui;

Tools::Tools(QObject *parent) : QObject(parent)
{

}

Tools::~Tools()
{

}

Tools* Tools::instance()
{
    static Tools* self = 0;
    if (!self) {
        self = new Tools(qApp);
    }

    return self;
}

bool Tools::findJsonValue(const QString &key, QJsonObject &sourceObject, QJsonValue &result)
{
    QJsonObject::const_iterator it = sourceObject.find(key);
    if (it != sourceObject.end()) {
        result = it.value();
        return true;
    }
    return false;
}

bool Tools::generateJsonDocument(const QString &jsonFile, QJsonDocument &result)
{
    QFile file(QDir::toNativeSeparators(jsonFile));
    if (!file.exists()) {
        qWarning() << Q_FUNC_INFO << "JSON file doesn't exist:" + jsonFile;
        return false;
    }
    if (!file.open(QFile::ReadOnly)) {
        qWarning() << Q_FUNC_INFO << "Cannot read JSON file:" + jsonFile;
        return false;
    }

    const QByteArray jsonData(file.readAll());
    QJsonParseError jsonParseError;
    result = QJsonDocument::fromJson(jsonData, &jsonParseError);

    if (jsonParseError.error != QJsonParseError::NoError) {
        qWarning() << Q_FUNC_INFO << "JSON file" << jsonFile << "failed to load with error:" << jsonParseError.error;
        return false;
    }

    return true;
}
