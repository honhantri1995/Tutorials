import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width:    height: 600
    title: "Clock"
    property string currTime: "00:00:00"
    property QtObject backend

    Rectangle {
        anchors.fill: parent

        Image {
            sourceSize.width: parent.width
            sourceSize.height: parent.height
            source: "./images/background.png"
            fillMode: Image.PreserveAspectCrop
        }

        Rectangle {
            anchors.fill: parent
            color: "transparent"


            Text {
                anchors {
                    bottom: parent.bottom
                    bottomMargin: 12
                    left: parent.left
                    leftMargin: 12
                }
                text: currTime  // used to be; text: "16:38:33"
                font.pixelSize: 48
                color: "white"
            }

        }

    }

    Connections {
        target: backend

        function onUpdated(msg) {
            currTime = msg;
           hms = {'hours': hours, 'minutes': minutes, 'seconds': seconds }
        }
    }

}