#ifndef WARN_H
#define WARN_H

#include <gtk/gtk.h>

#define msg(message, ...) \
  dialog = gtk_message_dialog_new (main_application_window, \
                                    GTK_DIALOG_DESTROY_WITH_PARENT,\
                                    GTK_MESSAGE_ERROR, \
                                    GTK_BUTTONS_CLOSE,\
                                    "Error loading file '%s': %s", \
                                    #__VA_ARGS); \
   gtk_dialog_run (GTK_DIALOG (dialog)); \
   gtk_widget_destroy (dialog);
#endif // WARN_H
