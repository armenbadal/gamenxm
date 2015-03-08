#ifndef TILE_H
#define TILE_H

#include <QLabel>
#include <QWidget>

class QMouseEvent;

/** @brief Խաղաքար */
class Tile : public QLabel {
    Q_OBJECT

public:
    Tile( unsigned int rw, unsigned int cl, QWidget* parent = nullptr );

private:
    /// @brief տողը
    unsigned int row;
    /// @brief սյունը
    unsigned int column;

signals:
    void clicked( unsigned int, unsigned int );

protected:
    void mousePressEvent( QMouseEvent* event ) override;
};

#endif // TILE_H

