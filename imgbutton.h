#ifndef IMGBUTTON_H
#define IMGBUTTON_H

#include <QLabel>
#include <QMouseEvent>

class ImgButton : public QLabel
{
    Q_OBJECT
public:
    explicit ImgButton(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent*);
signals:
    void clicked(QPoint);
    
};

#endif // IMGBUTTON_H
