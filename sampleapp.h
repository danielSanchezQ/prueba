#ifndef SAMPLEAPP_H
#define SAMPLEAPP_H

#include <QMainWindow>

namespace Ui {
class SampleApp;
}

class SampleApp : public QMainWindow
{
    Q_OBJECT

public:
    explicit SampleApp(QWidget *parent = 0);
    ~SampleApp();

private:
    Ui::SampleApp *ui;
};

#endif // SAMPLEAPP_H
