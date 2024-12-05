import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    visible: true
    width: 1920
    height: 1080
    flags: Qt.FramelessWindowHint
    color:"transparent"

    //0:homepage 1:logoin 2:mainpage
    property var pageIndex: 0

    Connections{
        target:client
        function onConnectedChanged(flag){
            pageIndex = 0
        }
    }

    //homepage
    Rectangle{
        visible:pageIndex == 0
        anchors.fill:parent
        color:"transparent"
        Image{
            anchors.fill:parent
            source:"file:./images/homepage.png"
            Image{
                anchors.horizontalCenter: parent.horizontalCenter
                y:368
                source:"file:./images/homepagetitle.png"
            }
        }

        Text{
            visible: !client.connected
            x:782
            y:910
            text: "Try connecting to a server ..."
            font.pixelSize: 35
            color:"red"
        }

        Button{
            id:signin
            property var enter: false
            visible: client.connected
            x:782
            y:910
            width:320
            height:102
            background: Rectangle{
                color:"transparent"
            }
            MouseArea{
                anchors.fill:parent
                hoverEnabled:true
                onEntered: {
                    signin.enter = true
                }
                onExited: {
                    signin.enter = false
                }
                onClicked: {
                    pageIndex = 1
                }
            }
            Image{
                anchors.fill:parent
                source:signin.enter?"file:./images/signin_active.png":"file:./images/signin.png"
            }
        }
    }

    //logoin
    Rectangle{
        visible:pageIndex == 1
        anchors.fill:parent
        color:"transparent"
        Image{
            anchors.fill:parent
            source:"file:./images/logoin_background.png"
        }

        Image{
            x:240
            y:183
            source:"file:./images/logoin_dialog.png"
            Image{
                x:24+50
                y:151+118
                source:"file:./images/logoin_title.png"
            }
            Image{
                x:292
                y:80
                width:223
                height:223
                source:"file:./images/head.png"
            }
            Image{
                x:761
                y:17
                source:"file:./images/logo_small.png"
            }

            Text{
                x:834
                y:120
                color:"black"
                font.pixelSize: 28
                font.bold: true
                text:"LOGIN"
            }

            Text{
                id:userid
                x:591
                y:187
                color:"black"
                font.pixelSize: 28
                font.bold: true
                text:"User ID"
            }

            TextField{
                id:usernameInput
                width:514
                height:78
                x:591
                anchors.top:userid.bottom
                anchors.topMargin: 10
                // focus: true
                // onFocusChanged: {
                //     focus = true
                // }
                placeholderText:"enter User ID"
                background:Rectangle{
                    color:"#D9D9D9"
                    radius: 35
                    border.width: 1
                    border.color:"black"
                }
                font.pixelSize: 22
                color:"black"
                validator: RegExpValidator {
                    regExp: /^[a-zA-Z0-9_]*$/
                }
                maximumLength: 20
                text:"admin"
            }

            Image{
                id:verifyError
                x:1126
                y:239
                width:50
                height:50
                source:"file:./images/verify_error.png"
                visible: false
                NumberAnimation {
                    id:verifyErrorAnimation
                    target: verifyError
                    property: "opacity"
                    from: 1.0
                    to: 0.0
                    duration: 4000
                    onFinished: {
                        verifyError.visible = false
                    }
                }
            }

            Text{
                id:password
                x:591
                y:358
                color:"black"
                font.pixelSize: 28
                font.bold: true
                text:"Password"
            }

            TextField{
                id:passwordInput
                width:514
                height:78
                x:591
                anchors.top:password.bottom
                anchors.topMargin: 10
                placeholderText:"enter Password"
                background:Rectangle{
                    color:"#D9D9D9"
                    radius: 35
                    border.width: 1
                    border.color:"black"
                }
                font.pixelSize: 22
                color:"black"
                validator: RegExpValidator {
                    regExp: /^[a-zA-Z0-9_]*$/
                }
                maximumLength: 20
                echoMode: TextInput.Password
                text:"123456"
            }

            Text {
                x:690
                y:507
                font.pointSize: 16
                color: mouseArea.containsMouse ? "blue" : "black"
                // 使用富文本格式添加下划线
                textFormat: Text.RichText
                text: mouseArea.containsMouse ? "<u>Forgot Password / User ID</u>" : "Forgot Password / User ID"
                MouseArea {
                    id: mouseArea
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor // 鼠标悬停时变成手势
                    hoverEnabled: true
                    // 点击事件
                    onClicked: {
                        //
                    }
                }
            }

            Button{
                id:login_submit
                property var enter: false
                x:736
                y:598
                width:247
                height:85
                background: Rectangle{
                    color:"transparent"
                }
                MouseArea{
                    anchors.fill:parent
                    hoverEnabled:true
                    onEntered: {
                        login_submit.enter = true
                    }
                    onExited: {
                        login_submit.enter = false
                    }
                    onClicked: {
                        var result = client.signIn(usernameInput.text,passwordInput.text)
                        if(result){
                            //ok
                            pageIndex = 2
                        }else{
                            verifyError.visible = true
                            verifyError.opacity = 1
                            verifyErrorAnimation.restart()
                        }
                    }
                }
                Image{
                    anchors.fill:parent
                    source:login_submit.enter?"file:./images/submit_active.png":"file:./images/submit.png"
                }
            }
        }

    }


    property var mainPageIndex: 0
    //mainpage
    Rectangle{
        visible:pageIndex == 2
        anchors.fill:parent
        color:"transparent"
        Image{
            anchors.fill:parent
            source:"file:./images/mainpage.png"
        }

        Image{
            x:40
            y:80
            source:"file:./images/logo_small.png"
        }

        Rectangle{
            id:logoRect
            width:73
            height:500
            radius: 35
            color:"#D9D9D9"
            opacity: 0.6
            x:20
            anchors.verticalCenter: parent.verticalCenter
        }

        Rectangle{
            id:textRect
            width:223
            height:500
            radius: 35
            color:"#D9D9D9"
            opacity: 0.6
            anchors.left: logoRect.right
            anchors.leftMargin: 20
            anchors.verticalCenter: parent.verticalCenter
        }

        Column{
            anchors.centerIn: logoRect
            spacing: 45
            Image{
                width:50
                height:50
                source:"file:./images/borrow.png"
                MouseArea{
                    width:300
                    height:50
                    onClicked: {
                        mainPageIndex = 0
                    }
                }
                Rectangle{
                    y:10
                    x:-16
                    width:10
                    height:30
                    radius: 25
                    color:"#16B712"
                    visible: mainPageIndex == 0
                }
                Text{
                    x:85
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 28
                    color:"#0C0C0C"
                    text:"Borrow / Return"
                }
            }
            Image{
                width:50
                height:50
                source:"file:./images/books.png"
                MouseArea{
                    width:300
                    height:50
                    onClicked: {
                        mainPageIndex = 1
                    }
                }
                Rectangle{
                    y:10
                    x:-16
                    width:10
                    height:30
                    radius: 25
                    color:"#16B712"
                    visible: mainPageIndex == 1
                }
                Text{
                    x:150
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 28
                    color:"#0C0C0C"
                    text:"Books"
                }
            }
            Image{
                width:50
                height:50
                source:"file:./images/history.png"
                MouseArea{
                    width:300
                    height:50
                    onClicked: {
                        mainPageIndex = 2
                    }
                }
                Rectangle{
                    y:10
                    x:-16
                    width:10
                    height:30
                    radius: 25
                    color:"#16B712"
                    visible: mainPageIndex == 2
                }
                Text{
                    x:140
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 28
                    color:"#0C0C0C"
                    text:"History"
                }
            }
            Image{
                width:50
                height:50
                source:"file:./images/search.png"
                MouseArea{
                    width:300
                    height:50
                    onClicked: {
                        mainPageIndex = 3
                    }
                }
                Rectangle{
                    y:10
                    x:-16
                    width:10
                    height:30
                    radius: 25
                    color:"#16B712"
                    visible: mainPageIndex == 3
                }
                Text{
                    x:140
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 28
                    color:"#0C0C0C"
                    text:"Searchs"
                }
            }
            Image{
                width:50
                height:50
                source:"file:./images/stats.png"
                MouseArea{
                    width:300
                    height:50
                    onClicked: {
                        mainPageIndex = 4
                    }
                }
                Rectangle{
                    y:10
                    x:-16
                    width:10
                    height:30
                    radius: 25
                    color:"#16B712"
                    visible: mainPageIndex == 4
                }
                Text{
                    x:150
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 28
                    color:"#0C0C0C"
                    text:"Stats"
                }
            }
        }


        Image{
            x:1800
            y:80
            width:70
            height:70
            source:"file:./images/head.png"
            MouseArea{
                anchors.fill:parent
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                    pageIndex = 0
                }
            }
        }

    }



    //  返回/退出按钮
    Button{
        id:exit
        visible: pageIndex <= 1
        property var enter: false
        x:1710
        y:910
        width:100
        height:100
        background: Rectangle{
            color:"transparent"
        }
        MouseArea{
            anchors.fill:parent
            hoverEnabled:true
            onEntered: {
                exit.enter = true
            }
            onExited: {
                exit.enter = false
            }
            onClicked: {
                if(pageIndex > 0)
                    pageIndex--
                else
                    Qt.quit()

            }
        }
        Image{
            anchors.fill:parent
            source:exit.enter?"file:./images/exit_active.png":"file:./images/exit.png"
        }
    }

}
