#pragma once

#include <QFrame>

class QAbstractButton;

namespace Ui {
class MiningFrame;
}

namespace WalletGui {

class Miner;
class PoolModel;

class MiningFrame : public QFrame {
  Q_OBJECT

public:
  MiningFrame(QWidget* _parent);
  ~MiningFrame();

protected:
  void timerEvent(QTimerEvent* _event) Q_DECL_OVERRIDE;

private:
  QScopedPointer<Ui::MiningFrame> m_ui;
  Miner* m_miner;
  PoolModel* m_poolModel;
  int m_hashRateTimerId;

  void initCpuCoreList();
  void startMining();
  void stopMining();
  void walletClosed();
  Q_SLOT void addPoolClicked();
  Q_SLOT void startStopClicked(QAbstractButton* _button);
};

}
