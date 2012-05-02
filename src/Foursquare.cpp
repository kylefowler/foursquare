#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/Control>
#include <bb/cascades/Button>
#include <bb/cascades/TextField>
#include <bb/cascades/animation/groupanimation.h>
#include <bb/cascades/animation/translatetransition.h>
#include <bb/cascades/animation/stockcurve.h>
#include <bb/cascades/Page>

#include "Foursquare.hpp"
#include "FoursquareApi.h"
#include "RequestEnvelope.h"
#include "LoginLayout.h"


using namespace bb::cascades;

Foursquare* Foursquare::appInstance = NULL;

Foursquare::Foursquare()
{
	nav = new NavigationPane();

	// Push the first Control to the stack.
	LoginLayout* first = new LoginLayout();
	Page *p = Page::create();
	p->setContent(first);
	nav->push(p);
	Application::setScene(nav);
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

