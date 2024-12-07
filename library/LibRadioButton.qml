import QtQuick 2.15
import QtQuick.Controls 2.15

RadioButton {
    property var lText: value
    height:30
    indicator:Item {
        width: 30
        height: 30
        Rectangle {
            anchors.fill:parent
            color:"transparent"
            Image{
                anchors.fill:parent
                source:checked?"file:./images/choose.png":"file:./images/unchoose.png"
            }
            // border.color: customRadioButton.down ? "blue" : "gray"
            // color: customRadioButton.checked ? "blue" : "transparent"
            // anchors.verticalCenter: parent.verticalCenter
        }
    }
    Text{
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 40
        text:lText
        font.pixelSize: 26
        color:"black"
    }
}
