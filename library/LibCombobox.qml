import QtQuick 2.15
import QtQuick.Controls 2.15

ComboBox{
    id:combobox
    width:118
    height:28
    clip:true
    property var comboBoxModel: []
    // signal changeIndex(var index)
    // signal changeText(var text)
    background:Rectangle{
        color:"#D9D9D9"
        radius: 26
    }
    Text {
        anchors.centerIn: parent
        font.pixelSize: 16
        color:"black"
        text:currentText
    }

    enabled: false

    // delegate:Rectangle{
    //     id:item
    //     property var mouseEntered: false
    //     width:parent.width
    //     height:20
    //     color:mouseEntered?"#7749EC":"white"
    //     Text {
    //         id:text
    //         anchors.verticalCenter: parent.verticalCenter
    //         x:11
    //         font.pixelSize: 12
    //         color:"black"
    //         text:combobox.model[index]
    //     }
    //     MouseArea{
    //         id:mouseArea
    //         anchors.fill:parent
    //         hoverEnabled:true
    //         onEntered: {
    //             item.mouseEntered = true
    //         }
    //         onExited: {
    //             item.mouseEntered = false
    //         }
    //         onClicked: {
    //             changeIndex(index)
    //             changeText(textAt(index))
    //             combobox.focus = false
    //         }
    //     }
    // }
    model:comboBoxModel
    indicator:Rectangle{
        anchors.fill:parent
        color:"transparent"
        Image{
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 9
            source:"file:./images/indicator.png"
        }
    }
}
