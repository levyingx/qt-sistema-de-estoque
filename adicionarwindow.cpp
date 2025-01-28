#include "adicionarwindow.h"
#include "ui_adicionarwindow.h"
#include "mainwindow.h"
#include "produto.h"

#include <QListWidgetItem>
#include <QLabel>
#include <QHBoxLayout>

#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

AdicionarWindow::AdicionarWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdicionarWindow)
{
    ui->setupUi(this);
}

AdicionarWindow::~AdicionarWindow()
{
    delete ui;
}

void AdicionarWindow::adicionarProduto(const Produto &produto) {
    ifstream arquivoEntrada(this->endereco);
    ofstream arquivoTemporario("temp.txt");

    if (!arquivoEntrada.is_open() || !arquivoTemporario.is_open()) {
        cerr << "Erro ao abrir os arquivos." << endl;
        return;
    }

    string linha;
    bool produtoEncontrado = false;

    while (getline(arquivoEntrada, linha)) {
        stringstream ss(linha);
        string campo;
        int idProduto;
        string tipoProduto;
        int quantidadeProduto;
        double valorProduto;

        getline(ss, campo, ',');
        idProduto = stoi(campo);
        getline(ss, tipoProduto, ',');
        getline(ss, campo, ',');
        quantidadeProduto = stoi(campo);
        getline(ss, campo, ',');
        valorProduto = stod(campo);

        if (idProduto == produto.id) {
            quantidadeProduto += produto.quantidade;
            arquivoTemporario << idProduto << "," << tipoProduto << "," << quantidadeProduto << "," << valorProduto << endl;
            produtoEncontrado = true;
        } else {
            arquivoTemporario << linha << endl;
        }
    }

    if (!produtoEncontrado) {
        arquivoTemporario << produto.toString() << endl;
    }

    arquivoEntrada.close();
    arquivoTemporario.close();

    remove(this->endereco.c_str());
    rename("temp.txt", this->endereco.c_str());

    if (produtoEncontrado) {
        cout << "Produto com ID " << produto.id << " atualizado com sucesso!" << endl;
    } else {
        cout << "Novo produto com ID " << produto.id << " adicionado com sucesso!" << endl;
    }
}

void AdicionarWindow::on_buttonBox_accepted()
{
    QString inputTipo = ui->lineEditCategoria->text();
    int inputID = ui->lineEditID->value();
    int inputValor = ui->doubleSpinBox->value();
    int inputQuantidade = ui->spinBoxQtd->value();

    auto produto = new Produto(inputID, inputTipo.toStdString(), inputQuantidade, inputValor);

    adicionarProduto(*produto);

    emit atualizarLista(*produto);

    this->close();
}
