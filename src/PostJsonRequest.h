#ifndef POSTJSONREQUEST_H
#define POSTJSONREQUEST_H
#include "GetRequest.h"
#include <QJsonObject>
#include "QHttpRequests_global.h"

namespace requests {

class QHTTPREQUESTSSHARED_EXPORT PostJsonRequest : public GetRequest
{
public:
    PostJsonRequest() = default;
    std::unique_ptr<QNetworkReply> sendRequest(QNetworkAccessManager *manager) override;
    QStringList filters() const;
    void setFilters(const QStringList &filters);
    void setFiltersKey(const QString &filtersKey);
    QString requestName() const override;
protected:
    QJsonObject jsonRequest() const;
    QJsonObject jsonRequest(const std::map<QString, QString> &parameters) const;
private:
    QStringList mFilters;
    QString mFiltersKey;
};
} //namespace requests
#endif // POSTJSONREQUEST_H
