#include "starbucks.h"
#include <iostream>
main_window::main_window(){
//	set_size_request(724,483);	//sets the size of the window
	set_title("STARBUCKS");
	image.set("starbucks_img.jpg"); //sets the image
	grid.attach(image, 0, 0, 1, 1); //attachs the image
	grid.show_all();		//shows all things attached to grid
	add(grid);			//finally adds the grid to the window
}
main_window::~main_window(){		//destructor empty
};
//add signal handler functions below
