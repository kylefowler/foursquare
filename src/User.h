/*
 * User.h
 *
 *  Created on: Feb 20, 2012
 *      Author: Kyle
 */

#ifndef USER_H_
#define USER_H_

#include "AbstractObjectBase.h"
#include <QtCore>
#include <QtCore/QList>
#include "qlist.h"

class User: public AbstractObjectBase {
public:
	User();
	virtual ~User();
	void parse(QVariantMap);
	QString getFirstName();
    void setFirstName(QString name);
private:
	QString firstName;
};

#endif /* USER_H_ */
