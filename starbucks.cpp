#include <iostream>
#include "starbucks.h"

main_window::main_window()
: VBox(Gtk::ORIENTATION_VERTICAL),
	Label1("Contents of tab 1"),
	Label2("Contents of tab 2"),
	Label3("Contents of tab 3"),
	quit("Quit")
{
	set_title("STARBUCKS");			//sets the title the window
	set_border_width(2);			//sets the boarder width
	set_default_size(743, 560);		//sets the size of the main window
	add(VBox);				//adds the vbox to the window
	//Add the Notebook, with the button underneath:
	Notebook.set_border_width(3);		//idk what this does
	image.set("starbucks_img.jpg");		//sets the image 
	VBox.pack_start(Notebook);
	VBox.pack_start(ButtonBox, Gtk::PACK_SHRINK);
	Cappuccino_Check.join_group(Latte_Check);
	Macchiato_Check.join_group(Latte_Check);
	grid1.attach(Label1,0,0,1,1);
	grid1.attach(Latte_Check,0,1,1,1);
	grid1.attach(Cappuccino_Check,0,2,1,1);
	grid1.attach(Macchiato_Check,0,3,1,1);



	ButtonBox.pack_start(quit, Gtk::PACK_SHRINK);
	quit.signal_clicked().connect(sigc::mem_fun(*this, &main_window::on_button_quit));

	//Add the Notebook pages:
	Notebook.append_page(image, "Home");
	Notebook.append_page(grid1, "Order");
	Notebook.append_page(grid2, "Apply");
	Notebook.append_page(grid3, "Nutrition Facts");

	Notebook.signal_switch_page().connect(sigc::mem_fun(*this, &main_window::on_notebook_switch_page));

	show_all_children();
}

main_window::~main_window()
{
}
void main_window::on_button_quit()
{
	hide();
}

void main_window::on_notebook_switch_page(Gtk::Widget* /* page */, guint page_num)
{
	std::cout << "Switched to tab with index " << page_num << std::endl;

	//You can also use Notebook.get_current_page() to get this index.
}
