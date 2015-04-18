#ifndef I2_H
#define I2_H

#include <QWidget>
#include <QMessageBox>
#include <QMainWindow>
class QAction;
class QListWidget;
class QMenu;
class QTextEdit;
class QToolbar;

namespace Ui {
class I2;
}

class I2 : public QWidget
{
    Q_OBJECT

public:
    explicit I2(QWidget *parent = 0);
    ~I2();
    void itIsChecked();

private slots:
     void document();
     void save();
     void open();
     void help();
     void addText(const QString &text);

private:
    Ui::I2 *ui;
    void createActions();
         void createMenus();
         void createToolBars();
         void createStatusBar();
         void createDockWindows();

         QTextEdit *textEdit;
         QListWidget *text;

         QMenu *fileMenu;
         QMenu *editMenu;
         QMenu *viewMenu;
         QMenu *helpMenu;
         QToolbar *fileToolBar;
         QAction *documentAct;
         QAction *saveAct;
         QAction *openAct;
         QAction *helpAct;
         QAction *quitAct;
};

#endif // I2_H
