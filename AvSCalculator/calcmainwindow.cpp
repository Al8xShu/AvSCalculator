#include <QDebug>
#include "calcmainwindow.h"
#include "./ui_calcmainwindow.h"

using namespace std;

CalcMainWindow::CalcMainWindow(QWidget *parent):QMainWindow(parent),
    ui(new Ui::CalcMainWindow){

    signContainer = {'+', '-', '*', '/'};

    operatorSign = '0';

    resetLeftRightValue();

    result = 0;

    ui->setupUi(this);

    setLabelZero();

    connect(ui->pushButton0, SIGNAL(clicked()), this, SLOT(pushButton0Clicked()));

    connect(ui->pushButton1, SIGNAL(clicked()), this, SLOT(pushButton1Clicked()));

    connect(ui->pushButton2, SIGNAL(clicked()), this, SLOT(pushButton2Clicked()));

    connect(ui->pushButton3, SIGNAL(clicked()), this, SLOT(pushButton3Clicked()));

    connect(ui->pushButton4, SIGNAL(clicked()), this, SLOT(pushButton4Clicked()));

    connect(ui->pushButton5, SIGNAL(clicked()), this, SLOT(pushButton5Clicked()));

    connect(ui->pushButton6, SIGNAL(clicked()), this, SLOT(pushButton6Clicked()));

    connect(ui->pushButton7, SIGNAL(clicked()), this, SLOT(pushButton7Clicked()));

    connect(ui->pushButton8, SIGNAL(clicked()), this, SLOT(pushButton8Clicked()));

    connect(ui->pushButton9, SIGNAL(clicked()), this, SLOT(pushButton9Clicked()));

    connect(ui->pushButtonDot, SIGNAL(clicked()), this, SLOT(pushButtonDotClicked()));

    connect(ui->pushButtonClear, SIGNAL(clicked()), this, SLOT(pushButtonClearClicked()));

    connect(ui->pushButtonPlus, SIGNAL(clicked()), this, SLOT(pushButtonPlusClicked()));

    connect(ui->pushButtonMinus, SIGNAL(clicked()), this, SLOT(pushButtonMinusClicked()));

    connect(ui->pushButtonMultiply, SIGNAL(clicked()), this, SLOT(pushButtonMultiplyClicked()));

    connect(ui->pushButtonDevided, SIGNAL(clicked()), this, SLOT(pushButtonDevidedClicked()));

    connect(ui->pushButtonEqual, SIGNAL(clicked()), this, SLOT(pushButtonEqualClicked()));

}

CalcMainWindow::~CalcMainWindow(){ delete ui; }

void CalcMainWindow::pushButton0Clicked(){ standardOperationForNumberButton('0'); }

void CalcMainWindow::pushButton1Clicked(){ standardOperationForNumberButton('1'); }

void CalcMainWindow::pushButton2Clicked(){ standardOperationForNumberButton('2'); }

void CalcMainWindow::pushButton3Clicked(){ standardOperationForNumberButton('3'); }

void CalcMainWindow::pushButton4Clicked(){ standardOperationForNumberButton('4'); }

void CalcMainWindow::pushButton5Clicked(){ standardOperationForNumberButton('5'); }

void CalcMainWindow::pushButton6Clicked(){ standardOperationForNumberButton('6'); }

void CalcMainWindow::pushButton7Clicked(){ standardOperationForNumberButton('7'); }

void CalcMainWindow::pushButton8Clicked(){ standardOperationForNumberButton('8'); }

void CalcMainWindow::pushButton9Clicked(){ standardOperationForNumberButton('9'); }

void CalcMainWindow::pushButtonDotClicked(){ standardOperationForNumberButton('.'); };

void CalcMainWindow::pushButtonClearClicked(){

    resetLeftRightValue();
    clearLabel();
    setLabelZero();

}

void CalcMainWindow::pushButtonPlusClicked(){ standardOperationForSign('+'); }

void CalcMainWindow::pushButtonMinusClicked(){ standardOperationForSign('-'); }

void CalcMainWindow::pushButtonMultiplyClicked(){ standardOperationForSign('*'); }

void CalcMainWindow::pushButtonDevidedClicked(){ standardOperationForSign('/'); }

void CalcMainWindow::pushButtonEqualClicked(){

    rValue = ui->label->text().toDouble();

    clearLabel();

    switch(operatorSign){
    case '+':
        result = lValue + rValue;
        break;
    case '-':
        result = lValue - rValue;
        break;
    case '*':
        result = lValue * rValue;
        break;
    case '/':
        result = lValue / rValue;
        break;
    default:
        break;
    }

    ui->label->setText(QString::number(result));

    resetLeftRightValue();

}

void CalcMainWindow::resetLeftRightValue(){

    lValue = 0;
    rValue = 0;

}

void CalcMainWindow::setValueForLabel(char value){ ui->label->setText(ui->label->text() + value); }

void CalcMainWindow::setLabelZero(){ ui->label->setText("0"); };

void CalcMainWindow::clearLabel(){ ui->label->clear(); }

void CalcMainWindow::clearSign(){

    if(std::find(signContainer.begin(), signContainer.end(), ui->label->text()) != signContainer.end()){
        ui->label->clear();
    }

}

void CalcMainWindow::clearZero(){

    if(ui->label->text() == '0'){
        ui->label->clear();
    }

}

void CalcMainWindow::standardOperationForNumberButton(char value){

    if(value == '.'){
        clearSign();
        setValueForLabel(value);
    }else{
        clearZero();
        clearSign();
        setValueForLabel(value);
    }

}

void CalcMainWindow::standardOperationForSign(char sign){

    lValue = ui->label->text().toDouble();
    operatorSign = sign;
    clearLabel();
    setValueForLabel(sign);

}

void CalcMainWindow::keyPressEvent(QKeyEvent *keyEvent){

    switch (keyEvent->key()) {
    case Qt::Key_0:
        pushButton0Clicked();
        break;
    case Qt::Key_1:
        pushButton1Clicked();
        break;
    case Qt::Key_2:
        pushButton2Clicked();
        break;
    case Qt::Key_3:
        pushButton3Clicked();
        break;
    case Qt::Key_4:
        pushButton4Clicked();
        break;
    case Qt::Key_5:
        pushButton5Clicked();
        break;
    case Qt::Key_6:
        pushButton6Clicked();
        break;
    case Qt::Key_7:
        pushButton7Clicked();
        break;
    case Qt::Key_8:
        pushButton8Clicked();
        break;
    case Qt::Key_9:
        pushButton9Clicked();
        break;
    case '.':
        pushButtonDotClicked();
        break;
    case Qt::Key_Delete:
        pushButtonClearClicked();
        break;
    case Qt::Key_Plus:
        pushButtonPlusClicked();
        break;
    case Qt::Key_Minus:
        pushButtonMinusClicked();
        break;
    case '*':
        pushButtonMultiplyClicked();
        break;
    case Qt::Key_Slash:
        pushButtonDevidedClicked();
        break;
    case Qt::Key_Enter:
        pushButtonEqualClicked();
        break;
    default:
        break;
    }

}
