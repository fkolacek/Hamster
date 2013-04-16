#include <QApplication>
#include <QTextCodec>
#include "prompt.h"

int main(int argc, char *argv[]){

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));

    QApplication app(argc, argv);
    app.setApplicationName("Hamster");
    app.setApplicationVersion("0.4");

    Prompt widget;
    widget.show();
    
    return app.exec();
}
