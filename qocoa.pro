SOURCES += main.cpp\
           gallery.cpp \

HEADERS += gallery.h \
           qocoa_mac.h \
           qsearchfield.h \
           qbutton.h \
           qprogressindicatorspinning.h \

!mac:SOURCES += qsearchfield_nonmac.cpp qbutton_nonmac.cpp qprogressindicatorspinning_nonmac.cpp
mac:SOURCES += qsearchfield_mac.mm qbutton_mac.mm qprogressindicatorspinning_mac.mm
mac:LIBS += -framework Foundation -framework Appkit
