#pragma once

#include <QObject>
#include <QNetworkAccessManager>

namespace WalletGui {

class AliasProvider : public QObject {
  Q_OBJECT

public:
  AliasProvider(QObject *parent);
  ~AliasProvider();

  void getAddresses(const QString& _urlString);

private:
  QNetworkAccessManager m_networkManager;
  void readyRead();

Q_SIGNALS:
  void aliasFoundSignal(const QString& _name, const QString& _address);
};

}
