#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <vector>
#include "player.h"
#include "dealer.h"
#include "deck.h"

 class Game : public QObject
 {
     Q_OBJECT

 public:
     enum GameState {PLAYER_BUSTED,
                     DEALER_BUSTED,
                     PLAYER_BLACKJACK,
                     DEALER_BLACKJACK,
                     PLAYER_STAND,
                     DEALER_WINS,
                     PLAYER_WINS,
                     PLAYER_PUSHES};
     Dealer dealer_;
     Player player_;

     Game();
     ~Game();

     void deal();
     void reset();
     void play();
     void hitDealer();
     void hitPlayer();
     void stand();
     void showdown();

 public slots:
     //void setValue(int value);
     void hit();
     void start();

 signals:
     void handChanged(std::vector<Card>, bool);
     void statusChanged(int);
     void balanceChanged(int);


 private:
     std::vector<int> cards;

     Deck deck_;
 };

#endif // GAME_H
