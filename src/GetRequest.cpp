#include "GetRequest.h"
#include <QNetworkRequest>
#include <QUrl>

namespace requests {

namespace {
constexpr QStringView httpsPrefix{QStringViewLiteral("https")};
} // namespace

std::unique_ptr<QNetworkReply> GetRequest::sendRequest(QNetworkAccessManager *manager) {
    if(!canSendRequest(manager)) {
        return nullptr;
    }
    auto request = generateRequest(manager);
    return std::unique_ptr<QNetworkReply>(manager->get(request));
}

void GetRequest::addParameter(const QString &parameterName, const QString &parameterValue) {
    mParameters.insert({parameterName, parameterValue});
}

QString GetRequest::parametersString() const {
    return parametersString(mParameters);
}

QString GetRequest::parametersString(const std::map<QString, QString> &parameters) const {
    QString result;
    for(const auto &param : parameters) {
        result.append(param.first);
        result.append('=');
        result.append(param.second);
        result.append('&');
    }
    return result;
}

QNetworkRequest GetRequest::generateRequest(QNetworkAccessManager *manager) const {
    QNetworkRequest request;
    QUrl url(address());
    if(address().startsWith(httpsPrefix)) {
        manager->connectToHostEncrypted(address());
    }

    url.setQuery(parametersString());

    QSslConfiguration sslConfiguration(QSslConfiguration::defaultConfiguration());
    sslConfiguration.setProtocol(QSsl::SecureProtocols);
    request.setSslConfiguration(sslConfiguration);
    request.setUrl(url);
    return request;
}

std::map<QString, QString> GetRequest::parameters() const {
    return mParameters;
}

QString GetRequest::requestName() const {
    return QObject::tr("GetRequest");
}

} //namespace requests
