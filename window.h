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
    ~Window();

private:
    Board* board = nullptr;
    GameNxM* engine = nullptr;

signals:

public slots:
};

#endif // WINDOW_H
