import QtQuick

Rectangle {
    width: 200
    height: 100
    color: "linen"

    TextInput {
        id: input1
        x: 8; y: 8
        width: 100; height: 20      // width and height are not about the text font, but about the text box
        text: "Text Input 1"
        KeyNavigation.tab: input2   // switch the focus by Tab key
        focus: true                 // without it, switching won't work
    }

    TextInput {
        id: input2
        x: 8; y: 36
        width: 150; height: 50
        text: "Text Input 2"
        KeyNavigation.tab: input1
    }
}
