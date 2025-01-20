#include "helloWorld.h"

helloWorld::helloWorld(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_helloWorld)
{
    ui->setupUi(this);
}

helloWorld::~helloWorld()
{
    delete ui; 
}