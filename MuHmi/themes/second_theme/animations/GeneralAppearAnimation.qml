import QtQuick 2.0
import HmiGui.Controls 1.0

AnimatedTransition {
    id: root
    property int duration: 1000

    animation: SequentialAnimation {
        PropertyAnimation {
            target: root.target
            properties: "scale"
            from: 0.1
            to: 1
            duration: root.duration
        }
    }
}
