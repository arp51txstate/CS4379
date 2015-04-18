#include "i2.h"
#include "ui_i2.h"
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
#include <QtGui>
#include <QMessageBox>
#include <QFileDialog>
#include <QMenu>
#include <QDockWidget>
#include <QToolBar>
#include <QTextEdit>
#include <QWidget>
#include <QListWidget>
#include <QMainWindow>
#include <QMenuBar>

//Help from QT project Dock Widget example and I1.


I2::I2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::I2)
{
    textEdit = new QTextEdit;
    setCentralWidget(textEdit);
    createActions();
    createMenus();
    createToolBars();
    createStatusBar();
    createDockWindows();
    setWindowTitle(tr("Dock Widgets"));
    document();
}

void I2::document()
 {
     textEdit->clear();

     QTextCursor cursor(textEdit->textCursor());
     cursor.movePosition(QTextCursor::Start);
     QTextFrame *topFrame = cursor.currentFrame();
     QTextFrameFormat topFrameFormat = topFrame->frameFormat();
     topFrameFormat.setPadding(16);
     topFrame->setFrameFormat(topFrameFormat);

     QTextCharFormat textFormat;
     QTextCharFormat boldFormat;
     boldFormat.setFontWeight(QFont::Bold);
     QTextCharFormat italicFormat;
     italicFormat.setFontItalic(true);

     QTextTableFormat tableFormat;
     tableFormat.setBorder(1);
     tableFormat.setCellPadding(16);
     tableFormat.setAlignment(Qt::AlignRight);
     cursor.insertTable(1, 1, tableFormat);
     cursor.insertText("Anthony Prejean", boldFormat);
     cursor.insertBlock();
     cursor.insertText("Assignment I2", textFormat);
     cursor.insertBlock();
     cursor.insertText("CS 4379B");
     cursor.insertBlock();
     cursor.insertText("Due: March 5th, 2015");
     cursor.setPosition(topFrame->lastPosition());
}

void I2::open()
 {
     QString fileName = QFileDialog::getOpenFileName(this,
                         tr("Choose a file name"), ".",
                         tr("HTML (*.html *.htm)"));
     if (fileName.isEmpty())
         return;
     QFile file(fileName);
     if (!file.open(QFile::WriteOnly | QFile::Text)) {
         QMessageBox::warning(this, tr("Dock Widgets"),
                              tr("Cannot write file %1:\n%2.")
                              .arg(fileName)
                              .arg(file.errorString()));
         return;
     }

     QTextStream out(&file);
     QApplication::setOverrideCursor(Qt::WaitCursor);
     out << textEdit->toHtml();
     QApplication::restoreOverrideCursor();

 }

void I2::save()
 {
     QString fileName = QFileDialog::getSaveFileName(this,
                         tr("Choose a file name"), ".",
                         tr("HTML (*.html *.htm)"));
     if (fileName.isEmpty())
         return;
     QFile file(fileName);
     if (!file.open(QFile::WriteOnly | QFile::Text)) {
         QMessageBox::warning(this, tr("Dock Widgets"),
                              tr("Cannot write file %1:\n%2.")
                              .arg(fileName)
                              .arg(file.errorString()));
         return;
     }

     QTextStream out(&file);
     QApplication::setOverrideCursor(Qt::WaitCursor);
     out << textEdit->toHtml();
     QApplication::restoreOverrideCursor();

 }

void I2::addText(const QString &text)
 {
     if (text.isEmpty())
         return;
     QTextDocument *document = textEdit->document();
     QTextCursor cursor = document->find(tr("end of text..."));
     if (cursor.isNull())
         return;
     cursor.beginEditBlock();
     cursor.movePosition(QTextCursor::PreviousBlock, QTextCursor::MoveAnchor, 2);
     cursor.insertBlock();
     cursor.insertText(text);
     cursor.insertBlock();
     cursor.endEditBlock();

 }

void I2::help()
 {
    QMessageBox::help(this, tr("&Help page"));
 }

void I2::createActions()
 {
     documentAct = new QAction(QIcon(":/images/new.png"), tr("&New document"),
                                this);
     documentAct->setShortcuts(QKeySequence::New);
     documentAct->setStatusTip(tr("Create a new document"));
     connect(documentAct, SIGNAL(triggered()), this, SLOT(document()));

     saveAct = new QAction(QIcon(":/images/save.png"), tr("&Save..."), this);
     saveAct->setShortcuts(QKeySequence::Save);
     saveAct->setStatusTip(tr("Save document"));
     connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

     quitAct = new QAction(tr("&Quit"), this);
          quitAct->setShortcuts(QKeySequence::Quit);
          quitAct->setStatusTip(tr("close document"));
          connect(quitAct, SIGNAL(triggered()), this, SLOT(close()));

          helpAct = new QAction(tr("&Help"), this);
          helpAct->setStatusTip(tr("Show the help box"));
          connect(helpAct, SIGNAL(triggered()), this, SLOT(help()));
     }

void I2::createMenus()
 {
     fileMenu->addMenu(tr("&File"));
     fileMenu->addAction(documentAct);
     fileMenu->addAction(saveAct);
     fileMenu->addSeparator();
     fileMenu->addAction(quitAct);
     viewMenu->addMenu(tr("&View"));
     menuBar()->addSeparator();
     helpMenu->addMenu(tr("&Help"));
     helpMenu->addAction(helpAct);
 }

void I2::createToolBars()
{
   fileToolBar->addAction(documentAct);
   fileToolBar->addAction(saveAct);
}

void I2::createDockWindows()
 {
    QDockWidget *dock = new QDockWidget(tr("widgets"), this);
    text = new QListWidget(dock);
    text->addItems(QStringList() << "Text Edit Area.");

    dock->setWidget(text);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    viewMenu->addAction(dock->toggleViewAction());

    connect(text, SIGNAL(currentTextChanged(QString)),
                 this, SLOT(addText(QString)));

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


I2::~I2()
{
    delete ui;
}
