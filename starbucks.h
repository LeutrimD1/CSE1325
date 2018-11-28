#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>

class main_window : public Gtk::Window
{
public:
	main_window();
	virtual ~main_window();

protected:
	//Signal handlers:
	void on_button_quit();
	void on_notebook_switch_page(Gtk::Widget* page, guint page_num);

	//Child widgets:
	Gtk::Box VBox;
	Gtk::Notebook Notebook;
	Gtk::Image image;
	Gtk::Label Label1, Label2, Label3;

	Gtk::ButtonBox ButtonBox;
	Gtk::Button quit;
	Gtk::Button order;
};

#endif //GTKMM_EXAMPLE:WINDOW_H
