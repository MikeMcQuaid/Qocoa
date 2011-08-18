#include "qsearchfield.h"

#include <QMacCocoaViewContainer>
#include <QVBoxLayout>

#import "Foundation/NSAutoreleasePool.h"
#import "Foundation/NSNotification.h"
#import "AppKit/NSTextField.h"
#import "AppKit/NSSearchField.h"

NSString* fromQString(const QString &string)
{
    char* cString = string.toUtf8().data();
    return [[NSString alloc] initWithUTF8String:cString];
}

QString toQString(NSString *string)
{
    if (!string)
        return QString();
    return QString::fromUtf8([string UTF8String]);
}

class QSearchFieldPrivate
{
public:
    QSearchFieldPrivate(QSearchField *qSearchField, NSSearchField *nsSearchField)
        : qSearchField(qSearchField), nsSearchField(nsSearchField) {}

    void textDidChange(const QString &text)
    {
        emit qSearchField->textChanged(text);
    }
    QSearchField *qSearchField;
    NSSearchField *nsSearchField;
};

@interface QSearchFieldDelegate : NSObject<NSTextFieldDelegate>
{
@public
    QSearchFieldPrivate* pimpl;
}
-(void)controlTextDidChange:(NSNotification*)notification;
@end

@implementation QSearchFieldDelegate
-(void)controlTextDidChange:(NSNotification*)notification {
    pimpl->textDidChange(toQString([[notification object] stringValue]));
}
@end

QSearchField::QSearchField(QWidget *parent) : QWidget(parent)
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

    NSSearchField *search = [[NSSearchField alloc] init];
    pimpl = new QSearchFieldPrivate(this, search);
    [search sizeToFit];

    QSearchFieldDelegate *delegate = [[QSearchFieldDelegate alloc] init];
    delegate->pimpl = pimpl;
    [search setDelegate:delegate];

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->addWidget(new QMacCocoaViewContainer(search, this));

    setFixedHeight(20);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    [search release];

    [pool release];
}

void QSearchField::setText(const QString &text)
{
    [pimpl->nsSearchField setStringValue:fromQString(text)];
}
