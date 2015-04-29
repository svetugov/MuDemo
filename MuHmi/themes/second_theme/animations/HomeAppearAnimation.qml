import QtQuick 2.0
import HmiGui.Controls 1.0

AnimatedTransition {
    id: root
    animation: SequentialAnimation {
        PropertyAnimation {
            target: root.target ? root.target : null
            properties: "scale"
            from: 0.1
            to: 1
            duration: 1000
        }
    }
}

