#ifndef WARN_H
#define WARN_H

#include <gtk/gtk.h>

#define msg(window, message, ...) \
{ \
  Widget *dialog = gtk_message_dialog_new (GTK_WINDOW(window), \
                                    GTK_DIALOG_DESTROY_WITH_PARENT,\
                                    GTK_MESSAGE_INFO, \
                                    GTK_BUTTONS_OK,\
                                    message, \
                                    ##__VA_ARGS__); \
   gtk_dialog_run (GTK_DIALOG (dialog)); \
   gtk_widget_destroy (dialog); \
}
#endif // WARN_H
