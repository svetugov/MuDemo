import QtQuick 2.0
import QtQuick.Controls 1.1


Item {
    width: 800
    height: 480

    Image {
        source: painter.image("home_bg")
    }


    Text {
        text: "Home"
    }

    Row {


    Button {
        text: "Fame Hall"
        onClicked: homeController.showFameHall();
    }

    Button {
        text: "Main Theme"
        onClicked: themeManager.changeTheme("main");
    }

    Button {
        text: "Second Theme"
        onClicked: themeManager.changeTheme("second");
    }

    }
}
