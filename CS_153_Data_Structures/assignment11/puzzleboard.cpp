#include "puzzleBoard.h"

//////////////////////////////////////////////////////////////////////
/// @file puzzleboard.cpp
/// @author James Anderson  Section A
/// @brief main file for sudoku sover for assignment 11
////////////////////////////////////////////////////////////////////// 

PuzzleBoard::PuzzleBoard()
{
	m_puzzleBox = new QLineEdit**[9];

	for( unsigned int i = 0; i < 9; i++ )
	{
		m_puzzleBox[i] = new QLineEdit*[9];

		for( unsigned int j = 0; j < 9; j++ )
		{
			m_puzzleBox[i][j] = new QLineEdit();
			if
			(
				(i < 3 && j > 2 && j < 6) ||
				(i > 2 && i < 6 && j < 3) ||
				(i > 2 && i < 6 && j > 5) ||
				(i > 5 && j > 2 && j < 6)
			)
			{
				QPalette p = m_puzzleBox[i][j]->palette();
				p.setColor
				(
					QPalette::Active,
					static_cast<QPalette::ColorRole>(9),
					QColor( Qt::lightGray )
				);
				m_puzzleBox[i][j]->setPalette( p );
			}
			unsigned int box_size = 50;
			m_puzzleBox[i][j]->setMaximumHeight( box_size );
			m_puzzleBox[i][j]->setMinimumHeight( box_size );
			m_puzzleBox[i][j]->setMaximumWidth( box_size );
			m_puzzleBox[i][j]->setMinimumWidth( box_size );
			m_puzzleBox[i][j]->setMaxLength( 1 );
			m_puzzleBox[i][j]->setFont(QFont("courier",40,QFont::Bold));
			m_puzzleBox[i][j]->setAlignment( Qt::AlignCenter );
		}		
	}
}

//This simply returns a particular puzzle square
QLineEdit * PuzzleBoard::puzzleBox( unsigned int i, unsigned int j )
{
	return m_puzzleBox[i][j];
}
