import QtQuick 2.0

Item {
    width: applicationWindow.width
    height: applicationWindow.height

    Image {
        id: content
        source: painter.image("general_bg")
    }
}
