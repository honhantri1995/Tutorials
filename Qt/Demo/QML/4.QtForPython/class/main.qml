import QtQuick
import QtQuick.Window
import QtQuick.Controls

// Import the Python class
import Generators 1.0

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello Python World!")

    Flow {
        Button {
            text: qsTr("Give me a number!")
            onClicked: numberGenerator.giveNumber()
        }
        Label {
            id: numberLabel
            text: qsTr("no number")
        }
    }

    NumberGenerator {
        id: numberGenerator
    }

    Connections {
        target: numberGenerator
        function onNextNumber(number) {
            numberLabel.text = number
        }
    }
}
