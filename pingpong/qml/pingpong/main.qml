import QtQuick 2.0

Rectangle {
    width: 360
    height: 360
    Rectangle{
        id: topRacket
        x: gameScene.topRacket.x
        y: gameScene.topRacket.y
        width: gameScene.topRacket.width
        height: gameScene.topRacket.height
        color: "red"
    }
    onWidthChanged: gameController.setSceneSize(width, height);
    onHeightChanged: gameController.setSceneSize(width, height);

    Rectangle{
        id: bottomRacket
        x: gameScene.bottomRacket.x
        y: gameScene.bottomRacket.y
        width: gameScene.bottomRacket.width
        height: gameScene.bottomRacket.height
        color: "red"
    }

    Image {
        id: ball
        x: gameScene.ball.x - gameScene.ball.radius
        y: gameScene.ball.y - gameScene.ball.radius
        width: gameScene.ball.radius * 2
        height: width
        source: "ball.png"
    }
    Keys.onLeftPressed:  { gameController.racketsGoToLeft(); }
    Keys.onRightPressed: { gameController.racketsGoToRight(); }
    focus: true

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        onMouseXChanged: gameController.setRacketsPosition(mouseX);
    }
}
