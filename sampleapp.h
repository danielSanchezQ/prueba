#ifndef SAMPLEAPP_H
#define SAMPLEAPP_H

#include <QMainWindow>
#include <QString>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>


namespace Ui {
class SampleApp;
}

class SampleApp : public QMainWindow
{
    Q_OBJECT

public:
    explicit SampleApp(QWidget *parent = 0);
    ~SampleApp();
    void loadImage();

private:
    Ui::SampleApp           *ui;
    QGraphicsScene          *scene;
    QGraphicsPixmapItem     *img_item;
    QPixmap                 *img;

    QString                 get_filename_from_UI();
};

#endif // SAMPLEAPP_H
