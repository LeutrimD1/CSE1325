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
	Gtk::Box VBox;//VBox is for quit button at the bottom
	//-----------------------tabs---------------------------
	Gtk::Grid grid1;
	Gtk::Grid grid2;
	Gtk::Grid grid3;
	//------------------------------------------------------
	Gtk::Notebook Notebook;//Creates the widget which contains the pages.
	Gtk::RadioButton Latte_Check, Cappuccino_Check, Macchiato_Check;//Radio buttons for selecting the drink.
	Gtk::RadioButton Small_Check, Medium_Check, Large_Check; //Radio buttons for selecting the size of a drink.
	Gtk::RadioButton Vanilla_Check, Caramel_Check, None_Check; //Radio buttons for selecting a flavor.
	Gtk::Image image;//creates the image widget.
	Gtk::Label Label1, Label2, Label3, Label12, Label13;//needs explaination.
	//---------------------page buttons---------------------
	Gtk::ButtonBox ButtonBox;
	Gtk::Button quit;//Button used to quit
	Gtk::Button order;
	//.....................nutrition widgets...............
	Gtk::Button Latte; //opens Latte nutrition
	Gtk::Button Cap; //opens Cappaccino nutrition
	Gtk::Button Machi; //opens Macchiato nutrition

	void on_latte(); //opens Latte
	void on_cap(); //opens Cap
	void on_machi(); //opens Machi

};//test
#endif //GTKMM_EXAMPLE:WINDOW_H
