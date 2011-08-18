SOURCES += main.cpp\
        gallery.cpp

HEADERS += gallery.h \
    qsearchfield.h

!mac:SOURCES += qsearchfield.cpp
mac:SOURCES += qsearchfield_mac.mm
mac:LIBS += -framework Foundation -framework Appkit
