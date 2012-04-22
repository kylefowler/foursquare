/*
 * ResponseMeta.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: Kyle
 */

#include "ResponseMeta.h"

ResponseMeta::ResponseMeta() {

}

ResponseMeta::~ResponseMeta() {
}

void ResponseMeta::parse(QVariantMap obj) {
	setCode(obj["code"].toInt());
	if(obj.contains("errorType")) {
		setErrorType(obj["errorType"].toString());
	}
}

void ResponseMeta::setCode(const int respStatus) {
	code = respStatus;
}

void ResponseMeta::setErrorType(const QString& respMsg) {
	errorType = respMsg;
}

int ResponseMeta::getStatus() {
	return code;
}

QString ResponseMeta::getErrorType() {
	return errorType;
}

