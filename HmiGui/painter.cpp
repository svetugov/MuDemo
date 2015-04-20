#include <QFile>
#include <QDebug>

#include "painter.h"
#include "environment.h"


using namespace HmiGui;

Painter::Painter(QObject *parent) : QObject(parent)
{

}

Painter::~Painter()
{

}

QString Painter::image(const QString &id) const
{
    QString path(Environment::instance()->themesFolder() + m_imagesFolder + id + ".jpg");
    if (QFile(path).exists())
        return "file:///" + path;
    else {
        qWarning() << Q_FUNC_INFO << "Cannot find image:" << path;
        return "";
    }
}

QString Painter::imagesFolder() const
{
    return m_imagesFolder;
}

void Painter::setImagesFolder(const QString &value)
{
    m_imagesFolder = value;
}


