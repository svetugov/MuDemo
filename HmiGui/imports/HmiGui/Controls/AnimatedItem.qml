import QtQuick 2.0

Item {
    id: root
    property string appearAnimationId: ""
    property string disappearAnimationId: ""

    function show() {
        var animation = themeManager.animation(appearAnimationId);
        root.visible = true;
        if (animation) {
            animation.target = root;
            animation.start();
        }
    }

    function hide() {
        var animation = themeManager.animation(disappearAnimationId);
        if (animation) {
            animation.target = root;
            animation.start();
        }
        root.visible = false;
    }
}

