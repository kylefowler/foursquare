#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

#include "app.hpp"

using namespace bb::cascades;

App::App()
{
    QmlDocument *qml = QmlDocument::create("main.qml");
    qml->setContextProperty("cs", this);

    AbstractPane *root = qml->createRootNode<AbstractPane>();
    Application::setScene(root);
}
