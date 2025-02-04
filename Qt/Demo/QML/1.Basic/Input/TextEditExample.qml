import QtQuick

Rectangle {
    width: 200
    height: 100
    color: "linen"

    TextEdit {
        id: input1
        x: 8; y: 8
        width: 100; height: 20
        text: "Text Edit"
        focus: true
    }
}
