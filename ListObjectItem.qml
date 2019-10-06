import QtQuick 2.11
import QtQuick.Controls 2.5

Item {
    id: item
    default property alias contents: placeholder.data

    property string label: "(none)"
    signal clicked

    height: window.height * 0.075
    width: parent.width

    Rectangle {
        id: container
        anchors.fill: parent
        anchors.margins: window.height * 0.075 * 0.3
    }

    Label {
        id: label
        anchors.fill: container
        text: item.label
    }
    
    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: false
        z: 1
        onClicked: item.clicked()
    }

    Item {
        id: placeholder
    }
}
