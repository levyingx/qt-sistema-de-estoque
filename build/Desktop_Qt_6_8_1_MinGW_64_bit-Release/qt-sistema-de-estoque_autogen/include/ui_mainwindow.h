/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *botaoImportar;
    QPushButton *botaoAdicionar;
    QPushButton *botaoRemover;
    QPushButton *botaoGerarRelatorio;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 430);
        MainWindow->setMinimumSize(QSize(400, 420));
        MainWindow->setMaximumSize(QSize(400, 430));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        MainWindow->setFont(font);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::EditSelectAll));
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(1.000000000000000);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 270, 361, 110));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        botaoImportar = new QPushButton(verticalLayoutWidget);
        botaoImportar->setObjectName("botaoImportar");

        verticalLayout->addWidget(botaoImportar);

        botaoAdicionar = new QPushButton(verticalLayoutWidget);
        botaoAdicionar->setObjectName("botaoAdicionar");
        botaoAdicionar->setEnabled(false);

        verticalLayout->addWidget(botaoAdicionar);

        botaoRemover = new QPushButton(verticalLayoutWidget);
        botaoRemover->setObjectName("botaoRemover");
        botaoRemover->setEnabled(false);

        verticalLayout->addWidget(botaoRemover);

        botaoGerarRelatorio = new QPushButton(verticalLayoutWidget);
        botaoGerarRelatorio->setObjectName("botaoGerarRelatorio");
        botaoGerarRelatorio->setEnabled(false);

        verticalLayout->addWidget(botaoGerarRelatorio);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(20, 20, 361, 241));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Sistema de Controle de Estoque", nullptr));
        botaoImportar->setText(QCoreApplication::translate("MainWindow", "Importar arquivo", nullptr));
        botaoAdicionar->setText(QCoreApplication::translate("MainWindow", "Adicionar item", nullptr));
        botaoRemover->setText(QCoreApplication::translate("MainWindow", "Remover item", nullptr));
        botaoGerarRelatorio->setText(QCoreApplication::translate("MainWindow", "Gerar relat\303\263rio (.txt)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
