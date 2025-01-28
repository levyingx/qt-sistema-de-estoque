/********************************************************************************
** Form generated from reading UI file 'adicionarwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADICIONARWINDOW_H
#define UI_ADICIONARWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdicionarWindow
{
public:
    QWidget *centralwidget;
    QWidget *formQtd;
    QLabel *labelQtd;
    QSpinBox *spinBoxQtd;
    QWidget *formNome;
    QLabel *labelNome;
    QSpinBox *lineEditID;
    QWidget *formCategoria;
    QLineEdit *lineEditCategoria;
    QLabel *labelCategoria;
    QWidget *formPreco;
    QLabel *labelPreco;
    QDoubleSpinBox *doubleSpinBox;
    QDialogButtonBox *buttonBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdicionarWindow)
    {
        if (AdicionarWindow->objectName().isEmpty())
            AdicionarWindow->setObjectName("AdicionarWindow");
        AdicionarWindow->resize(300, 250);
        AdicionarWindow->setMinimumSize(QSize(300, 250));
        AdicionarWindow->setMaximumSize(QSize(300, 250));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        AdicionarWindow->setFont(font);
        centralwidget = new QWidget(AdicionarWindow);
        centralwidget->setObjectName("centralwidget");
        formQtd = new QWidget(centralwidget);
        formQtd->setObjectName("formQtd");
        formQtd->setGeometry(QRect(10, 100, 281, 21));
        labelQtd = new QLabel(formQtd);
        labelQtd->setObjectName("labelQtd");
        labelQtd->setGeometry(QRect(0, 0, 81, 21));
        spinBoxQtd = new QSpinBox(formQtd);
        spinBoxQtd->setObjectName("spinBoxQtd");
        spinBoxQtd->setGeometry(QRect(80, 0, 201, 21));
        spinBoxQtd->setProperty("showGroupSeparator", QVariant(false));
        spinBoxQtd->setMinimum(1);
        spinBoxQtd->setMaximum(9999999);
        formNome = new QWidget(centralwidget);
        formNome->setObjectName("formNome");
        formNome->setGeometry(QRect(10, 40, 281, 21));
        labelNome = new QLabel(formNome);
        labelNome->setObjectName("labelNome");
        labelNome->setGeometry(QRect(0, 0, 81, 21));
        lineEditID = new QSpinBox(formNome);
        lineEditID->setObjectName("lineEditID");
        lineEditID->setGeometry(QRect(80, 0, 201, 21));
        lineEditID->setProperty("showGroupSeparator", QVariant(false));
        lineEditID->setMinimum(1);
        lineEditID->setMaximum(9999999);
        formCategoria = new QWidget(centralwidget);
        formCategoria->setObjectName("formCategoria");
        formCategoria->setGeometry(QRect(10, 10, 281, 21));
        lineEditCategoria = new QLineEdit(formCategoria);
        lineEditCategoria->setObjectName("lineEditCategoria");
        lineEditCategoria->setGeometry(QRect(80, 0, 201, 21));
        lineEditCategoria->setClearButtonEnabled(false);
        labelCategoria = new QLabel(formCategoria);
        labelCategoria->setObjectName("labelCategoria");
        labelCategoria->setGeometry(QRect(0, 0, 81, 21));
        labelCategoria->raise();
        lineEditCategoria->raise();
        formPreco = new QWidget(centralwidget);
        formPreco->setObjectName("formPreco");
        formPreco->setGeometry(QRect(10, 70, 281, 21));
        labelPreco = new QLabel(formPreco);
        labelPreco->setObjectName("labelPreco");
        labelPreco->setGeometry(QRect(0, 0, 81, 21));
        doubleSpinBox = new QDoubleSpinBox(formPreco);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setGeometry(QRect(80, 0, 201, 21));
        doubleSpinBox->setMaximum(9999.989999999999782);
        buttonBox = new QDialogButtonBox(centralwidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(130, 200, 166, 24));
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        AdicionarWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdicionarWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 300, 19));
        AdicionarWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdicionarWindow);
        statusbar->setObjectName("statusbar");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setWeight(QFont::Thin);
        statusbar->setFont(font1);
        statusbar->setSizeGripEnabled(false);
        AdicionarWindow->setStatusBar(statusbar);

        retranslateUi(AdicionarWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AdicionarWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(AdicionarWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdicionarWindow)
    {
        AdicionarWindow->setWindowTitle(QCoreApplication::translate("AdicionarWindow", "Adicionar item", nullptr));
        labelQtd->setText(QCoreApplication::translate("AdicionarWindow", "Quantidade:", nullptr));
        labelNome->setText(QCoreApplication::translate("AdicionarWindow", "ID:", nullptr));
        lineEditCategoria->setText(QString());
        lineEditCategoria->setPlaceholderText(QString());
        labelCategoria->setText(QCoreApplication::translate("AdicionarWindow", "Categoria:", nullptr));
        labelPreco->setText(QCoreApplication::translate("AdicionarWindow", "Pre\303\247o:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdicionarWindow: public Ui_AdicionarWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADICIONARWINDOW_H
