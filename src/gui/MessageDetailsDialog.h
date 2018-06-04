#pragma once

#include <QDataWidgetMapper>
#include <QDialog>

namespace Ui {
class MessageDetailsDialog;
}

namespace WalletGui {

class MessageDetailsDialog : public QDialog {
  Q_OBJECT

public:
  MessageDetailsDialog(const QModelIndex& _index, QWidget* _parent);
  ~MessageDetailsDialog();

  QModelIndex getCurrentMessageIndex() const;

private:
  QScopedPointer<Ui::MessageDetailsDialog> m_ui;
  QDataWidgetMapper m_dataMapper;

  Q_SLOT void prevClicked();
  Q_SLOT void nextClicked();
  Q_SLOT void saveClicked();
};

}
