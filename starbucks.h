#ifndef HEADER
#define HEADER
#include <gtkmm.h>
class main_window : public Gtk::Window{
	public:
		main_window();		//constructor
		virtual ~main_window();	//destructor
	protected:
		//add stuff here
		//signal handlers
		//widgets
		Gtk::Image image;
		Gtk::Grid grid;
};
#endif
