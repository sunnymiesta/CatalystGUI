#pragma once

#include <QSortFilterProxyModel>

namespace WalletGui {

class VisibleMessagesModel : public QSortFilterProxyModel {
  Q_OBJECT

public:
  VisibleMessagesModel();
  ~VisibleMessagesModel();

protected:
  bool filterAcceptsColumn(int _sourceColumn, const QModelIndex& _sourceParent) const Q_DECL_OVERRIDE;
};

}
