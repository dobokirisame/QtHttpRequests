#ifndef DELETEREQUEST_H
#define DELETEREQUEST_H
#include "GetRequest.h"
#include "QHttpRequests_global.h"

namespace requests {

class QHTTPREQUESTSSHARED_EXPORT DeleteRequest : public GetRequest
{
public:
	DeleteRequest();
	std::unique_ptr<QNetworkReply> sendRequest(QNetworkAccessManager *manager) override;
	QString requestName() const override;
};
}
#endif // DELETEREQUEST_H
