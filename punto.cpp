#include "punto.h"
#include "ui_punto.h"

punto::punto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::punto)
{
    ui->setupUi(this); //connections of interface signals with the slots
    connect(ui->Inicio,SIGNAL(clicked()),this,SLOT(ejecutar()));
    connect(ui->Reiniciar,SIGNAL(clicked()),this,SLOT(reunadar()));
}

punto::~punto()
{
    delete ui;
}
double punto:: g(double d){ //function to evaluate
    return(5*exp(-d-1));
}
void punto:: ejecutar(){ //slot that will execute the method when you press start
    x=ui->Valorx1->value();//will gather the values of "x" that the user will enter
    ea=ui->Errora->value();//It will gather the accepted error entered by the user and save in the variable and
    while(ei>ea){    //a with cycle will be used to control the iterations, the method will stop when the error is minimal
        xr=g(x); //evaluate the function with "x" and save to "xr"
        ei=100*std::abs(xr-x)/xr;//will calculate the new error
        i++;//Sum one iteration
        x=xr; //"x" takes the value stored in "xr"
        if(i==100)//if this limit of interactions is reached, the method will be stopped
            break;
    }
ui->display->display(x); //displays the root found
ui->interacciones->display(i);//shows on the screen the interactions
ui->mosterror->display(ei);//Shows the minimum error found
}
void punto:: reunadar(){ //slot that will restart the method to enter a new value of "x" and "accepted error" deleting everything previously entered
    ui->Valorx1->setValue(0.0);//the value of "x", the "error accepted", the root found and displayed on the display, interactions and the displayed error are cleared
    ui->Errora->setValue(0.0);
    ui->display->display(0.0);
    ui->interacciones->display(0.0);
    ui->mosterror->display(0.0);
    x=0; xr=0; ea=0; i=0;//All variables goes to 0, for start over
    ei=100;//The initial error back to 100 percent, to start over the method
}
