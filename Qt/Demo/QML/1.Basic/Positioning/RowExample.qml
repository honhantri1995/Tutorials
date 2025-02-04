import QtQuick

Item {
    id: root
    width: 400
    height: 120

    Row {
        id: row
        anchors.centerIn: parent
        spacing: 8
        RedSquare { }
        GreenSquare { width: 96 }
        BlueSquare { }
    }
}
