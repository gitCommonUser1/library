#include <QCoreApplication>
#include <QDebug>
#include "sql.h"
#include "server.h"
#include "imagereceiver.h"

Sql* sql = nullptr;
ImageReceiver *imageReceiver = nullptr;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    sql = new Sql;
    bool connect = sql->connect("localhost",3306,"root","123456","library");
    if(!connect){
        //连接数据库失败
        app.exit(-1);
        return 0;
    }
    imageReceiver = new ImageReceiver;
    Server *server =new Server;
    server->listen(QHostAddress::Any,DEFAULT_PORT);
    return app.exec();
}
