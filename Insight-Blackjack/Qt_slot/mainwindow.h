#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include "card.h"
class Game;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setEnableHitStandButtons(bool b);
    void setEnableBetButton(bool b);
    void setEnableStartButton(bool b);
    void showStatus(QString str);
    void clearStatus();
    void setupCardIcons();
    void clearIcons();
    std::string cardToIcon(int rank, int suit, bool isFaceUp);
    void drawCard(int position, bool isDealer, Card card);

private slots:
    void on_startButton_clicked();
    void on_betButton_clicked();
    void on_standButton_clicked();
    void handleHandChanged(std::vector<Card> playerCards, bool isDealer);
    void handleStatusChanged(int position);
    void handleBalanceChanged(int balance);

signals:
    void startDeal();

private:
    Ui::MainWindow *ui;
    Game* game_;
    QVector<QLabel*> houseCardPositions_;
    QVector<QLabel*> playerCardPositions_;
};

#endif // MAINWINDOW_H
