#ifndef CALCMAINWINDOW_H
#define CALCMAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <vector>

QT_BEGIN_NAMESPACE

namespace Ui { class CalcMainWindow; }

QT_END_NAMESPACE

class CalcMainWindow : public QMainWindow{

    Q_OBJECT

public:

    CalcMainWindow(QWidget *parent = nullptr);
    ~CalcMainWindow();

private slots:

    void pushButton0Clicked();

    void pushButton1Clicked();

    void pushButton2Clicked();

    void pushButton3Clicked();

    void pushButton4Clicked();

    void pushButton5Clicked();

    void pushButton6Clicked();

    void pushButton7Clicked();

    void pushButton8Clicked();

    void pushButton9Clicked();

    void pushButtonDotClicked();

    void pushButtonClearClicked();

    void pushButtonPlusClicked();

    void pushButtonMinusClicked();

    void pushButtonMultiplyClicked();

    void pushButtonDevidedClicked();

    void pushButtonEqualClicked();

private:

    Ui::CalcMainWindow *ui;

    std::vector<char> signContainer;

    char operatorSign;

    double lValue;
    double rValue;
    double result;

    void resetLeftRightValue();

    void setValueForLabel(char value);

    void setLabelZero();

    void clearLabel();

    void clearSign();

    void clearZero();

    void standardOperationForNumberButton(char value);

    void standardOperationForSign(char sign);

protected:

    void keyPressEvent(QKeyEvent *keyEvent) override;

};

#endif // CALCMAINWINDOW_H
