#ifndef ADICIONARWINDOW_H
#define ADICIONARWINDOW_H

#include "produto.h"

#include <QMainWindow>
#include <iostream>

namespace Ui {
class AdicionarWindow;
}

class AdicionarWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdicionarWindow(QWidget *parent = nullptr);

    ~AdicionarWindow();

    std::string endereco;
    void adicionarProduto(const Produto &produto);

signals:
    void atualizarLista(Produto &produto);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AdicionarWindow *ui;
};

#endif // ADICIONARWINDOW_H
