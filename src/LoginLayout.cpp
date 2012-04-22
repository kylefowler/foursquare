/*
 * LoginLayout.cpp
 *
 *  Created on: Mar 24, 2012
 *      Author: Kyle
 */

#include "LoginLayout.h"

LoginLayout::LoginLayout() {
    QmlDocument *qml = QmlDocument::create("foursquarelogin.qml");
    qml->setContextProperty("cs", this);

    Control *root = qml->createRootNode<Control>();
    loginButton = root->findChild<Button*>("login");
    if(!FoursquareApi::instance()->checkToken()) {
    	loginButton->setText("Logged In. Continue to dashboard.");
    }
    connect(loginButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    bb::cascades::CustomControl::setRoot(root);
}

LoginLayout::~LoginLayout() {
}


void LoginLayout::makeLoginRequest()
{
	qDebug() << "Making request";
	connect(FoursquareApi::instance(), SIGNAL(loginComplete(bool)),this,SLOT(onLoginResponse(bool)));
	FoursquareApi::instance()->login();
}

void LoginLayout::onButtonClicked()
{
	if(FoursquareApi::instance()->checkToken()) {
		loginButton->setText("Logging In");
		makeLoginRequest();
	} else {
		SequentialAnimation* anim = SequentialAnimation::create(loginButton)
						.add(TranslateTransition::create(loginButton).toX(100).duration(500).easingCurve(StockCurve::QuadraticOut))
						.add(TranslateTransition::create(loginButton).toX(-100).duration(500).easingCurve(StockCurve::QuadraticIn))
						.add(TranslateTransition::create(loginButton).toX(50).duration(500).easingCurve(StockCurve::QuadraticOut))
						.add(TranslateTransition::create(loginButton).toX(0).duration(500).easingCurve(StockCurve::QuadraticIn));
		anim->play();
		RequestEnvelope *env = new RequestEnvelope(ApiResponseObjectFactory::UserObj, FoursquareApi::instance()->getUserInfo());
		connect(env, SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onUserDataLoad(AbstractObjectBase*)));
		env->makeRequest();
	}
}

void LoginLayout::requestComplete(QNetworkReply* reply)
{
	qDebug() << "Response Received";
	qDebug() << QString(reply->readAll());
}

void LoginLayout::onLoginResponse(bool success) {
	if(success) {
		qDebug() << "Login success yayyyyy";
		loginButton->setText("Login Success");
		SequentialAnimation* anim = SequentialAnimation::create(loginButton)
						.add(TranslateTransition::create(loginButton).toX(100).duration(500).easingCurve(StockCurve::QuadraticOut))
						.add(TranslateTransition::create(loginButton).toX(-100).duration(500).easingCurve(StockCurve::QuadraticIn))
						.add(TranslateTransition::create(loginButton).toX(50).duration(500).easingCurve(StockCurve::QuadraticOut))
						.add(TranslateTransition::create(loginButton).toX(0).duration(500).easingCurve(StockCurve::QuadraticIn));
		anim->play();
		RequestEnvelope *env = new RequestEnvelope(ApiResponseObjectFactory::UserObj, FoursquareApi::instance()->getUserInfo());
		//FIXME I think the this keyword is referring to the object doing the emitting and not the tumblr class and causing callback issues
		connect(env, SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onUserDataLoad(AbstractObjectBase*)));
		env->makeRequest();
	} else {
		qDebug() << "Login failed womp womp";
		loginButton->setText("Login Failed");
	}
	disconnect(FoursquareApi::instance(), SIGNAL(loginComplete(bool)),this,SLOT(onLoginResponse(bool)));
}

void LoginLayout::onUserDataLoad(AbstractObjectBase* user) {
	User* usr = dynamic_cast<User*>(user);
	HomeLayout *home = new HomeLayout(usr);
	Foursquare::instance()->nav->push(home);
	//Application::setScene(home);
}

