#ifndef REQUEST_H
#define REQUEST_H
#include <QByteArray>
#include <memory>
#include <QString>
#include <QNetworkReply>
#include "QHttpRequests_global.h"

class QNetworkRequest;
class QNetworkAccessManager;
namespace requests {

class QHTTPREQUESTSSHARED_EXPORT Request
{
public:
	Request();
	virtual ~Request();
	virtual std::unique_ptr<QNetworkReply> sendRequest(QNetworkAccessManager *manager) = 0;
	virtual QString requestName() const = 0;
	QString address() const;
	void setAddress(const QString &address);
	int port() const;
	void setPort(int port);

private:
	QString mAddress;
	int mPort;
};
}
#endif // REQUEST_H
