//////////////////////////////////////////////////////////////////////
/// @file main.cpp
/// @author James Anderson  Section A
/// @brief main file for sudoku sover for assignment 11
////////////////////////////////////////////////////////////////////// 
#include <QApplication>
#include "mainwindow.h"

int main( int argc, char *argv[] )
{
	QApplication app ( argc, argv);
	MainWindow window;
	window.show();
	
	return app.exec();
}
