import QtQuick

Item {
    id: root
    width: 252
    height: 252
    property variant colorArray: ["red", "blue", "green"]

    Grid{
        anchors.fill: parent
        anchors.margins: 8
        spacing: 4
        Repeater {
            model: 16
            delegate: Rectangle {
                required property int index
                property int colorIndex: Math.floor(Math.random()*3)		// JS math functions

                width: 56; height: 56
                color: root.colorArray[colorIndex]

                Text {
                    anchors.centerIn: parent
                    color: "white"
                    text: "Cell " + parent.index
                }
            }
        }
    }
}