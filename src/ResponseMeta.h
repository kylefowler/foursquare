/*
 * ResponseMeta.h
 *
 *  Created on: Feb 18, 2012
 *      Author: Kyle
 */

#ifndef RESPONSEMETA_H_
#define RESPONSEMETA_H_

#include "AbstractObjectBase.h"
#include <QtCore>

class ResponseMeta: public AbstractObjectBase {
public:
	ResponseMeta();
	virtual ~ResponseMeta();
	void parse(QVariantMap);
	void setCode(const int);
	void setErrorType(const QString&);
	int getStatus();
	QString getErrorType();
private:
	int code;
	QString errorType;
};

#endif /* RESPONSEMETA_H_ */
