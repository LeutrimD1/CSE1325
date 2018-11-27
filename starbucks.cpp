#include "starbucks.h"
#include <iostream>
main_window::main_window(){
//	set_size_request(724,483);	//sets the size of the window
	set_title("STARBUCKS");
	image.set("starbucks_img.jpg"); //sets the image
	grid.attach(image, 0, 0, 3, 1); //attachs the image
	//---------------------BUTTONS---------------------
	order.add_label("Order");
	grid.attach(order,2,2,1,1);
	//signal handler here
	//-------------------------------------------------
	apply.add_label("Apply");
	grid.attach(apply,1,2,1,1);
	//signal handler here
	//-------------------------------------------------
	quit.add_label("Quit");
	quit.signal_pressed().connect(sigc::mem_fun(*this,&main_window::close));
	grid.attach(quit,0,2,1,1);	//attachs the button
	//-------------------------------------------------
	grid.show_all();		//shows all things attached to grid
	add(grid);			//finally adds the grid to the window
}
main_window::~main_window(){		//destructor empty
};
//add signal handler functions below
