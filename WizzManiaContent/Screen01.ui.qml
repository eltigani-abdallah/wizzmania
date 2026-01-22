/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick
import QtQuick.Controls
import WizzMania

Rectangle {
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor

    Grid {
        id: grid
        x: 694
        y: 349
        width: 400
        height: 400

        Pane {
            id: pane
            anchors.fill: parent

            Item {
                id: item1
                x: -12
                y: -12
                width: 400
                height: 32

                TabBar {
                    id: tabBar
                    x: 0
                    y: 0
                    width: 400
                    height: 32

                    Image {
                        id: image
                        x: 0
                        y: 0
                        width: 33
                        height: 32
                        source: "qrcimages/template_image.png"
                        fillMode: Image.PreserveAspectFit
                    }
                }
            }

            TextInput {
                id: textInput
                x: -12
                y: 348
                width: 400
                height: 40
                text: qsTr("Type your message")
                font.pixelSize: 12
            }


        }
    }

    RoundButton {
        id: roundButton
        x: 1062
        y: 718
        width: 21
        height: 21
        text: ">"
    }
}
