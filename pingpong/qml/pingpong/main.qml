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

    Rectangle{
        id: bottomRacket
        x: gameScene.bottomRacket.x
        y: gameScene.bottomRacket.y
        width: gameScene.bottomRacket.width
        height: gameScene.bottomRacket.height
        color: "red"
    }
    Keys.onLeftPressed:  { gameController.racketsGoToLeft(); }
    Keys.onRightPressed: { gameController.racketsGoToRight(); }
    focus: true
}
