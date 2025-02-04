import QtQuick
import "../common"

Background {
    width: 80
    height: 300

    ListView {
        // model
        model: 100
        // view
        delegate: numberDelegate
        spacing: 5
        anchors {
            fill: parent
            margins: 20
        }
        clip: true
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
