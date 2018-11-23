ex: starbucks.cpp starbucks_main.cpp
	g++ -std=c++11 -o starbucks starbucks_main.cpp starbucks.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
