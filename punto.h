#ifndef PUNTO_H
#define PUNTO_H

#include <QMainWindow>

namespace Ui {
class punto;
}

class punto : public QMainWindow
{
    Q_OBJECT

public:
    explicit punto(QWidget *parent = 0);
    ~punto();
    double x;//stores the initial value provided by the user
    double xr;//stores the result of the evaluated function
    double ei=100;// Initial error, it starts from 100 percent
    double ea=0;//stores the accepted error entered by the user
    int i=0;//variable that stores the interactions

    double g(double d); //function to evaluate
public slots:
    void ejecutar(); //slot to start the method
    void reunadar();//slot to restart method


private:
    Ui::punto *ui;
};

#endif // PUNTO_H
