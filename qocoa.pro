SOURCES += main.cpp\
           gallery.cpp \

HEADERS += gallery.h \
           qocoa_mac.h \
           qsearchfield.h \
           qbutton.h \
           qprogressindicatorspinning.h \

mac {
    OBJECTIVE_SOURCES += qsearchfield_mac.mm qbutton_mac.mm qprogressindicatorspinning_mac.mm
    LIBS += -framework Foundation -framework Appkit
} else {
    SOURCES += qsearchfield_nonmac.cpp qbutton_nonmac.cpp qprogressindicatorspinning_nonmac.cpp
}

contains(QT_CONFIG, embedded):debug {
        CXXFLAGS += -Wno-psabi
}
