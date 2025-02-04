import QtQuick
import "../common"

Column {
    spacing: 2

    Repeater {
        // model
        model: 10
        // view
        delegate: BlueBox {
            width: 100
            height: 32
            text: index
        }
    }
}
