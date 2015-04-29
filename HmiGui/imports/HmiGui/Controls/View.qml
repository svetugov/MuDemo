import QtQuick 2.0

AnimatedItem {
    id: root
    property string styleName: "NativeStyle"
    property QtObject style: themeManager.style(styleName, root)
    width: style.viewWidth
    height: style.viewHeight
}

