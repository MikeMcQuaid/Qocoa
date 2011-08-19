#ifndef QBUTTON_H
#define QBUTTON_H

#include <QWidget>

class QButtonPrivate;
class QButton : public QWidget
{
    Q_OBJECT
public:
    // Matches NSBezelStyle
    enum BezelStyle {
       Rounded           = 1,
       RegularSquare     = 2,
       Disclosure        = 5,
       ShadowlessSquare  = 6,
       Circular          = 7,
       TexturedSquare    = 8,
       HelpButton        = 9,
       SmallSquare       = 10,
       TexturedRounded   = 11,
       RoundRect         = 12,
       Recessed          = 13,
       RoundedDisclosure = 14,
       Inline            = 15
    };

    explicit QButton(QWidget *parent, BezelStyle bezelStyle = Rounded);

public slots:
    void setText(const QString &text);

signals:
    void clicked();

private:
    friend class QButtonPrivate;
    QButtonPrivate *pimpl;
};
#endif // QBUTTON_H
