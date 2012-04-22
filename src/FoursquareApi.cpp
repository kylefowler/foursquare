/*
 * FoursquareApi.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: Kyle
 */

#include "FoursquareApi.h"

FoursquareApi* FoursquareApi::m_instance = NULL;

const QString FoursquareApi::CONSUMER_KEY = QString("KZVMPWA403INWP4FSVVUO4DORGUZR5VEJLZZH3BSUGNC33Q4");
const QString FoursquareApi::CONSUMER_SECRET = QString("KEF2BCCOYZUBWXJAELF4EYAIOHGJOSX4GD2GC3QTLV2B4QAH");
const QString FoursquareApi::API_BASE = QString("https://api.foursquare.com/v2/");

FoursquareApi::FoursquareApi() {
    oauthRequest = new KQOAuthRequest;
    oauthManager = new KQOAuthManager(this);
    //this file should be a file path relative to the assets directory
    oauthManager->setSuccessHtmlFile("loginSuccess.html");
    oauthRequest->setEnableDebugOutput(true);
}

FoursquareApi::~FoursquareApi() {
    delete oauthRequest;
    delete oauthManager;
}

FoursquareApi* FoursquareApi::instance() {
	if(!m_instance) {
		m_instance = new FoursquareApi;
	}
	return m_instance;
}

KQOAuthManager* FoursquareApi::getRequestManager() {
	return oauthManager;
}

void FoursquareApi::onAuthorizationReceived(QString token, QString verifier) {
    qDebug() << "User authorization received: " << token;

    if(token == NULL) {
    	emit loginComplete(false);
        return;
    }
    if( oauthManager->lastError() != KQOAuthManager::NoError) {
        emit loginComplete(false);
    }
    oauthSettings.setValue("oauth_token", token);

    emit loginComplete(token.length() > 0);
    qDebug() << "Access tokens now stored.";
}

void FoursquareApi::login()
{
    connect(oauthManager, SIGNAL(authorizationReceived(QString,QString)), this, SLOT( onAuthorizationReceived(QString, QString)));
    KQOAuthParameters params;
    oauthManager->getOauth2UserAuthorization(QUrl("https://foursquare.com/oauth2/authenticate"),CONSUMER_KEY,params);
}

bool FoursquareApi::checkToken() {
	return oauthSettings.value("oauth_token").toString().isEmpty();
}

KQOAuthRequest* FoursquareApi::getUserInfo() {
	KQOAuth2Request *req = new KQOAuth2Request(this);
	if(!checkToken()) {
		req->initRequest(KQOAuthRequest::AuthorizedRequest, QUrl(API_BASE + "users/self"));
		req->setToken(oauthSettings.value("oauth_token").toString());
		KQOAuthParameters params;
		params.insert("v","20120501");
		req->setAdditionalParameters(params);
		req->setHttpMethod(KQOAuthRequest::GET);
	}
	return req;
}

void FoursquareApi::addAuth(KQOAuthRequest* req) {
	req->setToken(oauthSettings.value("oauth_token").toString());
}

void FoursquareApi::logout() {
	oauthSettings.setValue("oauth_token","");
}
