#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>
/*class RadioButtons : public Gtk::Window
{
	public:
		RadioButton();
	protected:
		Gtk::RadioButton */
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
	Gtk::Box VBox;//VBox is for quit button at the bottom
	//-----------------------tabs---------------------------
	Gtk::Grid grid1;
	Gtk::Grid grid2;
	Gtk::Grid grid3;
	//------------------------------------------------------
	Gtk::Notebook Notebook;
	Gtk::RadioButton Latte_Check, Cappuccino_Check, Macchiato_Check;
	Gtk::Image image;
	Gtk::Label Label1, Label2, Label3;

	Gtk::ButtonBox ButtonBox;
	Gtk::Button quit;
	Gtk::Button order;
};

#endif //GTKMM_EXAMPLE:WINDOW_H
