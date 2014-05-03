TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    login_page.c

HEADERS += \
    macros/css.h \
    macros/macors.h \
    macros/fenetre.h \
    macros/grille.h \
    macros/bouton.h \
    macros/conteneurs.h \
    login_page.h

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
