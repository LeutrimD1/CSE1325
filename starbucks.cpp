#include <iostream>
#include "starbucks.h"
/*Sup*/
main_window::main_window()
: m_VBox(Gtk::ORIENTATION_VERTICAL),
	m_Label1("Contents of tab 1"),
	m_Label2("Contents of tab 2"),
	m_Label3("Contents of tab 3"),
	m_Button_Quit("Quit")
{
	set_title("Gtk::Notebook example");
	set_border_width(2);
	set_default_size(743, 560);


	add(m_VBox);

	//Add the Notebook, with the button underneath:
	m_Notebook.set_border_width(3);
	image.set("starbucks_img.jpg");
	m_VBox.pack_start(m_Notebook);
	m_VBox.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);

	m_ButtonBox.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);
	m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this, &main_window::on_button_quit));

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
