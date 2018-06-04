#include "VisibleMessagesModel.h"
#include "MessagesModel.h"
#include "SortedMessagesModel.h"

namespace WalletGui {

VisibleMessagesModel::VisibleMessagesModel() : QSortFilterProxyModel() {
  setSourceModel(&SortedMessagesModel::instance());
}

VisibleMessagesModel::~VisibleMessagesModel() {
}

bool VisibleMessagesModel::filterAcceptsColumn(int _sourceColumn, const QModelIndex& _sourceParent) const {
  return _sourceColumn == MessagesModel::COLUMN_DATE || _sourceColumn == MessagesModel::COLUMN_TYPE ||
    _sourceColumn == MessagesModel::COLUMN_HEIGHT || _sourceColumn == MessagesModel::COLUMN_MESSAGE;
}

}
