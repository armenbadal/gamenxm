
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>

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

    createActions();
    createMenu();
}

/**/
void Window::createActions()
{
    actNew = new QAction("Նոր", this);
    actNew->setShortcuts(QKeySequence::New);
    connect(actNew, SIGNAL(triggered()), this, SLOT(newGame()));

    actEnd = new QAction("Ելք", this);
    actEnd->setShortcut(QKeySequence::Quit);
    connect(actEnd, SIGNAL(triggered()), this, SLOT(close()));

    actAbout = new QAction("Խաղ N×M", this);
    connect(actAbout, SIGNAL(triggered()), this, SLOT(aboutGame()));
}

/**/
void Window::createMenu()
{
    mainMenu = new QMenuBar(this);

    mnuGame = new QMenu("Խաղ", mainMenu);
    mainMenu->addAction(mnuGame->menuAction());
    mnuGame->addAction(actNew);
    mnuGame->addSeparator();
    mnuGame->addAction(actEnd);

    mnuHelp = new QMenu("Հուշում", mainMenu);
    mainMenu->addAction(mnuHelp->menuAction());
    mnuHelp->addAction(actAbout);

    setMenuBar(mainMenu);
}

/**/
void Window::newGame()
{
    if( engine != nullptr ) {
        engine->reset();
        board->setModel(engine);
    }
}

/**/
void Window::aboutGame()
{
    QMessageBox::about(this, "Խաղ N×M", "<b>Խաղ N×M</b> - 2015");
}
