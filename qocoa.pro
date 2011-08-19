SOURCES += main.cpp\
           gallery.cpp \

HEADERS += gallery.h \
           qocoa_mac.h \
           qsearchfield.h \
           qbutton.h \

!mac:SOURCES += qsearchfield.cpp qbutton.cpp
mac:SOURCES += qsearchfield_mac.mm qbutton_mac.mm
mac:LIBS += -framework Foundation -framework Appkit
