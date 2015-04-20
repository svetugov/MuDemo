#ifndef THEMESCOLLECTION_H
#define THEMESCOLLECTION_H

#include <QHash>

#include "theme.h"

namespace HmiGui {
typedef QHash<QString, Theme*> ThemesCollection;
}

#endif // THEMESCOLLECTION_H

