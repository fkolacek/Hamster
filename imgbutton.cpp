#include "imgbutton.h"

ImgButton::ImgButton(QWidget *parent) : QLabel(parent){

}

void ImgButton::mousePressEvent(QMouseEvent* event){
    emit clicked(event->globalPos());

    QLabel::mousePressEvent(event);
}
