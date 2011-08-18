#ifndef QSEARCHFIELD_H
#define QSEARCHFIELD_H

#include <QWidget>

class QSearchFieldPrivate;
class QSearchField : public QWidget
{
    Q_OBJECT
public:
    explicit QSearchField(QWidget *parent);

public slots:
    void setText(const QString &text);

signals:
    void textChanged(const QString &text);

private:
    friend class QSearchFieldPrivate;
    QSearchFieldPrivate *pimpl;
};

#endif // QSEARCHFIELD_H
