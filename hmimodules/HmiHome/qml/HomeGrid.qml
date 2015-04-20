import QtQuick 2.0
import QtQuick.Controls 1.1


Rectangle {
    width: 400
    height: 400

    color: "blue"

    Text {
        text: "HomeAppGrid"
    }

    Button {
        text: "Back"
        onClicked: homeController.back();
    }
}
