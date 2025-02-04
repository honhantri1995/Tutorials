import QtQuick
import QtQuick.Controls

ApplicationWindow {
    visible: true
    width: 640
    height: 220
    title: qsTr("Hello World")

    Column {
        anchors {
            top: parent.top
            left: parent.left
            margins: 10
        }
        width: parent.width/2
        spacing: 10

        Repeater {
            model: 2
            delegate: Button {
                width: parent.width
                height: 70
                text: qsTr("Click me!")
            }
        }
    }

    Grid {
        anchors {
            top: parent.top
            right: parent.right
            margins: 10
        }
        columns: 2
        spacing: 10

        Repeater {
            model: 4
            delegate: Button {
                height: 70
                text: qsTr("Check me!")
                checkable: true
            }
        }
    }
}
