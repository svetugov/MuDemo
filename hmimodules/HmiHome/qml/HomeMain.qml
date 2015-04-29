import QtQuick 2.0
import QtQuick.Controls 1.1
import HmiGui.Controls 1.0


View {
    appearAnimationId: "homeAppearAnimation"

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
