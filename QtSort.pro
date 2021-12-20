QT += charts
CONFIG     += qt

HEADERS += \
    QtSort.h

SOURCES += \
    QtSort.cpp \
    main.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/charts/scatterinteractions
INSTALLS += target
