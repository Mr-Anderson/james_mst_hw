#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//////////////////////////////////////////////////////////////////////
/// @file mainwindow.h
/// @author James Anderson  Section A
/// @brief main file for sudoku sover for assignment 11
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class MainWindow
/// @brief Used to creade sudouku solver
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn MainWindow::MainWindow()
/// @brief creates the main window
/// @post main window created
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn void MainWindow::createActions()
/// @brief This function creates all of the QAction objects
/// @post This creates a new QAction object and specifies the text to appear on it
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn MainWindow::createMenus()
/// @brief This function creates all of the QMenus and adds the QAction objects into them
/// @post Displays a pop-up window
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn MainWindow::open( QString  )
/// @brief This function reads in a Sudoku puzzle file and puts its contents
/// @post onto the applications puzzle board
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn MainWindow::slot_file_open()
/// @brief This function loads a saved file
/// @post file is displayed
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn MainWindow::slot_file_exit()
/// @brief When the user selects this the program exits
/// @post program closes
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn MainWindow::slot_difficulty_novice()
/// @brief Sets the selected difficulty level to novice
/// @post unsets other difficultys
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn MainWindow::slot_difficulty_intermediate()
/// @brief Sets the selected difficulty level to intermediate
/// @post unsets other difficultys
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn MainWindow::slot_difficulty_expert()
/// @brief Sets the selected difficulty level to expert
/// @post unsets other difficultys
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn MainWindow::slot_file_save()
/// @brief Saves the puzzles current state to a file
/// @post program closes
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn MainWindow::slot_help_solve()
/// @brief solves puzzle
/// @post dosent work
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/// @fn MainWindow:: checknum( unsigned int row, unsigned int collum)
/// @brief cheks number in slot given
/// @post feeds back number
////////////////////////////////////////////////////////////////////// 

#include <QMainWindow>
#include <QtGui>
#include "puzzleBoard.h"
#include "cstdlib"
#include "iostream"
using std::cerr ;
using std::endl ;

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
	public:
		MainWindow();

	private slots:
		void slot_file_new();
		void slot_file_open();
		void slot_file_save();
		void slot_file_exit();
		void slot_difficulty_novice();
		void slot_difficulty_intermediate();
		void slot_difficulty_expert();
		void slot_help_solve();
		void slot_help_about();
		
	private:
		QWidget * window;
		PuzzleBoard * puzzleBoard; 
		
		QMenu * menu_file;
		QMenu * menu_difficulty;
		QMenu * menu_help;
		QAction * action_file_new;
		QAction * action_file_open;
		QAction * action_file_save;
		QAction * action_file_exit;
		QAction * action_difficulty_novice;
		QAction * action_difficulty_intermediate;
		QAction * action_difficulty_expert;
		QAction * action_help_solve;
		QAction * action_help_about;
		
		void createActions();
		void createMenus();
		void open( QString );
		void solve( unsigned int , unsigned int , bool );
		void newsolve( unsigned int , unsigned int  );
		bool checknum(unsigned int , unsigned int) ;
		unsigned int boxValue[9][9];
		bool puzzleDefined[9][9];
};

#endif
