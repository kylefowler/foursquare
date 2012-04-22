/*
 * User.cpp
 *
 *  Created on: Feb 20, 2012
 *      Author: Kyle
 */

#include "User.h"

User::User() {
}

User::~User() {
}

void User::parse(QVariantMap qMap)
{
	QVariantMap map(qMap["user"].toMap());
	setFirstName(map["firstName"].toString());
}

QString User::getFirstName()
{
	return firstName;
}

void User::setFirstName(QString name)
{
    this->firstName = name;
}
