#ifndef CASE_H
#define CASE_H

#include "macors.h"

#include <gtk/gtk.h>

Widget *case_creer(boolean motDePasse);

// Type de case
#define case_type(case, type) \
  gtk_entry_set_input_purpose(GTK_ENTRY(case) , type);

// Renomer les types

#define CASE_FORM  GTK_INPUT_PURPOSE_FREE_FORM
#define CASE_ALPHA GTK_INPUT_PURPOSE_ALPHA
#define CASE_DIGIT GTK_INPUT_PURPOSE_DIGITS
#define CASE_NUMBE GTK_INPUT_PURPOSE_NUMBER
#define CASE_PHONE GTK_INPUT_PURPOSE_PHONE
#define CASE_URL   GTK_INPUT_PURPOSE_URL
#define CASE_EMAIL GTK_INPUT_PURPOSE_EMAIL
#define CASE_NAME  GTK_INPUT_PURPOSE_NAME
#define CASE_PASSW GTK_INPUT_PURPOSE_PASSWORD
#define CASE_PIN   GTK_INPUT_PURPOSE_PIN

#endif // CASE_H
