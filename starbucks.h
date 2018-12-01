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
	Gtk::Box VBox;							//VBox is for quit button at the bottom
	//-----------------------tabs---------------------------
	Gtk::Grid grid1;
	Gtk::Grid grid2;
	Gtk::Grid grid3;
	//------------------------------------------------------
	Gtk::Notebook Notebook;						 //Creates the widget which contains the pages.
	Gtk::RadioButton Pick_Drink_Check, Pick_Size_Check, No_Flavor_Check;	//Default radio buttons
	Gtk::RadioButton Latte_Check, Cappuccino_Check, Macchiato_Check; //Radio buttons for selecting the drink.
	Gtk::RadioButton Small_Check, Medium_Check, Large_Check; 	 //Radio buttons for selecting the size of a drink.
	Gtk::RadioButton Vanilla_Check, Caramel_Check, Mocha_Check; 	 //Radio buttons for selecting a flavor.
	Gtk::Image image;						 //creates the image widget.
	Gtk::Label Label_drink, Label_flavor, Label_size;		//Labels for the .
	Gtk::Label Label_Cappuccino, Label_Macchiato, Label_Latte, Drink_Default;	//Labels for the drinks.
	Gtk::Label Label_small, Label_medium, Label_large, Size_Default;		//Labels for the size.
	Gtk::Label Label_vanilla, Label_caramel, Label_mocha, Flavor_Default;		//Labels for the flavor.
	//---------------------page buttons---------------------
	Gtk::ButtonBox ButtonBox;					//Holds the buttons below
	Gtk::Button quit;						//Button used to quit
	Gtk::Button order;						//Button used to send the order out
	//.....................nutrition widgets...............
	Gtk::Button Latte; 					//opens Latte nutrition
	Gtk::Button Cap; 					//opens Cappaccino nutrition
	Gtk::Button Machi;					//opens Macchiato nutrition
	
	//*********************Signals for the check boxes******
	void no_drink_selected();				//None is checked
	void latte_check_selected();				//Latte_check selected
	void cappuccino_check_selected();			//Cappuccino_check selected
	void macchiato_check_selected();			//Machiato_check selected

	void no_size_selected();				//None is checked
	void small_check_selected();				//Small_check selected
	void medium_check_selected();				//Medium_check selected
	void large_check_selected();				//Large_check selected

	void no_flavor_selected();				//None is selected
	void vanilla_check_selected();				//Vanilla_check selected
	void caramel_check_selected();				//Caramel_check selected
	void mocha_check_selected();				//None_check selected
	void on_latte(); 					//opens Latte
	void on_cap(); 						//opens Cap
	void on_machi(); 					//opens Machi
};
#endif //GTKMM_EXAMPLE:WINDOW_H
