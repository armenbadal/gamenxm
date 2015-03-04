
#include "window.h"

#include "board.h"
#include "gamenxm.h"

/**/
Window::Window( QWidget* parent )
    : QMainWindow(parent)
{
    setWindowTitle( "Game NxM");

    board = new Board(4, 4, this);
    engine = new GameNxM(4, 4);
    board->setModel(engine);

    setCentralWidget(board);
}

/**/
Window::~Window()
{}

