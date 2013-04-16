#include "prompt.h"

Prompt::Prompt(QWidget *parent) : QWidget(parent){
    //Setup window
    this->setFixedSize(400, 35);
    this->move(50, 50);
    this->setWindowFlags(Qt::Widget | Qt::CustomizeWindowHint);
    this->setWindowIcon(QIcon(":/gfx/hamster.png"));

    //Create global keyboard hook
    this->khook = new QxtGlobalShortcut(QKeySequence("Alt+M"), this);
    connect(this->khook, SIGNAL(activated()), this, SLOT(invokeControl()));

    //Create actions
    this->actionSettings = new QAction("Settings", this);
    this->actionAbout = new QAction("About", this);
    this->actionQuit = new QAction("Quit", this);

    connect(this->actionSettings, SIGNAL(triggered()), this, SLOT(showSettings));
    connect(this->actionAbout, SIGNAL(triggered()), this, SLOT(showAbout()));
    connect(this->actionQuit, SIGNAL(triggered()), this, SLOT(close()));

    //Create menu
    this->trayIconMenu = new QMenu(this);
    this->trayIconMenu->addAction(this->actionSettings);
    this->trayIconMenu->addAction(this->actionAbout);
    this->trayIconMenu->addSeparator();
    this->trayIconMenu->addAction(this->actionQuit);

    //Create icon in systray
    if(QSystemTrayIcon::isSystemTrayAvailable()){
        this->trayIcon = new QSystemTrayIcon(QIcon(":/gfx/mhamster.png"), this);
        this->trayIcon->setContextMenu(this->trayIconMenu);
        this->trayIcon->show();
    }

    //Create user input
    this->userInput = new QLineEdit(this);
    this->userInput->setGeometry(5, 5, 355, 25);
    this->userInput->setFocus();

    //Create user settings
    this->userSettings = new ImgButton(this);
    this->userSettings->setPixmap(QPixmap(":/gfx/mhamster.png", 0, Qt::AutoColor));
    this->userSettings->setGeometry(365, 5, 25, 25);
    connect(this->userSettings, SIGNAL(clicked(QPoint)), this, SLOT(invokeMenu(QPoint)));
}

Prompt::~Prompt(){
    delete this->userSettings;
    delete this->userInput;
    delete this->trayIcon;
    delete this->trayIconMenu;
    delete this->actionSettings;
    delete this->actionAbout;
    delete this->actionQuit;
    delete this->khook;
}

void Prompt::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Escape && this->isVisible()){
        this->setVisible(false);
    }

    QWidget::keyPressEvent(event);
}

void Prompt::moveEvent(QMoveEvent *event){

    QPoint pos = event->pos();

    QWidget::moveEvent(event);
}

void Prompt::invokeControl(){
    this->userInput->clear();

    this->setVisible(true);
    this->raise();
    this->activateWindow();
}

void Prompt::invokeMenu(QPoint pos){
    this->trayIconMenu->popup(pos);
}

void Prompt::showSettings(){

}

void Prompt::showAbout(){
    QMessageBox::about(this, "Hamster", "Hamster v. 0.8");
}
