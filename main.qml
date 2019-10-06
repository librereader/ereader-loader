import QtQuick 2.11
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.11
import QtQuick.Window 2.11
import QtQuick.Dialogs 1.1
import QtQml.Models 2.11

ApplicationWindow {
    id: window
    visible: true
    width: 540
    height: 720

    header: ToolBar {
        height: window.height * 0.075
        RowLayout {
            anchors.fill: parent
            ToolButton {
                text: qsTr("<")
                onClicked: stack.pop()
                opacity : stack.depth > 1 ? 1.0 : 0.0
            }
            Label {
                id: toolBarLabel
                text: stack.currentItem.title
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
            ToolButton {
                text: qsTr("?")
                onClicked: console.log("show help")
            }
        }
    }

    StackView {
        id: stack
        anchors.fill: parent
        initialItem: Page {
            title: qsTr("E-Reader Launcher")
            ListView {
                width: window.width
                height: window.height

                model: ObjectModel {
                    id: views
                    ListObjectItem {
                        label: qsTr("Start CoolReader")
                        onClicked: console.log("process started")
                    }
                    ListObjectItem {
                        label: qsTr("About")
                        Page {
                            title: qsTr("About")
                            id: settings
                            visible: false
                            contentItem: Text {
                                anchors.fill: parent
                                anchors.margins: window.height * 0.075 * 0.3
                                text: "none"
                            }
                        }
                        onClicked: stack.push(settings)
                    }
                }
            }
        }

        // disable all animations
        pushEnter: Transition { }
        pushExit: Transition { }
        popEnter: Transition { }
        popExit: Transition { }
    }
}
