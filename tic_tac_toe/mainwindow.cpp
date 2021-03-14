#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->buttonsList = this->findChildren<QPushButton *>();
    ui->current->setText(this->symbol + " turn!");
    ui->current->setAlignment(Qt::AlignCenter);
    setGrid();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setGrid(){
    int ctr = -1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            grid[i][j] = ctr;
            --ctr;
        }
    }
}

void MainWindow::changeSimbol(){
    this->symbol == "X" ? symbol = "0" : symbol = "X";
    ui->current->setText(this->symbol + " turn!");
}

void MainWindow::clicked(QPushButton* btn, int x, int y){
    btn->setText(this->symbol);
    this->symbol == "X" ? this->grid[x][y] = 0 : this->grid[x][y] = 1;
    if(gameOver()){
        QMessageBox::information(this, "Result", "You won the game!");
        for (int i = 0; i < buttonsList.count() - 1; i++){
             buttonsList.at(i)->setEnabled(false);
        }
        ui->current->setText(this->symbol + " is the winner!");
    }
    else {
        changeSimbol();
        btn->setEnabled(false);
        for (int i = 0; i < buttonsList.count() - 1; i++){
           if(buttonsList.at(i)->isEnabled()){
               return;
           }
        }
        QMessageBox::information(this, "Result", "Draw!");
        ui->current->setText("Draw!");
    }
}

bool MainWindow::gameOver(){
    if(grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]){
        return true;
    }
    if(grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]){
        return true;
    }
    if(grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]){
        return true;
    }
    if(grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0]){
        return true;
    }
    if(grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]){
        return true;
    }
    if(grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2]){
        return true;
    }
    if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){
        return true;
    }
    if(grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2]){
        return true;
    }
    return false;
}

void MainWindow::on_buttonReset_clicked(){
    for (int i = 0; i < buttonsList.count() - 1; i++){
         buttonsList.at(i)->setEnabled(true);
         buttonsList.at(i)->setText("");
    }
    this->symbol = "X";
    ui->current->setText(this->symbol + " turn!");
    setGrid();
}

void MainWindow::on_button1_clicked(){
    clicked(ui->button1, 0, 0);
}

void MainWindow::on_button2_clicked(){
    clicked(ui->button2, 0, 1);
}

void MainWindow::on_button3_clicked(){
    clicked(ui->button3, 0, 2);
}

void MainWindow::on_button4_clicked(){
    clicked(ui->button4, 1, 0);
}

void MainWindow::on_button5_clicked(){
   clicked(ui->button5, 1, 1);
}

void MainWindow::on_button6_clicked(){
   clicked(ui->button6, 1, 2);
}

void MainWindow::on_button7_clicked(){
    clicked(ui->button7, 2, 0);
}

void MainWindow::on_button8_clicked(){
   clicked(ui->button8, 2, 1);
}

void MainWindow::on_button9_clicked(){
   clicked(ui->button9, 2, 2);
}
