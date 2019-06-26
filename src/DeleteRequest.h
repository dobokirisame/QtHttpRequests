#ifndef DELETEREQUEST_H
#define DELETEREQUEST_H
#include "GetRequest.h"
#include "QHttpRequests_global.h"

namespace requests {

class QHTTPREQUESTSSHARED_EXPORT DeleteRequest : public GetRequest
{
public:
    DeleteRequest() = default;
    std::unique_ptr<QNetworkReply> sendRequest(QNetworkAccessManager *manager) override;
    QString requestName() const override;
};
} //namespace requests
#endif // DELETEREQUEST_H
