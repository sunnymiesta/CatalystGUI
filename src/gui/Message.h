#pragma once

#include <QDateTime>
#include <QList>
#include <QPair>

namespace WalletGui {

typedef QList<QPair<QString, QString> > MessageHeader;

class Message {
public:
  Message();
  Message(const Message& _message);
  Message(const Message&& _message);
  Message(const QString& _message);
  ~Message();

  QString getMessage() const;
  QString getFullMessage() const;
  QString getHeaderValue(const QString& _key) const;

  Message& operator=(const Message& _message);

  static QString makeTextMessage(const QString& _message, const MessageHeader& _header);

private:
  QString m_message;
  MessageHeader m_header;
};

}
