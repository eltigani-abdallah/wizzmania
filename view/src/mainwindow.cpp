#include "../include/mainwindow.hpp"

#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

static QWidget* makeBubbleWidget(const QString &text, bool outgoing) {
    auto *container = new QWidget;
    auto *layout = new QHBoxLayout(container);
    layout->setContentsMargins(8, 2, 8, 2);

    auto *bubble = new QLabel(text);
    bubble->setWordWrap(true);
    bubble->setTextInteractionFlags(Qt::TextSelectableByMouse);

    // Style simple type "bulle"
    bubble->setStyleSheet(outgoing
        ? "QLabel { background:#20b2aa; color:white; padding:10px; border-radius:12px; }"
        : "QLabel { background:#777777; color:white; padding:10px; border-radius:12px; }"
    );

    // Alignement gauche/droite
    if (outgoing) {
        layout->addStretch();
        layout->addWidget(bubble, 0);
    } else {
        layout->addWidget(bubble, 0);
        layout->addStretch();
    }
    return container;
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    socket = new QTcpSocket(this);

    list = new QListWidget(this);
    list->setSpacing(6);
    list->setStyleSheet("QListWidget { background:#444; border:none; }");
    list->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

    input = new QLineEdit(this);
    input->setPlaceholderText("Écrire un message...");
    input->setStyleSheet("QLineEdit { padding:10px; border-radius:8px; }");

    sendBtn = new QPushButton("Send", this);
    sendBtn->setStyleSheet("QPushButton { padding:10px 14px; border-radius:8px; }");

    auto *central = new QWidget(this);
    auto *root = new QVBoxLayout(central);
    root->addWidget(list);

    auto *bottom = new QHBoxLayout();
    bottom->addWidget(input, 1);
    bottom->addWidget(sendBtn);
    root->addLayout(bottom);

    setCentralWidget(central);
    setWindowTitle("ChatBot");
    resize(520, 420);

    connect(sendBtn, &QPushButton::clicked, this, &MainWindow::sendMessage);
    connect(input, &QLineEdit::returnPressed, this, &MainWindow::sendMessage);

    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::onReadyRead);
    connect(socket, &QTcpSocket::connected, this, &MainWindow::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::onDisconnected);
    connect(socket, &QTcpSocket::errorOccurred, this, &MainWindow::onErrorOccurred);

    connectToServer();
}

void MainWindow::connectToServer() {
    socket->connectToHost("127.0.0.1", 4242);
}

void MainWindow::onConnected() {
    addBubble("Connecté au serveur.", false);
}

void MainWindow::onDisconnected() {
    addBubble("Déconnecté.", false);
}

void MainWindow::onErrorOccurred(QAbstractSocket::SocketError) {
    addBubble("Erreur socket: " + socket->errorString(), false);
}

void MainWindow::sendMessage() {
    const QString text = input->text().trimmed();
    if (text.isEmpty() || socket->state() != QAbstractSocket::ConnectedState)
        return;

    // Affichage local (bulle sortante)
    addBubble(text, true);

    // Envoi serveur (ligne terminée par \n)
    const QString payload = nickname + ": " + text + "\n";
    socket->write(payload.toUtf8());

    input->clear();
}

void MainWindow::onReadyRead() {
    while (socket->canReadLine()) {
        const QString line = QString::fromUtf8(socket->readLine()).trimmed();
        // On peut filtrer si c’est notre propre message, mais pas obligatoire
        addBubble(line, false);
    }
}

void MainWindow::addBubble(const QString &text, bool outgoing) {
    auto *item = new QListWidgetItem();
    item->setFlags(item->flags() & ~Qt::ItemIsSelectable);

    QWidget *w = makeBubbleWidget(text, outgoing);
    item->setSizeHint(w->sizeHint());

    list->addItem(item);
    list->setItemWidget(item, w);
    list->scrollToBottom();
}
