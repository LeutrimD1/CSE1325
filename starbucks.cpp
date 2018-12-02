#include <iostream>
#include <string>
#include "starbucks.h"

/*WHAT IS UP PARTY PEOPLE!!!!*/
// Chillin', Killin'
using namespace std;
//-----------global price variables-------------
double drink_price = 0;
double size_multi = 0;
double flavor_price = 0;
float price = 0;
//-----------global string variables-----------
string drink;
string flavor;
string size;
//-------------submit_application variables------------
string first_name;
string last_name;
string age;
//-------------Main Window Set Up----------------
main_window::main_window()
: VBox(Gtk::ORIENTATION_VERTICAL),
	Label_drink("Drink"),
	Label_flavor("Flavor"),
	Label_size("Size"),
	//----------------------------
	Label_Cappuccino("Cappuccino"),
	Label_Macchiato("Macchiato"),
	Label_Latte("Latte"),
	Drink_Default("Select drink"),
	//---------------------------
	Label_small("Small"),
	Label_medium("Medium"),
	Label_large("Large"),
	Size_Default("Select size"),
	//---------------------------
	Label_vanilla("Vanilla"),
	Label_caramel("Caramel"),
	Label_mocha("Mocha"),
	Flavor_Default("None"),
	quit("Quit"),
	calculate("Calculate"),
	order("Send order")
{
	//---empty out order file---
	//std::ofstream ofs;	//this block empty out txt file so you can fill it each run.
	ofs.open("list_orders.txt",std::ofstream::out | std::ofstream::trunc);
	ofs.close();
    
	//---empty out application file---
	std::ofstream outs;			//Same as above, but for the application file
	outs.open("list_applications.txt",std::ofstream::out | std::ofstream::trunc);
	outs.close();

	ofs.open("list_orders.txt",std::ofstream::out | std::ofstream::trunc);	//stream object is declare in header.
	ofs<<"List of orders for the day\n";					//adds to file, file closes on quit.

	//--------------------------
	set_title("STARBUCKS");			//sets the title the window
	set_border_width(2);			//sets the border width
	set_default_size(743, 560);		//sets the size of the main window
	add(VBox);				//adds the vbox to the window
	//Add the Notebook, with the button underneath:
	Notebook.set_border_width(3);		//idk what this does
	image.set("starbucks_img.jpg");		//sets the image 
	VBox.pack_start(Notebook);
	VBox.pack_start(ButtonBox, Gtk::PACK_SHRINK);
	//---------Connects all buttons to each other-----------
	Latte_Check.join_group(Pick_Drink_Check);
	Cappuccino_Check.join_group(Pick_Drink_Check);
	Macchiato_Check.join_group(Pick_Drink_Check);	
	/*Cappuccino_Check.join_group(Latte_Check);
	Macchiato_Check.join_group(Latte_Check);
	Pick_Drink_Check.join_group(Latte_Check);*/
	Small_Check.join_group(Pick_Size_Check);
	Medium_Check.join_group(Pick_Size_Check);
	Large_Check.join_group(Pick_Size_Check);
	//Pick_Size_Check.join_group(Small_Check);
	Vanilla_Check.join_group(No_Flavor_Check);
	Caramel_Check.join_group(No_Flavor_Check);
	Mocha_Check.join_group(No_Flavor_Check);
	//No_Flavor_Check.join_group(Vanilla_Check);
	/*---------Drink types check boxes---------------------*/
	//labels
	grid1.attach(Label_drink,     		0,0,1,1);
	grid1.attach(Drink_Default,    		1,1,1,1);
	grid1.attach(Label_Latte,     		1,2,1,1);
	grid1.attach(Label_Cappuccino,   	1,3,1,1);
	grid1.attach(Label_Macchiato,     	1,4,1,1);
	//checkboxes
	grid1.attach(Pick_Drink_Check,		0,1,1,1);
	grid1.attach(Latte_Check,     		0,2,1,1);
	grid1.attach(Cappuccino_Check,		0,3,1,1);
	grid1.attach(Macchiato_Check, 		0,4,1,1);
	//attaching the signals to the checkboxes.
	Pick_Drink_Check.signal_toggled().connect(sigc::mem_fun(*this, &main_window::no_drink_selected));
	Latte_Check.signal_toggled().connect(sigc::mem_fun(*this, &main_window::latte_check_selected));
	Cappuccino_Check.signal_toggled().connect(sigc::mem_fun(*this, &main_window::cappuccino_check_selected));
	Macchiato_Check.signal_toggled().connect(sigc::mem_fun(*this, &main_window::macchiato_check_selected));
	/*---------Size check boxes----------------------------*/
	//labels
	grid1.attach(Label_size,      2,0,1,1);
	grid1.attach(Size_Default,    3,1,1,1);
	grid1.attach(Label_small,     3,2,1,1);
	grid1.attach(Label_medium,    3,3,1,1);
	grid1.attach(Label_large,     3,4,1,1);
	//checkboxes
	grid1.attach(Pick_Size_Check, 2,1,1,1);
	grid1.attach(Small_Check,     2,2,1,1);
	grid1.attach(Medium_Check,    2,3,1,1);
	grid1.attach(Large_Check,     2,4,1,1);
	//attaching the signals to the checkboxes
	Pick_Size_Check.signal_toggled().connect(sigc::mem_fun(*this, &main_window::no_size_selected));
	Small_Check.signal_toggled().connect(sigc::mem_fun(*this, &main_window::small_check_selected));
	Medium_Check.signal_toggled().connect(sigc::mem_fun(*this, &main_window::medium_check_selected));
	Large_Check.signal_toggled().connect(sigc::mem_fun(*this, &main_window::large_check_selected));
	/*---------Flavor check boxes--------------------------*/
	//labels
	grid1.attach(Label_flavor,   	 4,0,1,1);
	grid1.attach(Flavor_Default,   	 5,1,1,1);
	grid1.attach(Label_vanilla,    	 5,2,1,1);
	grid1.attach(Label_caramel,   	 5,3,1,1);
	grid1.attach(Label_mocha,    	 5,4,1,1);
	//checkboxes
	grid1.attach(No_Flavor_Check,   4,1,1,1);
	grid1.attach(Vanilla_Check,   	  4,2,1,1);
	grid1.attach(Caramel_Check,       4,3,1,1);
	grid1.attach(Mocha_Check,         4,4,1,1);
	//attaching the signals to the checkboxes
	No_Flavor_Check.signal_toggled().connect(sigc::mem_fun(*this, &main_window::no_flavor_selected));
	Vanilla_Check.signal_toggled().connect(sigc::mem_fun(*this, &main_window::vanilla_check_selected));
	Caramel_Check.signal_toggled().connect(sigc::mem_fun(*this, &main_window::caramel_check_selected));
	Mocha_Check.signal_toggled().connect(sigc::mem_fun(*this, &main_window::mocha_check_selected));
	//-------------------------Apply Tab Set Up--------------------------------
	First_Name.set_text("*Enter first name here*");
	Last_Name.set_text("*Enter last name here*");
	Age.set_text("*Enter age here*");
	Submit.add_label("Submit Application");

	First_Name.set_max_width_chars(25);
	First_Name.set_width_chars(25);
	Last_Name.set_max_width_chars(25);
	Last_Name.set_width_chars(25);

	//Attaching function to submit button
	Submit.signal_pressed().connect(sigc::mem_fun(*this, &main_window::submit_application));

	grid2.add(First_Name);
	grid2.add(Last_Name);
	grid2.add(Age);
	grid2.add(Submit);
	//-------------------------Nutrition Tab Set Up-----------------------------
	Latte.add_label("Latte");
	Cap.add_label("Cappaccino");
	Machi.add_label("Macchiatto");
	
	imagel.set("Latte_nutrition.png"); //setting image
	imagec.set("Cappuccino_nutrition.png"); //setting image
	imagem.set("Macchiato_nutrition.png"); //setting image
	
	
	grid3.attach(imagel,0,0,1,1); //image attach
	grid3.attach(imagec,0,1,2,1); //image attach
	grid3.attach(imagem,0,2,3,1); //image attach
	scroll.add(grid3); //attching grid to scroll

	//---------------------------------------------------------------------------
	//ButtonBox.pack_start(calculate, Gtk::PACK_SHRINK);
	grid1.attach(calculate,		0,5,1,1);
	grid1.attach(order,		1,5,2,1);
	calculate.signal_clicked().connect(sigc::mem_fun(*this, &main_window::on_calculate));
	ButtonBox.pack_start(quit, Gtk::PACK_SHRINK);
	quit.signal_clicked().connect(sigc::mem_fun(*this, &main_window::on_button_quit));
	order.signal_clicked().connect(sigc::mem_fun(*this, &main_window::on_send_order));

	//Add the Notebook pages:
	Notebook.append_page(image, "Home");
	Notebook.append_page(grid1, "Order");
	Notebook.append_page(grid2, "Apply");
	Notebook.append_page(scroll, "Nutrition Facts");

	Notebook.signal_switch_page().connect(sigc::mem_fun(*this, &main_window::on_notebook_switch_page));

	show_all_children();
}

