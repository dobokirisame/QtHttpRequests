#include "PostJsonRequest.h"
#include <QNetworkRequest>
#include <QJsonDocument>

namespace requests {

std::unique_ptr<QNetworkReply> PostJsonRequest::sendRequest(QNetworkAccessManager *manager) {
    if(!canSendRequest(manager)) {
        return nullptr;
    }
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setUrl(destinationUrl());
    return std::unique_ptr<QNetworkReply>(manager->post(request, QJsonDocument(jsonRequest()).toJson()));
}

QJsonObject PostJsonRequest::jsonRequest() const {
    return jsonRequest(parameters());
}

QJsonObject PostJsonRequest::jsonRequest(const std::map<QString, QString> &parameters) const {
    QJsonObject result;
    for(const auto &param : parameters) {
        result.insert(param.first, param.second);
    }
    if(!filters().isEmpty()) {
        QJsonObject enabledFilters;
        for(const auto &filter : filters()) {
            enabledFilters.insert(filter, "true");
        }
        result.insert(mFiltersKey, enabledFilters);
    }
    return result;
}

QStringList PostJsonRequest::filters() const {
    return mFilters;
}

void PostJsonRequest::setFilters(const QStringList &filters) {
    mFilters = filters;
}

void PostJsonRequest::setFiltersKey(const QString &filtersKey) {
    mFiltersKey = filtersKey;
}

QString PostJsonRequest::requestName() const {
    return QObject::tr("PostJsonRequest");
}
} //namespace requests
