#include "tile.h"

/**/
Tile::Tile( unsigned int rw, unsigned int cl, QWidget* parent )
    : QLabel(parent)
{
    row = rw;
    column = cl;

    setMinimumSize(QSize(64, 64));

    QFont font;
    font.setPointSize(18);
    font.setBold(true);
    setFont(font);

    setAlignment(Qt::AlignCenter);

    setFrameShape(QFrame::StyledPanel);
    setFrameShadow(QFrame::Raised);
}

/**/
void Tile::mousePressEvent( QMouseEvent* event )
{
    Q_UNUSED(event)
    emit clicked(row, column);
}

