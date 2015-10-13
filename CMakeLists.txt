project(Qocoa)
cmake_minimum_required(VERSION 2.8)

option(NON_MAC_WIDGETS "Force non-Mac widgets on OS X (useful for testing)" OFF)

find_package(Qt4 COMPONENTS QtMain QtCore QtGui REQUIRED)
include(UseQt4)

set(SOURCES
    main.cpp
    gallery.cpp
)

set(HEADERS
    gallery.h
    qsearchfield.h
    qbutton.h
    qprogressindicatorspinning.h
)

qt4_wrap_cpp(MOC_SOURCES ${HEADERS})

if(APPLE AND NOT ${NON_MAC_WIDGETS})
    list(APPEND SOURCES
        qsearchfield_mac.mm
        qbutton_mac.mm
        qprogressindicatorspinning_mac.mm
    )
else()
  message(here)
    list(APPEND SOURCES
        qsearchfield_nonmac.cpp
        qbutton_nonmac.cpp
        qprogressindicatorspinning_nonmac.cpp
    )
    set(RESOURCES
        qsearchfield_nonmac.qrc
        qprogressindicatorspinning_nonmac.qrc
    )
    qt4_add_resources(RESOURCES_SOURCES ${RESOURCES})
endif()

add_executable(Qocoa
    WIN32 MACOSX_BUNDLE
    ${SOURCES} ${MOC_SOURCES} ${RESOURCES_SOURCES}
)
target_link_libraries(Qocoa ${QT_LIBRARIES})

if(APPLE AND NOT ${NON_MAC_WIDGETS})
    set_target_properties(Qocoa PROPERTIES LINK_FLAGS "-framework Foundation -framework AppKit")
    set_target_properties(Qocoa PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist.in)
endif()
