#include "gallery.h"

#include <QVBoxLayout>

#include "qsearchfield.h"

Gallery::Gallery(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QSearchField(this));
}
