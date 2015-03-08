#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>

class QMenuBar;
class QMenu;
class QAction;

class Board;
class GameNxM;

/**/
class Window : public QMainWindow {
    Q_OBJECT

public:
    explicit Window( QWidget* parent = nullptr );

private:
    void createActions();
    void createMenu();

private slots:
    void newGame();
    void aboutGame();

private:
    Board* board = nullptr;
    GameNxM* engine = nullptr;

    QMenuBar* mainMenu = nullptr;
    QMenu* mnuGame = nullptr;
    QMenu* mnuHelp = nullptr;

    QAction* actNew = nullptr;
    QAction* actEnd = nullptr;
    QAction* actAbout = nullptr;
};

#endif // WINDOW_H

