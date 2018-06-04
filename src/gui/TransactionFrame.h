#pragma once

#include <QDataWidgetMapper>
#include <QFrame>
#include <QModelIndex>
#include <QStyledItemDelegate>

namespace Ui {
class TransactionFrame;
}

namespace WalletGui {

class TransactionFrame : public QFrame {
  Q_OBJECT
  Q_DISABLE_COPY(TransactionFrame)

public:
  TransactionFrame(const QModelIndex &_index, QWidget* _parent);
  ~TransactionFrame();

protected:
  void mousePressEvent(QMouseEvent* _event) Q_DECL_OVERRIDE;

private:
  QScopedPointer<Ui::TransactionFrame> m_ui;
  QDataWidgetMapper m_dataMapper;
  QPersistentModelIndex m_index;
};

}