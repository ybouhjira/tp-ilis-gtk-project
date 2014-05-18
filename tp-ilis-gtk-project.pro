TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    macros/conteneurs.c \
    pages.c \
    callbacks.c \
    file.c \
    etudiant.c \
    macros/list.c

HEADERS += \
    macros/css.h \
    macros/macors.h \
    macros/fenetre.h \
    macros/bouton.h \
    macros/conteneurs.h \
    macros/case.h \
    macros/etiquette.h \
    pages.h \
    etudiant.h \
    callbacks.h \
    file.h \
    macros/list.h

INCLUDEPATH += /usr/include/gtk-3.0 \
/usr/include/glib-3.0 \
/usr/lib/i386-linux-gnu/glib-3.0/include/ \
/usr/include/cairo/ \
/usr/include/pango-1.0/ \
/usr/lib/i386-linux-gnu/gtk-3.0/include/ \
/usr/include/gdk-pixbuf-3.0/ \
/usr/include/atk-1.0/


unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += gtk+-3.0

QMAKE_CFLAGS += -Wno-unused-parameter -std=c99 -Wno-missing-field-initializers

