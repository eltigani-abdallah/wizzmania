#pragma once
#include <QMainWindow>
#include <QTcpSocket>

class QListWidget;
class QLineEdit;
class QPushButton;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent=nullptr);
    ~MainWindow() override = default;

private slots:
    void connectToServer();
    void sendMessage();
    void onReadyRead();
    void onConnected();
    void onDisconnected();
    void onErrorOccurred(QAbstractSocket::SocketError);

private:
    void addBubble(const QString &text, bool outgoing);

    QTcpSocket *socket;
    QListWidget *list;
    QLineEdit *input;
    QPushButton *sendBtn;

    QString nickname = "User1";
};
