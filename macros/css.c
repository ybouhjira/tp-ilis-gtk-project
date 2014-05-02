#include <gtk/gtk.h>

void css_apply(char *filename)
{
  GtkCssProvider *provider = gtk_css_provider_new();
  GdkDisplay *display = gdk_display_get_default();
  GdkScreen *screen = gdk_display_get_default_screen(display);

  gtk_style_context_add_provider_for_screen(
        screen,
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

  gtk_css_provider_load_from_path(GTK_CSS_PROVIDER(provider), filename, NULL);
  g_object_unref(provider);
}

