
#include <iostream>
#include "starbucks.h"
/*WHAT IS UP PARTY PEOPLE!!!!*/
main_window::main_window()
: VBox(Gtk::ORIENTATION_VERTICAL),
	Label_drink("Drink"),
	Label_flavor("Flavor"),
	Label_size("size"),
	//----------------------------
	Label_Cappuccino("Cappuccino"),
	Label_Macchiato("Macchiato"),
	Label_Latte("Latte"),
	//---------------------------
	Label_small("Small"),
	Label_medium("Medium"),
	Label_large("Large"),
	//---------------------------
	Label_vanilla("Vanilla"),
	Label_caramell("Caramell"),
	Label_mocha("Mocha"),
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
	//---------Connects all buttons to each other-----------
	Cappuccino_Check.join_group(Latte_Check);
	Macchiato_Check.join_group(Latte_Check);
	Medium_Check.join_group(Small_Check);
	Large_Check.join_group(Small_Check);
	Caramel_Check.join_group(Vanilla_Check);
	None_Check.join_group(Vanilla_Check);
	/*---------Drink types check boxes---------------------*/
	//labels
	grid1.attach(Label_drink,     		0,0,1,1);
	grid1.attach(Label_Latte,     		1,1,1,1);
	grid1.attach(Label_Cappuccino,   	1,2,1,1);
	grid1.attach(Label_Macchiato,     	1,3,1,1);
	//checkboxes
	grid1.attach(Latte_Check,     		0,1,1,1);
	grid1.attach(Cappuccino_Check,		0,2,1,1);
	grid1.attach(Macchiato_Check, 		0,3,1,1);
	
	/*---------Size check boxes----------------------------*/
	//labels
	grid1.attach(Label_size,      2,0,1,1);
	grid1.attach(Label_small,     3,1,1,1);
	grid1.attach(Label_medium,    3,2,1,1);
	grid1.attach(Label_large,     3,3,1,1);
	//checkboxes
	grid1.attach(Small_Check,     2,1,1,1);
	grid1.attach(Medium_Check,    2,2,1,1);
	grid1.attach(Large_Check,     2,3,1,1);
	/*---------Flavor check boxes--------------------------*/
	//labels
	grid1.attach(Label_flavor,   	 4,0,1,1);
	grid1.attach(Label_vanilla,    	 5,1,1,1);
	grid1.attach(Label_caramell,   	 5,2,1,1);
	grid1.attach(Label_mocha,    	 5,3,1,1);
	//checkboxes
	grid1.attach(Vanilla_Check,   4,1,1,1);
	grid1.attach(Caramel_Check,   4,2,1,1);
	grid1.attach(None_Check,      4,3,1,1);//need to add button for mocha flavor
	
	//We need to find someway to intergrate the follwing with the labels and radio buttons
	//grid1.attach_next_to(child(Gtk::Widget), sibling(Gtk::Widget), Postition,Side, Width);

	//Nutrition Tab Set Up	
	Latte.add_label("Latte");
	Cap.add_label("Cappaccino");
	Machi.add_label("Macchiatto");

	grid3.add(Latte);
	grid3.add(Cap);
	grid3.add(Machi);

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
