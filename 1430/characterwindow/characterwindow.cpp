#include "characterwindow.h"
#include "ui_characterwindow.h"

characterwindow::characterwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::characterwindow)
{
    ui->setupUi(this);
}

characterwindow::~characterwindow()
{
    delete ui;
}
