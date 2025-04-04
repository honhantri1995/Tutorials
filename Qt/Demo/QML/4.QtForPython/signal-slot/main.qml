import QtQuick
import QtQuick.Window
import QtQuick.Controls

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

    // receive a signal from an object that has been instantiated outside of QML
    Connections {
        target: numberGenerator
        function onNextNumber(number) {
            numberLabel.text = number
        }
    }
}
