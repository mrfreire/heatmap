# Heatmap - A C++ heatmap recording library for games 


HOW TO USE

To integrate Heatmap in your project, simply add Heatmap.h to your codebase.


FEATURES

* Minimal runtime that supports storing 4-dimensional points and flushing
  the current state to a file.
* No dynamic memory allocation (default footprint 32KB, but can be easily
  tweaked for your needs)
* Single-file header library, super easy to integrate
* Easy to extend for your own purposes (higher-dimensional points, etc)
* Basic offline data viewer for 2-dimensional points


APPLICATIONS

1. Mouse interaction heatmaps (using x and y mouse coordinates)
2. Tracing avatar paths in a 3D level to visualise hot areas or identify level
   design problems.
3. Animated heatmaps (e.g. using the fourth point coordinate for time)


TESTING

There is a Visual Studio 2013 solution (Dev/HeatmapDev.sln) that allows running
and debugging a basic Test App that uses the Heatmap library.

The Test App simply consists of a blank Windows app that records the mouse
movements that fall inside the window, and outputs them to the text file
Dev/TestApp/heatmap_out.txt

The Visual Studio solution also includes a UnitTests project.


VISUALISING DATA

This project includes a very basic offline viewer written in Python that
visualises 2-dimensional points as produced by the Heatmap library. You can use
it to display basic data, but its real purpose is to illustrate how a more
advance viewer could use the library output.

To run the viewer:
- Install Python 2.7 and matplotlib (on Windows, you can get this by installing
  Python(x,y): https://code.google.com/p/pythonxy/wiki/Downloads)
- Save your Heatmap library output in Viewer/heatmap_data.txt (for example, the
  data produced by running the Test App described above)
- Run Viewer/HeatmapViewer.py


FUTURE WORK

* Improve Python viewer to support arbitrary width / height and input files
* Unity wrapper
* Real time viewer


AUTHOR

Manuel Freire <manuel.r.freire@gmail.com>

