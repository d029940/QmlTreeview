#include <QFileSystemModel>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "treemodel.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    TreeModel *model = new TreeModel();

    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext();
    context->setContextProperty("_model", model);

    const QUrl url(u"qrc:/QmlTreeview/main.qml"_qs);
    //    const QUrl url(u"qrc:/QmlTreeview/mainOwnDelegate.qml"_qs);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
