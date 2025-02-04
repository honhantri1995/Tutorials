import QtQuick
import "../common"

Background {
    width: 220
    height: 300

    GridView {
        id: view
        // model
        model: 100
        // view
        delegate: numberDelegate
        clip: true
        cellWidth: 45
        cellHeight: 45
        anchors {
            fill: parent
            margins: 20
        }
    }

    Component {
        id: numberDelegate

        BlueBox {
            width: 40
            height: 40
            text: index
        }
    }
}
