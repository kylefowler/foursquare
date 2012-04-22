/*
 * HomeLayout.cpp
 *
 *  Created on: Feb 21, 2012
 *      Author: Kyle
 */

#include "HomeLayout.h"

#include <bb/cascades/controls/listview.h>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/Control>
#include <bb/cascades/Container>
#include <bb/cascades/Label>
#include <bb/cascades/Button>
#include <bb/cascades/DockLayout>
#include <bb/cascades/DockLayoutProperties>
#include <bb/cascades/animation/fadetransition.h>
#include <bb/cascades/animation/groupanimation.h>

HomeLayout::HomeLayout(User *homeUser) :
                CustomControl()
{
	QmlDocument *qml = QmlDocument::create("foursquarehome.qml");
	qml->setContextProperty("lg", this);

	user = homeUser;
	Control *root = qml->createRootNode<Control>();
	userName = root->findChild<Label*>("userName");
	userName->setText(user->getFirstName());

    logoutButton = root->findChild<Button*>("logoutButton");
    connect(logoutButton, SIGNAL(clicked()), this, SLOT(onLogoutClicked()));

	bb::cascades::CustomControl::setRoot(root);
}

HomeLayout::~HomeLayout() {
	delete userName;
}

void HomeLayout::onLogoutClicked() {
	FoursquareApi::instance()->logout();
	Foursquare::instance()->nav->pop();
}
