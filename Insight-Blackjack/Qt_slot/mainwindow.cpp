#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
     * set GUI properties
     */
    setWindowTitle(tr("Blackjack "));
    resize(550,420);

    /*labels for the card table*/
    QLabel *houseLabel = new QLabel(ui->cardTable);
    QLabel *playerLabel = new QLabel(ui->cardTable);
    houseLabel->setText("House");
    playerLabel->setText("Player");
    houseLabel->move(10,20);
    playerLabel->move(10,150);

    /*labels for the balance */
    ui->lineEdit->setFixedWidth(100);
    ui->lineEdit->move(400,20);
    ui->balanceLabel->setFixedWidth(400);
    ui->balanceLabel->setText(QString("You have ") + QString::number(100)+ QString(" Dollars"));

    /*disable hit and stand buttons */
    this->setEnableHitStandButtons(false);
    this->setEnableBetButton(false);
    this->setupCardIcons();

    /*
     * connect the signal with the slot
     */
    this->game_ = new Game();
    connect( ui->hitButton, SIGNAL(clicked()), this->game_, SLOT(hit()));
    connect( this, SIGNAL(startDeal()), this->game_, SLOT(start()));
    connect( this->game_, SIGNAL(statusChanged(int)), this, SLOT(handleStatusChanged(int)));
    connect( this->game_, SIGNAL(balanceChanged(int)), this, SLOT(handleBalanceChanged(int)));
    connect( this->game_, SIGNAL(handChanged(std::vector<Card>, bool)), this, SLOT(handleHandChanged(std::vector<Card>,bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setEnableHitStandButtons(bool b)
{
    ui->hitButton->setEnabled(b);
    ui->standButton->setEnabled(b);
}


void MainWindow::setEnableBetButton(bool b)
{
    ui->betButton->setEnabled(b);
    if(b){
        ui->lineEdit->clear();
        ui->lineEdit->setEnabled(b);
    }else{
         ui->lineEdit->setEnabled(false);
    }
    ui->quitButton->setEnabled(b);
}

void MainWindow::setEnableStartButton(bool b)
{
    ui->startButton->setEnabled(b);
}


void MainWindow::on_startButton_clicked()
{
    this->setEnableStartButton(false);
    this->setEnableBetButton(true);
    this->clearIcons();
    this->showStatus("Place a bet or quit");
}


void MainWindow::on_standButton_clicked()
{
    this->setEnableHitStandButtons(false);
    this->game_->stand();
}


void MainWindow::on_betButton_clicked()
{
    QString number_string = ui->lineEdit->text();
    int balance = this->game_->player_.getBalance();
    int bet = number_string.toInt();
    if(bet >= 1 && bet <= balance){
        this->game_->player_.bets(bet);
        this->setEnableBetButton(false);
        ui->balanceLabel->setText(QString("You have ") + QString::number(balance)+ QString(" Dollars"));
        this->setEnableHitStandButtons(true);
        this->clearStatus();
        emit startDeal();
    }else{

        QMessageBox::information(this, tr("Invalid Input"), tr("Enter a number less than balance") );
        ui->lineEdit->clear();
        this->showStatus("Place a bit between");
    }
}

void MainWindow::clearStatus()
{
    ui->statusLabel->clear();
}


void MainWindow::handleHandChanged(std::vector<Card> cards,  bool isDealer){
    std::vector<Card>::iterator card_iterator = cards.begin();
    int pos = 0;
    for(; card_iterator != cards.end(); ++card_iterator){
        this->drawCard(pos++, isDealer, *card_iterator);
        QEventLoop loop;
        QTimer::singleShot(200, &loop, SLOT(quit()));
        loop.exec();
    }

}


void MainWindow::setupCardIcons()
{
    for(int i = 0 ; i < 10; i++){
        QLabel* position = new QLabel(ui->cardTable);
        position->move(80 + 60*i,20);
        QPixmap supremect(":/icons/images/blank.gif");
        position->setPixmap(supremect);
        this->houseCardPositions_.push_back(position);
       // this->cardPositions_[0]->show();
    }

    for (int i = 0; i < 10; i++) {
        QLabel* position = new QLabel(ui->cardTable);
        position->move(80 + 60*i,150);
        QPixmap supremect(":/icons/images/blank.gif");
        position->setPixmap(supremect);
        this->playerCardPositions_.push_back(position);
    }
}


void MainWindow::clearIcons()
{
    QPixmap qpx = QPixmap(":/images/blank.png");
    for (int i = 0; i < this->playerCardPositions_.size(); i++) {
        this->playerCardPositions_[i]->setPixmap(qpx);
    }

    for (int i = 0; i < this->houseCardPositions_.size(); i++) {
        this->houseCardPositions_[i]->setPixmap(qpx);
    }
    /*clear the text boxes*/
    ui->houseStateLabel->clear();
    ui->playerStateLabel->clear();
    this->clearStatus();
}



void MainWindow::drawCard(int position, bool isDealer, Card card){
    string str = this->cardToIcon(card.getRank(), card.getSuit(), card.isFaceUp());
    QPixmap supremect(str.c_str());
    if(isDealer){
         this->houseCardPositions_[position]->setPixmap(supremect);
         this->houseCardPositions_[position]->show();
         QString ss = QString::fromStdString(this->game_->dealer_.getStateString());
         ui->houseStateLabel->setText(ss);
    }else{

        this->playerCardPositions_[position]->setPixmap(supremect);
        this->playerCardPositions_[position]->show();
        QString ss = QString::fromStdString(this->game_->player_.getStateString());
        ui->playerStateLabel->setText(ss);
    }

}


void MainWindow::handleStatusChanged(int s){
    switch(s){
        case Game::PLAYER_BUSTED: { this->showStatus("You busted by going over 21"); break;}

        case Game::DEALER_BUSTED: { this->showStatus("Dealer busted by going over 21"); break;}

        case Game::PLAYER_STAND : { this->game_->stand(); break; }

        case Game::PLAYER_BLACKJACK: {
                                       this->showStatus("You have blackjack");
                                       this->setEnableHitStandButtons(false);
                                       this->game_->stand();
                                       break;
                                     }
        case Game::PLAYER_WINS:      {  QMessageBox::information(this, tr("Result"), tr("You won!") );
                                        this->setEnableHitStandButtons(false);
                                        this->setEnableStartButton(true);
                                        break;}
        case Game::DEALER_WINS:      {  QMessageBox::information(this, tr("Result"), tr("You lost!") );
                                        this->setEnableHitStandButtons(false);
                                        this->setEnableStartButton(true);
                                        break;}
       case Game::PLAYER_PUSHES:  {  QMessageBox::information(this, tr("Result"), tr("Push!") );
                                     this->setEnableHitStandButtons(false);
                                     this->setEnableStartButton(true);
                                     break;}

    }
}

void MainWindow::handleBalanceChanged(int balance){
     ui->balanceLabel->setText(QString("You have ") + QString::number(balance)+ QString(" Dollars"));
}



void MainWindow::showStatus(QString str)
{
    QString labelText = "<P><b><FONT COLOR='#0000FF' FONT SIZE = 3>";
    labelText .append(str);
    labelText .append("</i></b></P></br>");
    ui->statusLabel->setText(labelText);
}

std::string MainWindow::cardToIcon(int rank, int suit, bool isFaceUp){
    ostringstream oss;
    string str;
    const string RANKS[] = {"14", "02", "03", "04", "05", "06", "07", "08", "09","10", "11", "12", "13"};
    const string SUITS[] = {"1", "2", "3", "4"};

    if (isFaceUp){
       oss << ":icons/images/" << SUITS[suit] << RANKS[rank] << ".gif";
    }
    else{
       oss << ":icons/images/" << "cardback" << ".gif";
    }
    str = oss.str();
    return str;
}





/*void MainWindow::handleDeal(std::vector<Card> playerCards, std::vector<Card> houseCards)
{
    QEventLoop loop;

    /*Draw player cards*/
    /*for(size_t i =0 ; i < playerCards.size(); i++){
        this->drawCard(i, false, playerCards[i]);
        // This will stupidly wait 1 sec doing nothing...
        QTimer::singleShot(500, &loop, SLOT(quit()));
        loop.exec();
    }

    /*Draw house cards*/
    /*for(size_t i =0 ; i < houseCards.size(); i++){
        this->drawCard(i, true, houseCards[i]);
        QTimer::singleShot(500, &loop, SLOT(quit()));
        loop.exec();
    }

    QTimer::singleShot(500, &loop, SLOT(quit()));
    loop.exec();

    //if the player already has a blackjack
    if(this->game_->player_.hand.isBlackjack()){
        this->showStatus("Place a bit between");
    }
}*/




