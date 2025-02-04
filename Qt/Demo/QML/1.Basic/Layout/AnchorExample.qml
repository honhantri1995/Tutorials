import QtQuick

Item {
    GreenSquare {
        width: 200; height: 100
        BlueSquare {
            width: 50
            anchors.fill: parent
            anchors.margins: 20
        }
    }

}
