#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>

class Board;
class GameNxM;

/**/
class Window : public QMainWindow {
    Q_OBJECT

public:
    explicit Window( QWidget* parent = nullptr );

private:
    Board* board = nullptr;
    GameNxM* engine = nullptr;
};

#endif // WINDOW_H

