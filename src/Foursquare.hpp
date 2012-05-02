#ifndef FOURSQUARE_H
#define FOURSQUARE_H

#include <QtCore/QObject>
#include <QSettings>
#include <QtNetwork/qnetworkreply.h>
#include <bb/cascades/Application>
#include <bb/cascades/Container>
#include <bb/cascades/NavigationPane>
#include "AbstractObjectBase.h"

using namespace bb::cascades;

namespace bb
{
    namespace cascades
    {
        class Button;
        class TextField;
        class SequentialAnimation;
    }
}
class Foursquare : public QObject
{
    Q_OBJECT

public:
    Foursquare();
    ~Foursquare();
    static Foursquare* instance();
    NavigationPane* nav;
private:
    static Foursquare* appInstance;
private slots:
};

#endif // ifndef HELLOCASCADESAPP_H
