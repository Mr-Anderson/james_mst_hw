#include "mainwindow.h"

//////////////////////////////////////////////////////////////////////
/// @file mainwindow.cpp
/// @author James Anderson  Section A
/// @brief main file for sudoku sover for assignment 11
////////////////////////////////////////////////////////////////////// 

MainWindow::MainWindow()
{
	window = new QWidget;
	setCentralWidget( window );
	setWindowTitle( "Sudoku" );
	setWindowIcon( QIcon( ":/icon.gif" ) );

	QGridLayout * layout = new QGridLayout;
	puzzleBoard = new PuzzleBoard();

	for( unsigned int i = 0; i < 9; i++ )
	{
		for( unsigned int j = 0; j < 9; j++ )
		{
			layout->addWidget(puzzleBoard->puzzleBox(i,j),i,j,1,1);
		}
	}
	window->setLayout( layout );

	createActions();
	createMenus();
}

//This function creates all of the QAction objects
void MainWindow::createActions()
{
	//This creates a new QAction object and specifies the text to appear on it
	action_file_new = new QAction( tr( "&New" ), this);

	//This text appears as an extra description when a user hovers over the menu item
	action_file_new->setStatusTip( tr( "Create a new puzzle" ) );

	//The slot_file_new function is called whenever the triggered SIGNAL is thrown
	connect( action_file_new, SIGNAL( triggered() ), this, SLOT( slot_file_new() ) );

	action_file_open = new QAction( tr( "&Open" ), this );
	action_file_open->setStatusTip( tr( "Open a saved puzzle" ) );
	connect( action_file_open, SIGNAL( triggered() ), this, SLOT( slot_file_open() ) );

	action_file_save = new QAction( tr( "&Save" ), this );
	action_file_save->setStatusTip( tr( "Save your current puzzle" ) );
	connect( action_file_save, SIGNAL( triggered() ), this, SLOT( slot_file_save() ) );

	action_file_exit = new QAction( tr( "&Exit" ), this );
	action_file_exit->setStatusTip( tr( "Exit Sudoku" ) );
	connect( action_file_exit, SIGNAL( triggered() ), this, SLOT( slot_file_exit() ) );

	action_difficulty_novice = new QAction( tr( "&Novice" ), this );
	action_difficulty_novice->setStatusTip( tr( "Play Sudoku at a novice difficulty" ) );
	action_difficulty_novice->setCheckable( true );
	action_difficulty_novice->setChecked( true );
	connect
	(
		action_difficulty_novice,
		SIGNAL(triggered()),
		this,
		SLOT(slot_difficulty_novice())
	);
	action_difficulty_intermediate = new QAction( tr( "&Intermediate" ), this );
	action_difficulty_intermediate->setStatusTip
	(
		tr( "Play Sudoku at an intermediate difficulty" )
	);
	action_difficulty_intermediate->setCheckable( true );
	connect
	(
		action_difficulty_intermediate,
		SIGNAL( triggered() ),
		this,
		SLOT( slot_difficulty_intermediate() )
	);

	action_difficulty_expert = new QAction( tr( "&Expert" ), this );
	action_difficulty_expert->setStatusTip( tr( "Play Sudoku at an expert difficulty" ) );
	action_difficulty_expert->setCheckable( true );
	connect
	(
		action_difficulty_expert,
		SIGNAL( triggered() ),
		this,
		SLOT( slot_difficulty_expert() )
	);
	
	action_help_solve = new QAction( tr( "&Solve" ), this );
	action_help_solve->setStatusTip( tr( "Show the puzzle's solution" ) );
	connect( action_help_solve, SIGNAL( triggered() ), this, SLOT( slot_help_solve() ) );

	action_help_about = new QAction( tr( "&About" ), this );
	action_help_about->setStatusTip( tr( "Show information about this Sudoku software" ) );
	connect( action_help_about, SIGNAL( triggered() ), this, SLOT( slot_help_about() ) );
}

