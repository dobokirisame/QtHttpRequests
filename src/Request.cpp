#include "Request.h"

namespace requests {


Request::Request()
    : mPort(80) {
}

Request::~Request() {
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
}
