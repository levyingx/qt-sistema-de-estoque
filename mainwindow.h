#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "adicionarwindow.h"
#include "ui_adicionarwindow.h"
#include "produto.h"

#include <QMainWindow>
#include <QListWidgetItem>

#include <iostream>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    string endereco;

public slots:
    void adicionar(Produto &produto);
    void removerProduto(int id);
    void gerarRelatorio();

private slots:
    void on_botaoImportar_clicked();
    void on_botaoAdicionar_clicked();
    void on_botaoRemover_clicked();
    void on_botaoGerarRelatorio_clicked();

private:
    Ui::MainWindow *ui;
    AdicionarWindow *adicionarWindow;
};

#endif // MAINWINDOW_H
