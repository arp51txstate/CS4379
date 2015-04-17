#ifndef I1_H
#define I1_H

#include <QMainWindow>

namespace Ui {
class I1;
}

class I1 : public QWidget
{
    Q_OBJECT

public:
    explicit I1(QWidget *parent = 0);
    ~I1();
    void itIsChecked();

private:
    Ui::I1 *ui;
};

#endif // I1_H
