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

    connect(ui->actionOpen, &QAction::triggered,    [this](){this->loadImage();});
    connect(ui->clear_b,    &QPushButton::clicked,  [this](){this->clear();});
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
void SampleApp::custom_setImage()
{
    if(img_item != nullptr) img_item->setPixmap(*img);
    else
    {
        img_item = scene->addPixmap(*img);
        scene->addItem(img_item);
    }
    ui->image_view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

void SampleApp::loadImage()
{
    img->load(get_filename_from_UI());
    custom_setImage();
}

void SampleApp::clear()
{
    img->load("");
    custom_setImage();
}
