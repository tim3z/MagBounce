/* 
 * File:   main.cpp
 * Author: eagle
 *
 * Created on 22. Oktober 2011, 19:10
 */

#include <cstdio>
#include <allegro5/allegro.h>

/*
 * 
 */
int main(int argc, char** argv) {

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
        
	return 0;
}
