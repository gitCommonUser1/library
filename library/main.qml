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
                            showTipsDialog(0,"verify error.")
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

    onMainPageIndexChanged: {
        stackViewBooks.addBookFlag = false
    }

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
        //left menu
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
                    id:borrow
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
                    id:books
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
                    id:history
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
                    id:searchs
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
                    id:stats
                    x:150
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 28
                    color:"#0C0C0C"
                    text:"Stats"
                }
            }
        }

        //datetime
        Image{
            x:434
            y:63
            source:"file:./images/datetime.png"
            Text {
                x:5
                y:10
                text:datetime.m
                color:"#F5F8FA"
                font.pixelSize: 22
                font.bold: true
            }
            Rectangle{
                y:40
                width:95
                height:50
                color:"transparent"
                Text {
                    anchors.centerIn: parent
                    text: datetime.d
                    color:"#66757F"
                    font.pixelSize: 42
                    font.bold: true
                }
            }
            Rectangle{
                x:60
                y:38
                width:284
                height:124
                color:"transparent"
                Text {
                    y:30
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: datetime.date
                    color:"#FFFFFF"
                    font.pixelSize: 25
                    font.bold: true
                }
                Text {
                    y:70
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: datetime.time
                    color:"#FFFFFF"
                    font.pixelSize: 25
                    font.bold: true
                }
            }
        }

        //head
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

        Text {
            anchors.horizontalCenter: stackView.horizontalCenter
            anchors.bottom: stackView.top
            anchors.bottomMargin: 40
            color:"white"
            font.pixelSize: 28
            font.bold: true
            text:{
                if(mainPageIndex == 0){
                    // borrow.text
                    ""
                }else if(mainPageIndex == 1){
                    books.text
                }else if(mainPageIndex == 2){
                    history.text
                }else if(mainPageIndex == 3){
                    searchs.text
                }else if(mainPageIndex == 4){
                    stats.text
                }
            }
        }


        Rectangle{
            id:stackView
            x:500
            y:300
            width:1300
            height:700
            color:"transparent"


            //borrow
            Rectangle{
                id:stackViewBorrow
                visible: mainPageIndex == 0
                anchors.fill:parent
                color:"transparent"

                property var borrowFlag: true

                Row{
                    spacing: 20
                    anchors.top:parent.top
                    anchors.topMargin: -40-28
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text{
                        text:"Borrow"
                        color:"white"
                        font.pixelSize: 28
                        font.bold: true
                    }
                    Image{
                        y:-1
                        source:{
                            if(stackViewBorrow.borrowFlag){
                                if(enter){
                                    "file:./images/check_left_active.png"
                                }else{
                                    "file:./images/check_left.png"
                                }
                            }else{
                                if(enter){
                                    "file:./images/check_right_active.png"
                                }else{
                                    "file:./images/check_right.png"
                                }
                            }
                        }

                        property var enter: false
                        MouseArea{
                            anchors.fill:parent
                            hoverEnabled: true
                            onEntered: {
                                parent.enter = true
                            }
                            onExited: {
                                parent.enter = false
                            }
                            onClicked: {
                                stackViewBorrow.borrowFlag = !stackViewBorrow.borrowFlag
                            }
                        }
                    }
                    Text{
                        text:"Return"
                        color:"white"
                        font.pixelSize: 28
                        font.bold: true
                    }
                }

                Rectangle{
                    id:borrowBookRect
                    width:780
                    height:546
                    radius: 35
                    color:"#E5E5E5"
                    opacity: 0.3
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top:parent.top
                    anchors.topMargin: 50
                }
                Rectangle{
                    color:"transparent"
                    anchors.fill:borrowBookRect
                    Image{
                        width:250
                        height:80
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: -40
                        source:enter?"file:./images/submit_active.png":"file:./images/submit.png"
                        property var enter: false
                        MouseArea{
                            anchors.fill:parent
                            hoverEnabled: true
                            onEntered: {
                                parent.enter = true
                            }
                            onExited: {
                                parent.enter = false
                            }
                            onClicked: {
                                if(stackViewBorrow.borrowFlag){
                                    //borrow
                                    client.borrowBook(borrowUserIdInput.textFieldText,borrowBookIdInput.textFieldText,borrowDataInput.textFieldText,)
                                }else{
                                    //return
                                    client.returnBook(borrowBookIdInput.textFieldText,returnDataInput.textFieldText,)
                                }
                            }

                            Connections{
                                target:client
                                function onBorrowBookError(){
                                    showTipsDialog(0,"The borrowing failed.")
                                }
                                function onReturnBookError(){
                                    showTipsDialog(0,"Failed to return the book.")
                                }
                                function onBorrowBookOk(){
                                    showTipsDialog(1,"The borrowing was successful.")
                                }
                                function onReturnBookOk(){
                                    showTipsDialog(1,"The book was returned.")
                                }
                            }
                        }
                    }
                    Row{
                        x:60
                        y:60
                        spacing: 140
                        Column{
                            spacing: 100
                            TextInputRow{
                                id:borrowUserIdInput
                                name:"User ID :     "
                                textColor:stackViewBorrow.borrowFlag?"black":"transparent"
                                enabled: stackViewBorrow.borrowFlag?true:false
                            }
                            TextInputRow{
                                id:borrowBookIdInput
                                name:"Book ID :     "
                            }
                            TextInputRow{
                                id:borrowDataInput
                                name:"Date :        "
                                textFieldText:datetime.dateTime
                                enabled: false
                                textColor:stackViewBorrow.borrowFlag?"black":"transparent"
                            }
                            TextInputRow{
                                id:returnDataInput
                                name:"Return :      "
                                textFieldText:datetime.dateTime
                                enabled: false
                                textColor:stackViewBorrow.borrowFlag?"transparent":"black"
                            }
                        }
                    }
                }

            }


            //books
            Rectangle{
                id:stackViewBooks
                visible: mainPageIndex == 1 && !stackViewBooks.addBookFlag
                anchors.fill:parent
                color:"transparent"

                property var addBookFlag: false
                onAddBookFlagChanged: {
                    nameInput.textFieldText = ""
                    bookIdInput.textFieldText = ""
                    authorInput.textFieldText = ""
                    pagesInput.textFieldText = ""
                    priceInput.textFieldText = ""
                    typeInput.textFieldText = ""
                    languageInput.textFieldText = ""
                }

                Text {
                    id:category
                    x:20
                    text: qsTr("Category")
                    color:"white"
                    font.pixelSize: 20
                    font.bold: true
                }

                LibCombobox{
                    anchors.left:category.right
                    anchors.leftMargin: 20
                    anchors.verticalCenter: category.verticalCenter
                    comboBoxModel:["Story"]
                }

                Text {
                    id:type
                    x:470
                    text: qsTr("Type")
                    color:"white"
                    font.pixelSize: 20
                    font.bold: true
                }

                LibCombobox{
                    anchors.left:type.right
                    anchors.leftMargin: 20
                    anchors.verticalCenter: category.verticalCenter
                    comboBoxModel:["Novel"]
                }

                Text {
                    id:language
                    x:920
                    text: qsTr("Language")
                    color:"white"
                    font.pixelSize: 20
                    font.bold: true
                }

                LibCombobox{
                    anchors.left:language.right
                    anchors.leftMargin: 20
                    anchors.verticalCenter: category.verticalCenter
                    comboBoxModel:["English"]
                }

                Image{
                    width:34
                    height:38
                    anchors.right:gridView.right
                    anchors.rightMargin: 30
                    anchors.verticalCenter: category.verticalCenter
                    source:"file:./images/mi_filter.png"
                }

                Image{
                    anchors.horizontalCenter: gridView.horizontalCenter
                    anchors.top:gridView.bottom
                    // anchors.topMargin: -20
                    source:enter?"file:./images/add_book_active.png":"file:./images/add_book.png"
                    property var enter: false
                    MouseArea{
                        anchors.fill:parent
                        hoverEnabled: true
                        onEntered: {
                            parent.enter = true
                        }
                        onExited: {
                            parent.enter = false
                        }
                        onClicked: {
                            stackViewBooks.addBookFlag = true
                        }
                    }
                }


                GridView {
                    id: gridView
                    anchors.top:category.bottom
                    anchors.topMargin: 40
                    width:1260
                    height:580
                    cellWidth: 630   // 每个单元格的宽度
                    cellHeight: 290  // 每个单元格的高度
                    model: booksModel         // 总共有四个项目
                    clip:true
                    delegate: Item {
                        width: 600
                        height: 260
                        Rectangle{
                            anchors.fill:parent
                            radius: 40
                            color: "#FFFAFA"
                            Image{
                                id:bookImage
                                x:20
                                anchors.verticalCenter: parent.verticalCenter
                                source:"file:./images/test_image.png"
                            }
                            Rectangle{
                                width:98
                                height:28
                                radius: 35
                                x:450
                                y:246
                                color:enter?"#FF0303":"#E43F3F"
                                Text {
                                    anchors.centerIn: parent
                                    text: qsTr("DELETE")
                                    color:"white"
                                    font.pixelSize: 20
                                }
                                property var enter: false
                                MouseArea{
                                    anchors.fill:parent
                                    hoverEnabled: true
                                    onEntered: {
                                        parent.enter = true
                                    }
                                    onExited: {
                                        parent.enter = false
                                    }
                                    onClicked: {
                                        client.removeBook(modelBookId)
                                    }
                                }
                            }

                            Column{
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.left:bookImage.right
                                anchors.leftMargin: 10
                                spacing: 20
                                Text{
                                    color:"black"
                                    font.pixelSize: 19
                                    text:"Name: " + modelName
                                }
                                Text{
                                    color:"black"
                                    font.pixelSize: 19
                                    text:"Author: " + modelAuthor
                                }
                                Text{
                                    color:"black"
                                    font.pixelSize: 19
                                    text:"Book ID: " + modelBookId
                                }
                                Text{
                                    color:"black"
                                    font.pixelSize: 19
                                    text:"Pages: " + modelPages
                                }
                                Text{
                                    color:"black"
                                    font.pixelSize: 19
                                    text:"Price: " + modelPrice
                                }
                            }
                        }
                    }
                }
            }

            //add book rect
            Rectangle{
                id:addBookRect
                anchors.fill:parent
                radius: 35
                color:"#E5E5E5"
                opacity: 0.3
                visible: stackViewBooks.addBookFlag
            }
            //add book
            Rectangle{
                visible: stackViewBooks.addBookFlag
                anchors.fill:addBookRect
                color:"transparent"
                Image{
                    width:250
                    height:80
                    anchors.left:parent.left
                    anchors.leftMargin: 100
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: -40
                    source:enter?"file:./images/cancel_active.png":"file:./images/cancel.png"
                    property var enter: false
                    MouseArea{
                        anchors.fill:parent
                        hoverEnabled: true
                        onEntered: {
                            parent.enter = true
                        }
                        onExited: {
                            parent.enter = false
                        }
                        onClicked: {
                            stackViewBooks.addBookFlag = false
                        }
                    }
                }
                Image{
                    width:250
                    height:80
                    anchors.right:parent.right
                    anchors.rightMargin: 100
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: -40
                    source:enter?"file:./images/submit_active.png":"file:./images/submit.png"
                    property var enter: false
                    MouseArea{
                        anchors.fill:parent
                        hoverEnabled: true
                        onEntered: {
                            parent.enter = true
                        }
                        onExited: {
                            parent.enter = false
                        }
                        onClicked: {
                            client.addBook(nameInput.textFieldText,
                                           bookIdInput.textFieldText,
                                           authorInput.textFieldText,
                                           pagesInput.textFieldText,
                                           priceInput.textFieldText,
                                           typeInput.textFieldText,
                                           languageInput.textFieldText)
                            stackViewBooks.addBookFlag = false
                        }
                    }
                }
                Row{
                    x:50
                    y:50
                    spacing: 140
                    Column{
                        spacing: 80
                        TextInputRow{
                            id:nameInput
                            name:"Book Name :  "
                        }
                        TextInputRow{
                            id:bookIdInput
                            name:"Book ID :    "
                        }
                        TextInputRow{
                            id:authorInput
                            name:"Author Name :"
                        }
                        TextInputRow{
                            id:pagesInput
                            name:"Pages :      "
                            val:TextInputRow.ValidatorType.INT
                        }
                        TextInputRow{
                            id:priceInput
                            name:"Price :      "
                            val:TextInputRow.ValidatorType.DOUBLE
                        }
                        TextInputRow{
                            id:typeInput
                            name:"Type :       "
                        }
                    }
                    Column{
                        TextInputRow{
                            id:languageInput
                            name:"Language :   "
                        }
                    }
                }
            }


            //history
            Rectangle{
                visible: mainPageIndex == 2
            }

            //searchs
            Rectangle{
                visible: mainPageIndex == 3
            }

            //stats
            Rectangle{
                visible: mainPageIndex == 4
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

    Rectangle{
        id:tipsDialog
        z:99
        visible: false
        anchors.fill:parent
        color:"transparent"
        Rectangle{
            anchors.centerIn: parent
            width:400
            height:220
            color:"#E5E5E5"
            radius: 35
            Image{
                id:tipsImage
                width:100
                height:100
                // source:"file:./images/ok.png"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top:parent.top
                anchors.topMargin: -50
            }
            Text {
                id:tipsText
                color:"black"
                font.pixelSize: 24
                width: 320
                wrapMode: Text.WordWrap
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.verticalCenter: parent.verticalCenter
                verticalAlignment: Text.AlignVCenter
            }
            NumberAnimation {
                id:tipsDialogAnimation
                target: tipsDialog
                property: "opacity"
                from: 1.0
                to: 0.0
                duration: 3000
                onFinished: {
                    tipsDialog.visible = false
                }
            }
        }
        MouseArea{
            anchors.fill:parent
            onClicked: {
                tipsDialogAnimation.complete()
            }
        }
    }

    function showTipsDialog(flag,text){
        tipsText.text = text
        tipsDialog.visible = true
        tipsDialogAnimation.restart()
        if(flag == 0){
            //error
            tipsImage.source = "file:./images/error.png"
        }else if(flag == 1){
            //ok
            tipsImage.source = "file:./images/ok.png"
        }
    }
}
