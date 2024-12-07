import QtQuick 2.15
import QtQuick.Controls 2.15

Row{
    property var name: value
    property alias textFieldText: textField.text
    property var textColor: "black"
    property var val: TextInputRow.ValidatorType.TEXT

    enum ValidatorType{
        TEXT,
        INT,
        DOUBLE
    }

    spacing: 30

    Text{
        font.pixelSize: 28
        color:"white"
        text:name
    }
    TextField{
        id:textField
        y:-8
        width:318
        height:30
        background:Rectangle{
            color:"transparent"
        }
        font.pixelSize: 28
        topPadding: 2
        bottomPadding: 2
        color:textColor
        validator:{
            if(val == TextInputRow.ValidatorType.TEXT){
                textValidator
            }else if(val == TextInputRow.ValidatorType.INT){
                intValidator
            }else if(val == TextInputRow.ValidatorType.DOUBLE){
                doubleValidator
            }
        }

        maximumLength: 20
        Rectangle{
            width:parent.width
            height:1
            anchors.top:parent.bottom
            // color:"white"
            border.width: 1
            border.color: "white"
        }
    }

    RegExpValidator {
        id:textValidator
        regExp: /^[a-zA-Z0-9_]*$/
    }

    DoubleValidator {
        id:doubleValidator
        bottom: -2147483648
        top: 2147483647
        decimals: 2
    }

    IntValidator {
        id:intValidator
        top: 2147483647;
        bottom: -2147483648
    }
}
