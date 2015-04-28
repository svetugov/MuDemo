import QtQuick 2.0
import HmiGui.Controls 1.0

AnimatedTransition {
    id: root
    animation: SequentialAnimation {
        PropertyAnimation {
            target: root.target ? root.target : null
            properties: "y"
            from: root.target ? -root.target.height : 0
            to: 0
            duration: 1000
        }
    }
}

