#ifndef PROMPT_H
#define PROMPT_H

#include <QWidget>
#include <QLineEdit>
#include <QSystemTrayIcon>
#include <QKeyEvent>
#include <QMoveEvent>
#include <QMenu>
#include <QxtGlobalShortcut>
#include <QMessageBox>
#include "imgbutton.h"
#include <QDebug>

#include "iniparser.h"

class Prompt : public QWidget
{
    Q_OBJECT
    
public:
    explicit Prompt(QWidget *parent = 0);
    ~Prompt();

    void keyPressEvent(QKeyEvent *);
    void moveEvent(QMoveEvent *);
public slots:
    void invokeControl();
    void invokeMenu(QPoint);
    void showSettings();
    void showAbout();
    
private:
    QxtGlobalShortcut* khook;

    QLineEdit* userInput;
    ImgButton* userSettings;

    QMenu* trayIconMenu;
    QAction* actionSettings;
    QAction* actionAbout;
    QAction* actionQuit;

    QSystemTrayIcon* trayIcon;
};

#endif // PROMPT_H