//This function creates all of the QMenus and adds the QAction objects into them
void MainWindow::createMenus()
{
	menu_file = menuBar()->addMenu( tr( "&File" ) );
	menu_file->addAction( action_file_new );
	menu_file->addAction( action_file_open );
	menu_file->addAction( action_file_save );
	menu_file->addAction( action_file_exit );
	menu_difficulty = menuBar()->addMenu( tr( "&Difficulty" ) );
	menu_difficulty->addAction( action_difficulty_novice );
	menu_difficulty->addAction( action_difficulty_intermediate );
	menu_difficulty->addAction( action_difficulty_expert );
	menu_help = menuBar()->addMenu( tr( "&Help" ) );
	menu_help->addAction( action_help_solve );
	menu_help->addAction( action_help_about );
}

//Whenever a user selects to receive a new Sudoku puzzle, we want to
//randomly generate a puzzle based on the difficulty level they have
//selected. In this function, the code checks to see which difficulty
//the user has selected and it then loads one of the three available
//puzzles
void MainWindow::slot_file_new()
{
	//seeds the random number generator
	qsrand((QTime::currentTime()).msec());
	//selects a random number and adds it to the filename string
	QString fileName;
	fileName.setNum( qrand() % 3 );
	//based on the user’s selected difficulty it appends a suffix
	if( action_difficulty_novice->isChecked() )
	{
		fileName.append( ".novice" );
	}
	else if( action_difficulty_intermediate->isChecked() )
	{
		fileName.append( ".intermediate" );
	}
	else
	{
		fileName.append( ".expert" );
	}
	
	//we then try to load one of the puzzles onto our board
	open( fileName );
}

//Displays a pop-up window
void MainWindow::slot_help_about()
{
	QMessageBox::about
	(
		this,
		tr("About Sudoku"),
		tr("This Sudoku puzzle solver was written by Matt Buechler and the solve functionality was added by James Anderson")
	);
}

//This function reads in a Sudoku puzzle file and puts its contents
//onto the applications puzzle board
void MainWindow::open( QString fileName )
{
	QFile file;
	file.setFileName( fileName );

	if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
	{
		//error
		return;
	}
	
	//QTextStreams work just like the file streams you are familiar with
	QTextStream in( &file );
	QChar character;

	for( unsigned int i = 0; i < 9; i++ )
	{
		for( unsigned int j = 0; j < 9; j++ )
		{
			in >> character;
			
			//checks to see if the character is a P. P’s are puzzle defined
			//and can not be changed by the user.
			if( character == 'P' )
			{
				//if it was a P, then we place that number on the board and
				//disable the users ability to write or edit that box.
				in >> character;
				puzzleBoard->puzzleBox( i, j )->setText( character );

				QPalette p = puzzleBoard->puzzleBox( i, j )->palette();
				p.setColor( QPalette::Text, QColor( Qt::darkGray ) );
				puzzleBoard->puzzleBox( i, j )->setPalette( p );
				puzzleBoard->puzzleBox( i, j )->setReadOnly( true );
			}
			else
			{
				//if it wasn’t a P, then it is a user editable box
				in >> character;

				//if the next character is an X, then the square is blank
				if( character == 'X' )
				{
					puzzleBoard->puzzleBox( i, j )->clear();
				}
				//otherwise, place the users number into the square
				else
				{
					puzzleBoard->puzzleBox( i, j )->setText( character );
				}
				
				QPalette p = puzzleBoard->puzzleBox( i, j )->palette();
				p.setColor( QPalette::Text, QColor( Qt::black ) );
				puzzleBoard->puzzleBox( i, j )->setPalette( p );

				puzzleBoard->puzzleBox( i, j )->setReadOnly( false );
			}
		}
	}
}

//This function loads a saved file
void MainWindow::slot_file_open()
{
	//This is our previously defined open function
	open
	(
		//This opens up a dialog box that allows the user browse his or her
		//drives for .sudoku files. It then returns a string containing
		//the filename that the user has selected
		QFileDialog::getOpenFileName
		(
			this,
			tr("Open a saved Sudoku puzzle"),
			"",
			tr("Sudoku puzzles (*.sudoku)")
		)
	);
}

