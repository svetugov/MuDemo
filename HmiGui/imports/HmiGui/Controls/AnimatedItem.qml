import QtQuick 2.0

Item {
    id: root
    property string appearAnimationId: ""

    function show() {
        var animation = themeManager.animation(appearAnimationId);
        root.visible = true;
        if (animation) {
            animation.target = root;
            animation.start();
        }
    }

    function hide() {
        root.visible = false;
    }
}

