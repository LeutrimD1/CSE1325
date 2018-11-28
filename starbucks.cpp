#include <iostream>
#include "starbucks.h"
main_window::main_window()
: VBox(Gtk::ORIENTATION_VERTICAL),
	m_Label1("Contents of tab 1"),
	m_Label2("Contents of tab 2"),
	m_Label3("Contents of tab 3"),
	quit("Quit")
{
	set_title("STARBUCKS");//sets the title the window
	set_border_width(2);//sets the boarder width
	set_default_size(743, 560);//sets the size of the main window
	add(VBox);//adds the vbox to the window
	//Add the Notebook, with the button underneath:
	m_Notebook.set_border_width(3);//idk what this does
	image.set("starbucks_img.jpg");//sets the image 
	VBox.pack_start(m_Notebook);
	VBox.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);

	m_ButtonBox.pack_start(quit, Gtk::PACK_SHRINK);
	quit.signal_clicked().connect(sigc::mem_fun(*this, &main_window::on_button_quit));

	//Add the Notebook pages:
	m_Notebook.append_page(image, "Home");
	m_Notebook.append_page(m_Label1, "Order");
	m_Notebook.append_page(m_Label2, "Apply");
	m_Notebook.append_page(m_Label3, "Nutrition Facts");

	m_Notebook.signal_switch_page().connect(sigc::mem_fun(*this, &main_window::on_notebook_switch_page));

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

	//You can also use m_Notebook.get_current_page() to get this index.
}
