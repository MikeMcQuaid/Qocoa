#include "qsearchfield.h"

#include <QLineEdit>
#include <QVBoxLayout>

class QSearchFieldPrivate
{
public:
    QSearchFieldPrivate(QLineEdit *lineEdit) : lineEdit(lineEdit) {}
    QLineEdit *lineEdit;
};

QSearchField::QSearchField(QWidget *parent) : QWidget(parent)
{
    QLineEdit *lineEdit = new QLineEdit(this);
    connect(lineEdit, SIGNAL(textChanged(QString)),
            this, SIGNAL(textChanged(QString)));
    pimpl = new QSearchFieldPrivate(lineEdit);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->addWidget(lineEdit);
}

void QSearchField::setText(const QString &text)
{
    pimpl->lineEdit->setText(text);
}
