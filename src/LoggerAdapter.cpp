#include "LoggerAdapter.h"
#include "Settings.h"

namespace WalletGui {

LoggerAdapter& LoggerAdapter::instance() {
  static LoggerAdapter inst;
  return inst;
}

void LoggerAdapter::init() {
  Common::JsonValue loggerConfiguration(Common::JsonValue::OBJECT);
  int64_t logLevel =
    #ifdef DEBUG
	  Logging::TRACE
	#else
		Logging::INFO
	#endif
  ;
  loggerConfiguration.insert("globalLevel", logLevel);
  Common::JsonValue& cfgLoggers = loggerConfiguration.insert("loggers", Common::JsonValue::ARRAY);
  Common::JsonValue& fileLogger = cfgLoggers.pushBack(Common::JsonValue::OBJECT);
  fileLogger.insert("type", "file");
  fileLogger.insert("filename", Settings::instance().getDataDir().absoluteFilePath("catawallet.log").toStdString());
  fileLogger.insert("level", logLevel);
  m_logManager.configure(loggerConfiguration);
}

LoggerAdapter::LoggerAdapter() : m_logManager() {
}

LoggerAdapter::~LoggerAdapter() {
}

Logging::LoggerManager& LoggerAdapter::getLoggerManager() {
  return m_logManager;
}

}
