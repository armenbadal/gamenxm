#ifndef TILE_H
#define TILE_H

#include <QLabel>
#include <QWidget>

class QMouseEvent;

/**/
class Tile : public QLabel {
    Q_OBJECT

public:
    Tile( unsigned int rw, unsigned int cl, QWidget* parent = nullptr );
    ~Tile();

private:
    unsigned int row;
    unsigned int column;

signals:
    void clicked( unsigned int, unsigned int );

protected:
    void mousePressEvent( QMouseEvent* event ) override;
};

#endif // TILE_H
