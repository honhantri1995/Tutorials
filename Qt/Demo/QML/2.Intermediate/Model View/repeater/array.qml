import QtQuick
import "../common"

Column {
    spacing: 2

    Repeater {
        // model
        model: ["Enterprise", "Columbia", "Challenger", "Discovery", "Endeavour", "Atlantis"]
        // view
        delegate: BlueBox {
            width: 100
            height: 32
            text: modelData + ' (' + index + ')'
        }
    }
}
