#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include <QObject>

#include "theme.h"

namespace HmiGui {

class AnimationManager : public QObject
{
    Q_OBJECT
public:
    explicit AnimationManager(QObject *parent = 0);
    ~AnimationManager();

    void collectAnimations(const QString &animationsFolder);

signals:

public slots:

private:
    AnimationsCollection *m_animationsCollection;
};

}
#endif // ANIMATIONMANAGER_H
