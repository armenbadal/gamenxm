#ifndef BOARD_H
#define BOARD_H

#include <QVector>
#include <QWidget>

class Tile;
class GameNxM;

/**/
class Board : public QWidget {
    Q_OBJECT

public:
    Board( unsigned int rw, unsigned int cl, QWidget* parent = nullptr );
    ~Board();

    void setModel( GameNxM* mo );

private:
    void updateLabels();

private:
    unsigned int rows = 0;
    unsigned int columns = 0;
    QVector<Tile*> tiles;

    GameNxM* model = nullptr;

signals:

private slots:
    void clickedOnTile( unsigned int r, unsigned int c );
};

#endif // BOARD_H
