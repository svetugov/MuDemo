#ifndef PAINTER_H
#define PAINTER_H

#include <QObject>

#include "hmigui_global.h"


namespace HmiGui {

class HMIGUI_EXPORT Painter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString imagesFolder READ imagesFolder WRITE setImagesFolder)

public:
    Painter(QObject *parent = 0);
    ~Painter();

    QString imagesFolder() const;
    void setImagesFolder(const QString &value);

public slots:
    // API
    QString image(const QString &id) const;

private:
    QString m_imagesFolder;
};

}
#endif // PAINTER_H
