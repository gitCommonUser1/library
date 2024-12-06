#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "client.h"
#include "datetime.h"
#include "booksmodel.h"

Client *client = nullptr;
BooksModel * booksModel = nullptr;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    client = new Client;
    engine.rootContext()->setContextProperty("client",client);

    DateTime *datetime = new DateTime;
    engine.rootContext()->setContextProperty("datetime",datetime);

    booksModel = new BooksModel;
    engine.rootContext()->setContextProperty("booksModel",booksModel);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    //
    client->getBooks();

    return app.exec();
}
