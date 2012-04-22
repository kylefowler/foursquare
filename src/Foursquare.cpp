#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/Control>
#include <bb/cascades/controls/navigationcontrol.h>
#include <bb/cascades/Button>
#include <bb/cascades/TextField>
#include <bb/cascades/animation/groupanimation.h>
#include <bb/cascades/animation/translatetransition.h>
#include <bb/cascades/animation/stockcurve.h>

#include "Foursquare.hpp"
#include "FoursquareApi.h"
#include "RequestEnvelope.h"
#include "LoginLayout.h"


using namespace bb::cascades;

Foursquare* Foursquare::appInstance = NULL;

Foursquare::Foursquare()
{
	Container *container = new Container();

	// Create the NavigationControl and set its size this is the area were Controls
	// that are pushed and popped are presented. By the default the Navigation Control
	// has a navigation bar with a title, this can also be used to peek (drag on top of the bar)
	// and navigate backwards in the stack.
	nav = new NavigationControl();
	nav->setPreferredSize(1024, 600);

	// Push the first Control to the stack.
	LoginLayout* first = new LoginLayout();
	nav->push(first);
	container->add(nav);
    Application::setScene(container);
}

Foursquare::~Foursquare()
{
}

Foursquare* Foursquare::instance() {
	if(!appInstance) {
		appInstance = new Foursquare;
	}
	return appInstance;
}

