// TransformationExample.qml
import QtQuick

Item {
    // set size based on given background
    width: bg.width
    height: bg.height

    // nice background image
    Image {
        id: bg
        source: "assets/background.png"
    }

    // mouse area for the backgroud
    // needs to be before the images as order matters
    // otherwise this mousearea would be before the other elements and consume the mouse events
    MouseArea {
        id: backgroundClicker

        anchors.fill: parent
        onClicked: {
            // reset our little scene
            circle.x = 84
            box.rotation = 0
            triangle.scale = 1.0
        }
    }

    ClickableImage {
        id: circle
        x: 84; y: 68
        source: "assets/circle_blue.png"
        antialiasing: true
        onClicked: {
            // increase the x-position on click
            x += 20
        }
    }

    ClickableImage {
        id: box
        x: 164; y: 68
        source: "assets/box_green.png"
        antialiasing: true  // enable anti-aliasing, which is switched off (same as the clipping property clip) for performance reasons
        onClicked: {
            // increase the rotation on click
            rotation += 15
        }
    }

    ClickableImage {
        id: triangle
        x: 248; y: 68
        source: "assets/triangle_red.png"
        antialiasing: true  // enable anti-aliasing, which is switched off (same as the clipping property clip) for performance reasons
        smooth: true        // enable the usage of a higher quality filter at the cost of performance
        onClicked: {
            // scale up
            scale += 0.25
        }
    }
}
