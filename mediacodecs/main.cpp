#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

#include "mediacodecs.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<MediaCodecs>("MediaCodecs", 1, 0, "MediaCodecs");

    QQuickView view;
    view.setSource(QUrl(QStringLiteral("qrc:///Main.qml")));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();
    return app.exec();
}

