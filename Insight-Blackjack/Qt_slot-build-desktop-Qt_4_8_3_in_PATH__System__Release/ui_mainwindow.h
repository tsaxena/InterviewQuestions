/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Apr 24 14:45:47 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QPushButton *hitButton;
    QPushButton *standButton;
    QPushButton *quitButton;
    QListView *cardTable;
    QHBoxLayout *horizontalLayout_4;
    QLabel *houseLabel;
    QLabel *houseStateLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *playerLabel;
    QLabel *playerStateLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *balanceLabel;
    QLineEdit *lineEdit;
    QPushButton *betButton;
    QLabel *statusLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(548, 443);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 531, 401));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        startButton = new QPushButton(verticalLayoutWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        horizontalLayout->addWidget(startButton);

        hitButton = new QPushButton(verticalLayoutWidget);
        hitButton->setObjectName(QString::fromUtf8("hitButton"));

        horizontalLayout->addWidget(hitButton);

        standButton = new QPushButton(verticalLayoutWidget);
        standButton->setObjectName(QString::fromUtf8("standButton"));

        horizontalLayout->addWidget(standButton);

        quitButton = new QPushButton(verticalLayoutWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        horizontalLayout->addWidget(quitButton);


        verticalLayout->addLayout(horizontalLayout);

        cardTable = new QListView(verticalLayoutWidget);
        cardTable->setObjectName(QString::fromUtf8("cardTable"));

        verticalLayout->addWidget(cardTable);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        houseLabel = new QLabel(verticalLayoutWidget);
        houseLabel->setObjectName(QString::fromUtf8("houseLabel"));

        horizontalLayout_4->addWidget(houseLabel);

        houseStateLabel = new QLabel(verticalLayoutWidget);
        houseStateLabel->setObjectName(QString::fromUtf8("houseStateLabel"));

        horizontalLayout_4->addWidget(houseStateLabel);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        playerLabel = new QLabel(verticalLayoutWidget);
        playerLabel->setObjectName(QString::fromUtf8("playerLabel"));

        horizontalLayout_2->addWidget(playerLabel);

        playerStateLabel = new QLabel(verticalLayoutWidget);
        playerStateLabel->setObjectName(QString::fromUtf8("playerStateLabel"));

        horizontalLayout_2->addWidget(playerStateLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        balanceLabel = new QLabel(verticalLayoutWidget);
        balanceLabel->setObjectName(QString::fromUtf8("balanceLabel"));

        horizontalLayout_3->addWidget(balanceLabel);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);

        betButton = new QPushButton(verticalLayoutWidget);
        betButton->setObjectName(QString::fromUtf8("betButton"));

        horizontalLayout_3->addWidget(betButton);


        verticalLayout->addLayout(horizontalLayout_3);

        statusLabel = new QLabel(verticalLayoutWidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(statusLabel);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 548, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        hitButton->setText(QApplication::translate("MainWindow", "Hit", 0, QApplication::UnicodeUTF8));
        standButton->setText(QApplication::translate("MainWindow", "Stand", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        houseLabel->setText(QApplication::translate("MainWindow", "House", 0, QApplication::UnicodeUTF8));
        houseStateLabel->setText(QString());
        playerLabel->setText(QApplication::translate("MainWindow", "Player", 0, QApplication::UnicodeUTF8));
        playerStateLabel->setText(QString());
        balanceLabel->setText(QApplication::translate("MainWindow", "Balance                                                                                          ", 0, QApplication::UnicodeUTF8));
        betButton->setText(QApplication::translate("MainWindow", "Bet", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
