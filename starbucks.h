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
	Gtk::Notebook m_Notebook;
	Gtk::Image image;
	Gtk::Label m_Label1, m_Label2, m_Label3;

	Gtk::ButtonBox m_ButtonBox;
	Gtk::Button quit;
	Gtk::Button order;
};

#endif //GTKMM_EXAMPLE:WINDOW_H
