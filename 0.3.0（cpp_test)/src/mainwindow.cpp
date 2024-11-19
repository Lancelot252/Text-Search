#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "textsearch.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::onSearchButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSearchButtonClicked()
{
    QString keyword = ui->keywordLineEdit->text();
    if (keyword.isEmpty()) {
        return;
    }

    TextSearch textSearch;
    QString text = textSearch.loadTextFromFile("text.txt");
    if (text.isEmpty()) {
        ui->resultTextEdit->setText("Failed to open text.txt");
        return;
    }

    vector<string> sentences = textSearch.splitIntoSentences(text.toStdString());
    unordered_map<string, unordered_set<string>> hashTable = textSearch.buildHashTable(sentences);
    unordered_set<string> results = textSearch.searchKeyword(hashTable, keyword.toStdString());

    QString resultText;
    for (const auto& sentence : results) {
        resultText += QString::fromStdString(sentence) + "\n";
    }

    if (resultText.isEmpty()) {
        resultText = "No sentences found containing the keyword: " + keyword;
    }

    ui->resultTextEdit->setText(resultText);
}