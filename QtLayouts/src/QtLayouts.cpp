#include "QtLayouts.h"

QtLayouts::QtLayouts(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_QtLayouts)
{
    ui->setupUi(this);
}

QtLayouts::~QtLayouts()
{
    delete ui; 
}