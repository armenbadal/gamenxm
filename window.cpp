
#include <QAction>
#include <QIcon>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QMessageBox>

#include "window.h"

#include "board.h"
#include "gamenxm.h"

/**/
Window::Window( QWidget* parent )
    : QMainWindow(parent)
{
    setWindowTitle( tr("Game NxM") );

    board = new Board(4, 4, this);
    engine = new GameNxM(4, 4);
    board->setModel(engine);

    setCentralWidget(board);

    createActions();
    createMenu();
    createToolBar();
    createStatusBar();

    connect(board, SIGNAL(updateStatus()), this, SLOT(showStatus()));
}

/**/
void Window::createActions()
{
    actNew = new QAction( QIcon(":/icons/puzzle.png"), tr("New"), this);
    actNew->setShortcuts(QKeySequence::New);
    connect(actNew, SIGNAL(triggered()), this, SLOT(newGame()));

    actEnd = new QAction( QIcon(":/icons/cross.png"), tr("Exit"), this);
    actEnd->setShortcut(QKeySequence::Quit);
    connect(actEnd, SIGNAL(triggered()), this, SLOT(close()));

    actAbout = new QAction( QIcon(":/icons/question.png"), tr("About"), this);
    connect(actAbout, SIGNAL(triggered()), this, SLOT(aboutGame()));
}

/**/
void Window::createMenu()
{
    mainMenu = new QMenuBar(this);

    mnuGame = new QMenu(tr("Game"), mainMenu);
    mainMenu->addAction(mnuGame->menuAction());
    mnuGame->addAction(actNew);
    mnuGame->addSeparator();
    mnuGame->addAction(actEnd);

    mnuHelp = new QMenu(tr("Help"), mainMenu);
    mainMenu->addAction(mnuHelp->menuAction());
    mnuHelp->addAction(actAbout);

    setMenuBar(mainMenu);
}

/**/
void Window::createToolBar()
{
    mainToolBar = addToolBar("Main");

    mainToolBar->addAction(actNew);
    mainToolBar->addSeparator();
    mainToolBar->addAction(actAbout);
}

/**/
void Window::createStatusBar()
{
    statusBar = new QStatusBar(this);
    setStatusBar(statusBar);
    showStatus();
}

/**/
void Window::newGame()
{
    if( engine != nullptr ) {
        engine->reset();
        board->setModel(engine);
        showStatus();
    }
}

/**/
void Window::showStatus()
{
    auto sp = engine->getSteps();
    statusBar->showMessage(tr("Step: ") + QString::number(sp));
    if( engine->isOver() )
        QMessageBox::information(this, tr("Game N×M"), tr("You win at step ") + QString::number(sp));
}

/**/
void Window::aboutGame()
{
    QString message = tr("<b>Game N×M</b> - extended version of <i>Game 15</i><br/>");
    message += tr("Designed and implemented for educational purposes.<br/><br/>2015");
    QMessageBox::about(this, "Game N×M", message);
}
