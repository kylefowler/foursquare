/*
 * FoursquareApi.h
 *
 *  Created on: Feb 18, 2012
 *      Author: Kyle
 */

#ifndef FOURSQUAREAPI_H_
#define FOURSQUAREAPI_H_

#include <iostream>
#include <QtCore>
#include <QtCore/QObject>
#include <QSettings>
#include <oauth/kqoauthmanager.h>
#include <oauth/kqoauth2request.h>

class FoursquareApi : public QObject {
	Q_OBJECT
public:
	static const QString API_BASE;
	static FoursquareApi* instance();
	void login();
    void logout();
	bool checkToken();
	KQOAuthManager* getRequestManager();

	//api methods
	KQOAuthRequest* getUserInfo();
	void addAuth(KQOAuthRequest* req);
private:
	FoursquareApi();
	virtual ~FoursquareApi();
	static const QString CONSUMER_KEY;
	static const QString CONSUMER_SECRET;
	static FoursquareApi* m_instance;
    KQOAuthManager *oauthManager;
    KQOAuthRequest *oauthRequest;
    QSettings oauthSettings;

signals:
	void loginComplete(bool);

private slots:
	void onAuthorizationReceived(QString token, QString verifier);
};

#endif /* TUMBLRAPI_H_ */
