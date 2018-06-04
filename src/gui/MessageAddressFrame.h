#pragma once

#include <QFrame>

namespace Ui {
  class MessageAddressFrame;
}

namespace WalletGui {

class AliasProvider;

class MessageAddressFrame : public QFrame {
  Q_OBJECT
  Q_DISABLE_COPY(MessageAddressFrame)

public:
  MessageAddressFrame(QWidget* _parent);
  ~MessageAddressFrame();

  QString getAddress() const;
  void disableRemoveButton(bool _disable);

protected:
  void timerEvent(QTimerEvent* _event) Q_DECL_OVERRIDE;

private:
  QScopedPointer<Ui::MessageAddressFrame> m_ui;
  AliasProvider* m_aliasProvider;
  int m_addressInputTimerId;

  void onAliasFound(const QString& _name, const QString& _address);

  Q_SLOT void addressBookClicked();
  Q_SLOT void addressEdited(const QString& _text);
  Q_SLOT void pasteClicked();
};

}
