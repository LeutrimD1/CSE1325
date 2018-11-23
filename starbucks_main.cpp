#include "starbucks.h"
#include <gtkmm/application.h>
int main(int argc, char* argv[]){
	Gtk::Main app(argc, argv);
	main_window window1;
	Gtk::Main::run(window1);
	return 0;
}
