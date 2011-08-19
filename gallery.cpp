#include "gallery.h"

#include <QVBoxLayout>

#include "qsearchfield.h"
#include "qbutton.h"

Gallery::Gallery(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Qocoa Gallery");
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QSearchField(this));
    layout->addWidget(new QButton(this, QButton::Rounded));
    layout->addWidget(new QButton(this, QButton::RegularSquare));
    layout->addWidget(new QButton(this, QButton::Disclosure));
    layout->addWidget(new QButton(this, QButton::ShadowlessSquare));
    layout->addWidget(new QButton(this, QButton::Circular));
    layout->addWidget(new QButton(this, QButton::TexturedSquare));
    layout->addWidget(new QButton(this, QButton::HelpButton));
    layout->addWidget(new QButton(this, QButton::SmallSquare));
    layout->addWidget(new QButton(this, QButton::TexturedRounded));
    layout->addWidget(new QButton(this, QButton::RoundRect));
    layout->addWidget(new QButton(this, QButton::Recessed));
    layout->addWidget(new QButton(this, QButton::RoundedDisclosure));
    layout->addWidget(new QButton(this, QButton::Inline));
}
