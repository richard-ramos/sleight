#ifndef STATUS_H
#define STATUS_H
#include <QString>
#include <QVector>
#include <QObject>



class Status : public QObject {
  Q_OBJECT

public:
  explicit Status(QObject * parent = nullptr);
  ~Status() {}
  Q_INVOKABLE QString multiAccountGenerateAndDeriveAddresses(int n, int mnemonicPhraseLength, QString bip32Passphrase);

  Q_INVOKABLE QString multiAccountStoreDerivedAccounts(QString accountJson, QString password);
  Q_INVOKABLE QString generateAlias(QString publicKey);
  Q_INVOKABLE QString generateIdenticon(QString publicKey);
  Q_INVOKABLE QString saveAccountAndLogin(QString multiaccData,
                                          QString password,
                                          QString settings,
                                          QString nodeConfig,
                                          QString accountsData);
  Q_INVOKABLE QString openAccounts();
  Q_INVOKABLE QString login(QString loginData, QString password);
  Q_INVOKABLE QString initKeystore();
  Q_INVOKABLE void callPrivateRPC(QString payload);

signals:
  void privateRPCResult(QString result);

private:
  static void statusGoEventCallback(const char *event);
  QString prepareDirAndUpdateConfig(QString configString);
};

#endif // STATUS_H
