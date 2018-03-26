#ifndef REQUESTSENDER_H
#define REQUESTSENDER_H

#include <QObject>
#include <memory>
#include "QHttpRequests_global.h"

class QNetworkAccessManager;
namespace requests {

class Request;

class QHTTPREQUESTSSHARED_EXPORT RequestSender : public QObject
{
	Q_OBJECT
public:
	explicit RequestSender(QObject *parent = nullptr);
public slots:
	QByteArray sendRequest(const std::unique_ptr<Request> &request) const;
private:
	QNetworkAccessManager *mManager;
};
}
#endif // REQUESTSENDER_H
