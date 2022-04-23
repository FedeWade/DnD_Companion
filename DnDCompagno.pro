QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model/barbaro.cpp \
    Model/caratteristiche.cpp \
    Model/chierico.cpp \
    Model/guerriero.cpp \
    Model/incantatore.cpp \
    Model/listaabilita.cpp \
    Model/livello.cpp \
    Model/mago.cpp \
    Model/modello.cpp \
    Model/personaggio.cpp \
    Model/portafoglio.cpp \
    Model/slotincantesimi.cpp \
    Model/tirisalvezza.cpp \
    View/baseinfo.cpp \
    View/combatinfobox.cpp \
    View/descriptionbox.cpp \
    View/dnd.cpp \
    View/equipmentbox.cpp \
    View/exceptionmessage.cpp \
    View/healthbox.cpp \
    View/pgcreationdialog.cpp \
    View/pgselectionbox.cpp \
    View/savingthrow.cpp \
    View/savingthrowsbox.cpp \
    View/skill.cpp \
    View/skillsbox.cpp \
    View/slot.cpp \
    View/spellsbox.cpp \
    View/spellsslotsbox.cpp \
    View/stat.cpp \
    View/statsbox.cpp \
    main.cpp

HEADERS += \
    Model/barbaro.h \
    Model/caratteristiche.h \
    Model/chierico.h \
    Model/contenitore.h \
    Model/deeppointer.h \
    Model/guerriero.h \
    Model/incantatore.h \
    Model/listaabilita.h \
    Model/livello.h \
    Model/mago.h \
    Model/personaggio.h \
    Model/portafoglio.h \
    Model/slotincantesimi.h \
    Model/tirisalvezza.h \
    View/baseinfo.h \
    View/combatinfobox.h \
    View/descriptionbox.h \
    View/dnd.h \
    Model/modello.h \
    View/equipmentbox.h \
    View/exceptionmessage.h \
    View/healthbox.h \
    View/pgcreationdialog.h \
    View/pgselectionbox.h \
    View/savingthrow.h \
    View/savingthrowsbox.h \
    View/skill.h \
    View/skillsbox.h \
    View/slot.h \
    View/spellsbox.h \
    View/spellsslotsbox.h \
    View/stat.h \
    View/statsbox.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

DISTFILES +=
