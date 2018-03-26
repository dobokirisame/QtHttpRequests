#include "DeleteRequest.h"
#include <QNetworkRequest>

namespace requests {

DeleteRequest::DeleteRequest()
	: GetRequest() {
}

std::unique_ptr<QNetworkReply> DeleteRequest::sendRequest(QNetworkAccessManager *manager) {
	if(address().isEmpty() || !manager)
		return nullptr;
	auto request = generateRequest(manager);
	return std::unique_ptr<QNetworkReply>(manager->deleteResource(request));
}

QString DeleteRequest::requestName() const {
	return QObject::tr("DeleteRequest");
}
}
