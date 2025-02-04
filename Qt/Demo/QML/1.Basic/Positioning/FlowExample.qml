import QtQuick

Item {
    id: root
    width: 160		// if width = 360, then only 1 row
    height: 160

    Flow {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 20
        RedSquare { }
        BlueSquare { }
        GreenSquare { }
    }
}
