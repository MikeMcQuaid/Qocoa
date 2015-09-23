#ifndef GALLERY_H
#define GALLERY_H

#include <QWidget>

class QSearchField;

class Gallery : public QWidget
{
    Q_OBJECT

public:
    explicit Gallery(QWidget *parent = 0);
protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
private:
    QSearchField *searchField;
};

#endif // WIDGET_H