//When the user selects this the program exits
void MainWindow::slot_file_exit()
{
	close();
}

//Sets the selected difficulty level to novice
void MainWindow::slot_difficulty_novice()
{
	action_difficulty_novice->setChecked( true );
	action_difficulty_intermediate->setChecked( false );
	action_difficulty_expert->setChecked( false );
}

//Sets the selected difficulty level to intermediate
void MainWindow::slot_difficulty_intermediate()
{
	action_difficulty_novice->setChecked( false );
	action_difficulty_intermediate->setChecked( true );
	action_difficulty_expert->setChecked( false );
}

//Sets the selected difficulty level to expert
void MainWindow::slot_difficulty_expert()
{
	action_difficulty_novice->setChecked( false );
	action_difficulty_intermediate->setChecked( false );
	action_difficulty_expert->setChecked( true );
}

//Saves the puzzles current state to a file
void MainWindow::slot_file_save()
{
	//This opens up a dialog box that allows the user to browse his or
	//her drives for a suitable location and filename to save into.
	QString fileName =
	QFileDialog::getSaveFileName
	(
		this,
		tr("Save your Sudoku puzzle"),
		"",
		tr("Sudoku puzzles (*.sudoku)")
	);
	QFile file;
	file.setFileName( fileName );
	
	if( !file.open( QIODevice::WriteOnly | QIODevice::Text ) )
	{
		// error
		return;
	}
	QTextStream out( &file );
	QChar character;
	//Once the file is opened and accessible, we begin writing out the
	//puzzle’s contents. Each square is read. If a square is puzzle-
	//defined then a P and then the number is written out. If the square
	//is user-defined then a U and then the number is written out. If
	//the user has left a square blank then a U and X are written out to
	// indicate that it is empty user-defined square.
	for( unsigned int i = 0; i < 9; i++ )
	{
		for( unsigned int j = 0; j < 9; j++ )
		{
			if( puzzleBoard->puzzleBox( i, j )->isReadOnly() )
			{
				character = 'P';
				out << character;
				out << puzzleBoard->puzzleBox( i, j )->displayText();
			}
			else
			{
				character = 'U';
				out << character;
				if( puzzleBoard->puzzleBox( i, j )->displayText().size() < 1 )
				{
					character = 'X';
					out << character;
				}
				else
				{
					out << puzzleBoard->puzzleBox( i, j )->displayText();
				}
			}
		}
	}
}

//Eventually this function will solve the puzzle. For the moment, it
//only does two things. One, it reads the contents of the puzzle and
//stores all of the number values into the boxValue array. Two, it
//determines if the square is puzzle defined or user editable and
//stores that in the Boolean array. Your solver function will use
//these arrays to work its magic.
void MainWindow::slot_help_solve()
{
	for( unsigned int i = 0; i < 9; i++ )
	{
		for( unsigned int j = 0; j < 9; j++ )
		{
			puzzleDefined[i][j] = false;
		}
	}

	// This takes everything out of the user interface
	for( unsigned int i = 0; i < 9; i++ )
	{
		for( unsigned int j = 0; j < 9; j++ )
		{
			if( puzzleBoard->puzzleBox( i, j )->isReadOnly() )
			{
				puzzleDefined[i][j] = true;
				boxValue[i][j] = puzzleBoard->puzzleBox( i, j )->displayText().toUInt();
			}
			else
			{
				if( puzzleBoard->puzzleBox( i, j )->displayText().size() < 1 )
				{
					boxValue[i][j] = 0;
				}
				else
				{
					boxValue[i][j] = puzzleBoard->puzzleBox( i, j )->displayText().toUInt();
				}
			}
		}
	}
	///////////////////////////////////////////////////////////////////////
	// The Sudoku puzzle function goes below this comment
	newsolve(0,0);
	// The Sudoku puzzle function goes above this comment
	///////////////////////////////////////////////////////////////////////
	
	// This puts everything back into the user interface
	for( unsigned int i = 0; i < 9; i++ )
	{
		for( unsigned int j = 0; j < 9; j++ )
		{
			QString text;
			text.setNum( boxValue[i][j] );
			puzzleBoard->puzzleBox( i, j )->setText( text );
		}
	}
}


