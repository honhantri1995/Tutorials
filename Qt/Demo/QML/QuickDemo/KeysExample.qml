import QtQuick
Item {
    id: root
    property string title: "hello"

    MyLabel {
        //title: root.title
        size: 22
        anchors.top: parent.top
    }

    MyLabel {
        //title: root.title
        size: 18
        anchors.bottom: parent.bottom
    }
}
