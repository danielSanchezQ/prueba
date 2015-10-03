#include "sampleapp.h"
#include "ui_sampleapp.h"
#include <QFileDialog>
#include <QImage>

SampleApp::SampleApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SampleApp)
{
    ui          ->  setupUi(this);
    scene       =   new QGraphicsScene();
    img_item    =   nullptr;
    img         =   new QPixmap();
    ui->image_view->setScene(scene);

    connect(ui->actionOpen, &QAction::triggered, [this](){this->loadImage();});
}

SampleApp::~SampleApp()
{
    delete ui;
}

QString SampleApp::get_filename_from_UI()
{
    return QFileDialog::getOpenFileName(this,
                                        tr("Open Image"),
                                        "",
                                        tr("Image Files(*.png *.jpg *.bmp)"));
}

void SampleApp::loadImage()
{
    img->load(get_filename_from_UI());
    if(img_item != nullptr) img_item->setPixmap(*img);
    else
    {
        img_item = scene->addPixmap(*img);
        scene->addItem(img_item);
    }
}
