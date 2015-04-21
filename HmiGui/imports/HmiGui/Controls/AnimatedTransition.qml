import QtQuick 2.0

Item {
    property QtObject target
    property SequentialAnimation animation

    function start() {
        animation.start();
    }

    function stop() {
        animation.stop();
    }
}