main_window::~main_window()
{
}

//-------------------Functions----------------------------------
void main_window::on_send_order(){//pretty much done
	price = drink_price*size_multi + flavor_price;
	ofs<<drink<<size<<flavor<<"Revenue as of now:"<<"$"<<price<<"\n";	//writes out to file. file closes below on quit.
}
void main_window::on_button_quit()
{
	ofs.close();
	hide();
}

void main_window::on_calculate(){
	price = drink_price*size_multi + flavor_price;
	std::ostringstream ss;
	ss.precision(2);
	ss << std::fixed <<  price;
	std::string sprice = ss.str();
	std::string message = "The price of your overpriced bean water is $"+sprice;
	Gtk::MessageDialog	dialog(*this, message, false, Gtk::MESSAGE_INFO);
	dialog.run();
}
void main_window::on_notebook_switch_page(Gtk::Widget* /* page */, guint page_num){
	std::cout << "Switched to tab with index " << page_num << std::endl;
	//You can also use Notebook.get_current_page() to get this index.
}
//---------------Signals for when each of the buttons are selected
/*
I am setting the base value of the drinks as the following:
Latte:$2.00
Cappuccino:$3.00
Macchiato:$3.50
*/
void main_window::no_drink_selected(){
	if(Pick_Drink_Check.get_active())
	{
		drink_price=0;
		std::cout<<"Why no drinks"<<std::endl;
		drink = "No drink\n";
	}
}
void main_window::latte_check_selected(){
	if(Latte_Check.get_active()){
		drink_price+=2;
		std::cout<<"Yall want some lattes"<<std::endl;
		drink = "Latte ";
	}
}
void main_window::cappuccino_check_selected(){
	if(Cappuccino_Check.get_active()){
		drink_price+=3;	
		std::cout<<"Pop a cap"<<std::endl;
		drink = "Cappuccino ";
	}
}
void main_window::macchiato_check_selected(){
	if(Macchiato_Check.get_active()){	
		drink_price+=3.5;
		std::cout<<"Uh what"<<std::endl;
		drink = "Macchiato ";
	}
}
/*
I am setting the base value of the drinks as the following:
Small: x1 of drink
Medium: x2 of drink
Large: x3 of drink
*/
void main_window::no_size_selected(){
	if(Pick_Size_Check.get_active()){
		size_multi=0;
		std::cout<<"Yo, you gotta pick a size Holmes"<<std::endl;
		size = "No size selected ";
	}	
}
void main_window::small_check_selected(){
	if(Small_Check.get_active()){
		size_multi=1;
		std::cout<<"You sure about that?"<<std::endl;
		size = "Small ";
	}	
}
void main_window::medium_check_selected(){
	if(Medium_Check.get_active()){
		size_multi=2;
		std::cout<<"Almost..."<<std::endl;
		size = "Medium ";
	}	
}
void main_window::large_check_selected(){
	if(Large_Check.get_active()){
		size_multi=3;
		std::cout<<"BIG BOIS!"<<std::endl;
		size = "Large ";
	}
}
void main_window::no_flavor_selected(){
	if(No_Flavor_Check.get_active()){
		flavor_price = 0;
		std::cout<<"Lame"<<std::endl;
		flavor = "No flavor ";
	}
}
void main_window::vanilla_check_selected(){
	if(Vanilla_Check.get_active())	{	
		flavor_price = .25;
		std::cout<<"Boring"<<std::endl;
		flavor = "Vanilla ";
	}
}
void main_window::caramel_check_selected(){
	if(Caramel_Check.get_active()){
		flavor_price = .50;
		std::cout<<"SPELL IT RIGHT NEXT TIME LEUTRIM jk"<<std::endl;
		flavor = "Caramel ";
	}
}
void main_window::mocha_check_selected(){
	if(Mocha_Check.get_active()){
		flavor_price = .50;
		std::cout<<"Yummy"<<std::endl;
		flavor = "Mocha ";
	}
}
//------------------Apply function-------------------------------
void main_window::submit_application()
{
	std::ofstream outs;
	outs.open("list_applications.txt");

	if(Submit.get_focus_on_click())
	{
		first_name = First_Name.get_text();
		last_name = Last_Name.get_text();
		age = Age.get_text();
		cout << "Dude thinks he's getting a job, LOL." << endl;

		outs << "First Name : " << first_name << endl;
		outs << "Last Name : " << last_name << endl;
		outs << "Age : " << age << endl;
	}
}
