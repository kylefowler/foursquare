#ifndef APP_H
#define APP_H

#include <QtCore/QObject>
#include <QtCore/QMetaType>

#include <bb/cascades/Event>
#include <bb/cascades/UiObject>
#include <bb/cascades/Control>

class App : public QObject
{
    Q_OBJECT

public:
    App();

};

#endif // ifndef APP_H
