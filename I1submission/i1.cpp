#include "i1.h"
#include "ui_i1.h"
#include <QApplication>
#include <QFont>
#include <QLCDNumber>
#include <QComboBox>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QString>
#include <QLineEdit>
#include <QSlider>
#include <QDial>
#include <QPushButton>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QCheckBox>

I1::I1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::I1)
{

    //create widget labels
    QLabel *visual = new QLabel("Visualization Methods:");
    QLabel *size = new QLabel("\nImage Size\n50%-150%:");
    QLabel *brightness = new QLabel("Image Brightness\n0-255:");
    QLabel *color = new QLabel("Color Representation:");
    QLabel *orientation = new QLabel("Image Orientation:");
    QComboBox *visualChoice = new QComboBox();

    //implement visual
    visualChoice->addItem(" ");
    visualChoice->addItem("A");
    visualChoice->addItem("B");
    visualChoice->addItem("C");
    visualChoice->addItem("D");
    visualChoice->addItem("E");

    //implement size slider
    QSlider *Slider = new QSlider(Qt::Horizontal);
    Slider->setRange(50,150);
    Slider->setValue(50);

    //implement brightness dial
    QDial *dial = new QDial();
    dial->setNotchesVisible(true);
    dial->setRange(0,255);
    dial->setValue(0);

    //implement color
    QCheckBox *colorChoiceR = new QCheckBox("R");
    QCheckBox *colorChoiceS = new QCheckBox("S");
    QCheckBox *colorChoiceT = new QCheckBox("T");
    QCheckBox *colorChoiceU = new QCheckBox("U");

    //implement Orientation
    QRadioButton *Portrait = new QRadioButton("Portrait");
    QRadioButton *Landscape = new QRadioButton("Landscape");

    //set initial value of visual to an empty selection
    QLineEdit *lineEdit = new QLineEdit();
    lineEdit->setReadOnly(true);
    lineEdit->setText(" ");

    //set initial value size to minimal amount
    QLCDNumber *sizeDisplay = new QLCDNumber(3);
    sizeDisplay->display(50);

    //set brightness value to minimal amount which is 0
    QLCDNumber *brightnessDisplay = new QLCDNumber(3);
    brightnessDisplay->display(0);

    //exit button
    QPushButton *exit = new QPushButton("Exit");

    //connect widgets by signal and slots
    connect(visualChoice,SIGNAL(currentIndexChanged(QString)), lineEdit, SLOT(setText(QString)));
    connect(Slider,SIGNAL(valueChanged(int)), sizeDisplay, SLOT(display(int)));
    connect(dial,SIGNAL(valueChanged(int)), brightnessDisplay, SLOT(display(int)));
    connect(exit,SIGNAL(clicked()), qApp, SLOT(quit()));

    //set layout
    QHBoxLayout *hlayoutColor = new QHBoxLayout;
    QHBoxLayout *hlayoutOrientation = new QHBoxLayout;

    QGridLayout *glayout = new QGridLayout;

    glayout->addWidget(visual,1,1,1,1,0);
    glayout->addWidget(visualChoice,1,2,1,1,0);
    glayout->addWidget(lineEdit,1,3,1,1,0);
    glayout->addWidget(size,2,1,1,1,0);
    glayout->addWidget(Slider,2,2,1,1,0);
    glayout->addWidget(sizeDisplay,2,3,1,1,0);
    glayout->addWidget(brightness,3,1,1,1,0);
    glayout->addWidget(dial,3,2,1,1,0);
    glayout->addWidget(brightnessDisplay,3,3,1,1,0);
    glayout->addWidget(color,4,1,1,1,0);
    glayout->addLayout(hlayoutColor,4,2,1,1,0);
    hlayoutColor->addWidget(colorChoiceR);
    hlayoutColor->addWidget(colorChoiceS);
    hlayoutColor->addWidget(colorChoiceT);
    hlayoutColor->addWidget(colorChoiceU);
    glayout->addWidget(orientation,5,1,1,1,0);
    glayout->addLayout(hlayoutOrientation,5,2,1,1,0);
    hlayoutOrientation->addWidget(Portrait);
    hlayoutOrientation->addWidget(Landscape);
    glayout->addWidget(exit,6,2,1,1,0);
    setLayout(glayout);
}

I1::~I1()
{
    delete ui;
}
