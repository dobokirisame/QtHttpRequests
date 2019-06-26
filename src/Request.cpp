#include "Request.h"
#include <QUrl>

namespace requests {

Request::Request()
    : mPort(80) {
}

QUrl Request::destinationUrl() const {
    QUrl result(address());
    result.setPort(port());
    return result;
}

bool Request::canSendRequest(QNetworkAccessManager *manager) const {
    return !destinationUrl().isEmpty() &&
            destinationUrl().isValid() &&
            manager != nullptr;
}

QString Request::address() const {
    return mAddress;
}

void Request::setAddress(const QString &address) {
    mAddress = address;
}

int Request::port() const {
    return mPort;
}

void Request::setPort(int port) {
    mPort = port;
}
} //namespace requests
