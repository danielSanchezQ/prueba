#include "sampleapp.h"
#include "ui_sampleapp.h"

SampleApp::SampleApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SampleApp)
{
    ui->setupUi(this);
}

SampleApp::~SampleApp()
{
    delete ui;
}
