import QtQuick 2.0
import QtQuick.Controls 1.2
import HmiGui.Controls 1.0

AnimatedItem {
    width: 800
    height: 480
    appearAnimationId: "generalAppearAnimation"

//    Image {
//        source: painter.image("general_bg")
//    }

    Button {
        text: "Back"
        onClicked: homeController.back();
    }


    Text {
        text: "Fame Hall"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
    }
}