void MainWindow::newsolve( unsigned int i, unsigned int j )
{
	/*
	cerr<< i << "," << j <<"," << boxValue[i][j] <<endl;
	for( unsigned int s = 0; s <= 8 ; s++ )
	{
		for( unsigned int t=0; t <= 8; t++ )
		{
			if(t!=0)
			{
				cerr<< ",";
			}
			cerr << boxValue[s][t];
		}
		cerr<< endl;
	}
	cerr << endl;
	*/
	if( i<=8 && j<=8 )
	{
		if(puzzleDefined[i][j] == false)
		{

			do
			{
				//increment
				boxValue[i][j]++;
			}while(!checknum(i,j) && boxValue[i][j] < 10 );
		
		}
		
		if (puzzleDefined[i][j] == false && !checknum(i,j))
		{
			//backtrack
			boxValue[i][j] = 0;
			do 
			{
				if( j==0 )
				{
					j=8;
					i--;
				}
				else
				{
					j--;
				}
			}while(puzzleDefined[i][j] == true);
				
		}
		else
		{
			//increment
			if(j==8) 
			{
				j=0;
				i++;
			}
			else
			{
				j++;
			}
		}
		newsolve(i,j);
	}
}

void MainWindow::solve( unsigned int i, unsigned int j ,bool backtrack)
{
	for( ; i <= 8; i++ )
	{
		if(j==9)
		{
			j=0;
		}
		for( ; j <= 8; j++  )
		{
			
			if( puzzleDefined[i][j] == false)
			{
				while(!checknum(i,j) || backtrack == true)
				{
					backtrack = false ;
					if(boxValue[i][j] < 9)
					{
						boxValue[i][j]++;
					}
					else
					{
						do
						{
							boxValue[i][j] = 0;
						
							if(j==0 )
							{
								i--;
								j=8;
							}
							else
							{
								j--;
							}
						}while( puzzleDefined[i][j] == true  );
						backtrack = true ;
						solve(i,j,backtrack);
					}
				}
			}	
		}
	}
}

bool MainWindow:: checknum( unsigned int row, unsigned int collum)
{
	bool good = true;
	unsigned int row_start,row_end,collum_start,collum_end;
	
	
	
	//check row
	for( unsigned int i = 0; i <= 8; i++ )
	{
		if(boxValue[row][collum] == boxValue[i][collum] && row !=i )
		{
			good = false;
		}
	}
	
	//check collum
	for( unsigned int j = 0; j <= 8; j++ )
	{
		if(boxValue[row][collum] == boxValue[row][j] && collum !=j )
		{
			good = false;
		}	
	}
	
	
	//chek box
	if( row <= 2)
	{
		row_start = 0;
		row_end =2;
	}
	else if(3 <= row && row <= 5)
	{
		row_start = 3;
		row_end =5;
	}
	else 
	{
		row_start = 6;
		row_end =8;
	}
	
	if( collum <= 2)
	{
		collum_start =0;
		collum_end=2;
	}
	else if(3 <= collum &&  collum <= 5)
	{
		collum_start =3;
		collum_end=5;		
	}
	else 
	{
		collum_start = 6;
		collum_end = 8;
	}
	
	for( unsigned int s = row_start; s <= row_end ; s++ )
	{
		for( unsigned int t = collum_start; t <= collum_end; t++ )
		{
			if(boxValue[row][collum] == boxValue[s][t] && !(row == s && collum ==t) )
			{
				good = false;
			}
		}
	}
	
	if(boxValue[row][collum] < 1 || boxValue[row][collum] > 9)
	{
		good = false;
	}
	
	return good;
}
