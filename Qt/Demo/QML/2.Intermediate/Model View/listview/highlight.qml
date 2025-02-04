import QtQuick

Rectangle {
    width: 120
    height: 300

    ListView {
        // model
        model: 100
        // view
        delegate: numberDelegate
        anchors {
            fill: parent
            margins: 20
        }
        clip: true
        spacing: 5
        focus: true
    }

    Component {
        id: numberDelegate

        Rectangle {
            width: ListView.view.width
            height: 40

            color: ListView.isCurrentItem ? "#157efb" : "#53d769"
            Text {
                anchors.centerIn: parent
                font.pixelSize: 10
                text: index
            }
        }
    }
}

