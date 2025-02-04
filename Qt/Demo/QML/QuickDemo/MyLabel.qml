import QtQuick

Text {
    property string title: "goodbye"
    property int size

    text: "<b>" + title + "</b>"
    font.pixelSize: size
}
