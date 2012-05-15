MagBounce - The Game
====================

MagBounce is a platform/puzzle/sidescroll game about magnetism.

It was developed within 48h (Version 0.1) for the GameJam Contest of GPN11 (https://entropia.de/GPN11) by the MOSDEV Team.

MagBounce - Development
=======================

Originally developed in Java Magbounce was recently ported to C++.
After the first Port using [Allegro](http://alleg.sourceforge.net/) a basic Engine wrapping the Allegro stuff was extracted - the result was [R2D](https://github.com/Landkeks/R2D) now utilized as a submodule.

MagBounce - Setup
-----------------

You will need Allegro. To get it the [Allegro Wiki](http://wiki.allegro.cc/index.php?title=Install_Allegro5_From_SVN) might be a good start.

After you cloned the repository you'll still have to initialize the r2d submodule:
	git submodule init
	git submodule update
It's strongly recommanded not to work in the submodule but clone r2d and work there if you want to contribute to the engine.

Magbounce uses [CMake](http://www.cmake.org/) for building. On linux there will be most likely a package. If not and for other OS take a look at the cmake homepage.

Once you got everything set up run
	mkdir build
	cd build
	cmake ..
to generate a makefile.

Now you can  build magbounce with
	make
and execute it with
	./Magbounce

To build for debugging you'll have to run
	cmake -DCMAKE_BUILD_TYPE=Debug ..
in the build directory.

