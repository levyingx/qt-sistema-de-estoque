#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adicionarwindow.h"
#include "produto.h"

#include <QListWidgetItem>
#include <QLabel>
#include <QFileDialog>
#include <QHBoxLayout>

#include <fstream>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete adicionarWindow;
}

void novoItem(QListWidget *listWidget, Produto &produto) {
    QWidget *container = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout(container);

    QLabel *tipoLabel = new QLabel(QString::fromStdString(produto.tipo));
    tipoLabel->setAlignment(Qt::AlignLeft);

    QFont font = tipoLabel->font();
    font.setWeight(QFont::Bold);
    tipoLabel->setFont(font);

    QLabel *idLabel = new QLabel(QString::number(produto.id));
    idLabel->setObjectName("idLabel");
    idLabel->setAlignment(Qt::AlignLeft);

    QLabel *valorLabel = new QLabel("R$" + QString::number(produto.valor, 'f', 2));
    valorLabel->setAlignment(Qt::AlignRight);

    QLabel *qtdLabel = new QLabel(QString::number(produto.quantidade) + " und.");
    qtdLabel->setAlignment(Qt::AlignRight);

    layout->addWidget(tipoLabel);
    layout->addWidget(idLabel);
    layout->addWidget(valorLabel);
    layout->addWidget(qtdLabel);

    layout->setContentsMargins(5, 5, 5, 5);
    container->setLayout(layout);

    QListWidgetItem *item = new QListWidgetItem(listWidget);
    item->setSizeHint(container->sizeHint());
    listWidget->setItemWidget(item, container);
}

void MainWindow::adicionar(Produto &produto)
{
    novoItem(ui->listWidget, produto);
}

void MainWindow::removerProduto(int id) {
    ifstream arquivoEntrada(this->endereco);
    ofstream arquivoTemporario("temp.txt");
    ofstream arquivoVendidosOut("arquivoVendidos.txt", ios::app);

    if (!arquivoEntrada.is_open() || !arquivoTemporario.is_open() || !arquivoVendidosOut.is_open()) {
        cerr << "Erro ao abrir os arquivos." << endl;
        return;
    }

    string linha;
    bool produtoEncontrado = false;

    while (getline(arquivoEntrada, linha)) {
        stringstream ss(linha);
        string campo;
        int idProduto;

        getline(ss, campo, ',');
        idProduto = stoi(campo);

        if (idProduto == id) {
            produtoEncontrado = true;
            arquivoVendidosOut << linha << endl;
        } else {
            arquivoTemporario << linha << endl;
        }
    }

    arquivoEntrada.close();
    arquivoTemporario.close();
    arquivoVendidosOut.close();

    if (produtoEncontrado) {
        remove(this->endereco.c_str());
        rename("temp.txt", this->endereco.c_str());
        cout << "Produto com ID " << id << " removido e registrado como vendido!" << endl;
    } else {
        remove("temp.txt");
        cout << "Produto com ID " << id << " não encontrado." << endl;
    }
}

void MainWindow::gerarRelatorio() {
    ifstream arquivoEntradaAdicionados(this->endereco);
    ifstream arquivoEntradaVendidos("arquivoVendidos.txt");

    if (!arquivoEntradaAdicionados.is_open() || !arquivoEntradaVendidos.is_open()) {
        cerr << "Erro ao abrir os arquivos para gerar o relatório." << endl;
        return;
    }

    cout << "\n===== RELATÓRIO DE PRODUTOS =====\n";

    cout << "\nProdutos Adicionados:\n";
    cout << "ID | Tipo | Quantidade | Valor\n";
    cout << "----------------------------------\n";
    string linha;
    while (getline(arquivoEntradaAdicionados, linha)) {
        cout << linha << endl;
    }

    cout << "\nProdutos Vendidos/Removidos:\n";
    cout << "ID | Tipo | Quantidade | Valor\n";
    cout << "----------------------------------\n";
    while (getline(arquivoEntradaVendidos, linha)) {
        cout << linha << endl;
    }

    arquivoEntradaAdicionados.close();
    arquivoEntradaVendidos.close();

    cout << "==================================\n";
}

void MainWindow::on_botaoImportar_clicked()
{
    using namespace std;

    ui->listWidget->clear();

    QString diretorio = QFileDialog::getOpenFileName(ui->centralwidget, tr("Abrir arquivo"),"/home", tr("Text files (*.txt)"));
    this->endereco = diretorio.toStdString();

    ifstream arquivoEntrada(endereco);

    if (!arquivoEntrada.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << endereco << endl;
        ui->statusbar->showMessage("Erro ao abrir o arquivo: " + diretorio, 2000);
        return;
    }

    string linha;

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

        Produto produto(idProduto, tipoProduto, quantidadeProduto, valorProduto);
        adicionar(produto);
    }

    arquivoEntrada.close();

    ui->botaoAdicionar->setEnabled(true);
    ui->botaoRemover->setEnabled(true);
    ui->botaoGerarRelatorio->setEnabled(true);


    ui->statusbar->showMessage("Arquivo importado de: " + diretorio, 2000);
}

void MainWindow::on_botaoAdicionar_clicked()
{
    adicionarWindow = new AdicionarWindow(this);
    adicionarWindow->endereco = this->endereco;
    connect(adicionarWindow, &AdicionarWindow::atualizarLista, this, &MainWindow::adicionar);
    adicionarWindow->show();
}

void MainWindow::on_botaoRemover_clicked()
{
    QListWidgetItem *itemAtual = ui->listWidget->currentItem();

    if (itemAtual) {
        QWidget *widget = ui->listWidget->itemWidget(itemAtual);
        QLabel *idLabel = widget->findChild<QLabel *>("idLabel");

        if (idLabel) {
            int idProduto = idLabel->text().toInt();
            cout << "ID Passado: " << idProduto << endl;
            removerProduto(idProduto);
        }

        delete ui->listWidget->takeItem(ui->listWidget->row(itemAtual));
    }
}

void MainWindow::on_botaoGerarRelatorio_clicked()
{
    gerarRelatorio();
}
