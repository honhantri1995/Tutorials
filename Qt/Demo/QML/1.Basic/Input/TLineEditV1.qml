import QtQuick

Rectangle {
    width: 96
    height: input.height + 8
    color: "lightsteelblue"
    border.color: "gray"

    property alias text: input.text

    TextInput {
        id: input
        width: 100
        height: 15
        anchors.fill: parent
        anchors.margins: 4
        focus: true
    }
}
