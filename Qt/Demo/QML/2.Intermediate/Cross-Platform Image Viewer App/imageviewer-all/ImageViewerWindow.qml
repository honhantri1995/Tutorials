import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

ApplicationWindow {
    function openFileDialog() { fileOpenDialog.open(); }
    function openAboutDialog() { aboutDialog.open(); }

    visible: true
    title: qsTr("Image Viewer")

    background: Rectangle {
        color: "darkGray"
    }

    Image {
        id: image
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        asynchronous: true
    }

    FileDialog {
        id: fileOpenDialog
        title: "Select an image file"
        nameFilters: [ "Image files (*.png *.jpeg *.jpg)" ]
        onAccepted: image.source = fileOpenDialog.selectedFile;
    }

    Dialog {
        id: aboutDialog
        title: qsTr("About")
        standardButtons: Dialog.Ok

        Label {
            anchors.fill: parent
            text: qsTr("QML Image Viewer\nA part of the QmlBook\nhttp://qmlbook.org")
            horizontalAlignment: Text.AlignHCenter
        }
    }
}
