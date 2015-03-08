
#include <QGridLayout>

#include "board.h"
#include "tile.h"
#include "gamenxm.h"

/**/
Board::Board( unsigned int rw, unsigned int cl, QWidget* parent )
    : QWidget(parent)
{
    rows = rw;
    columns = cl;

    auto baseGrid = new QGridLayout(this);
    baseGrid->setSpacing(4);
    baseGrid->setContentsMargins(4, 4, 4, 4);

    for( unsigned int r = 0; r < rows; ++r )
        for( unsigned int c = 0; c < columns; ++c ) {
            auto atile = new Tile(r+1, c+1, this);
            baseGrid->addWidget(atile, r, c);
            connect(atile, SIGNAL(clicked(unsigned int,unsigned int)),
                    this, SLOT(clickedOnTile(unsigned int,unsigned int)));
            tiles.push_back(atile);
        }
}

/**/
void Board::setModel( GameNxM* mo )
{
    model = mo;
    updateLabels();
}

/**/
void Board::updateLabels()
{
    if( model != nullptr ) {
        for( size_t r = 0; r < rows; ++r )
            for( size_t c = 0; c < columns; ++c ) {
                auto mk = model->valueAt(r, c);
                auto sk = mk == 0 ? QString{""} : QString::number(mk);
                tiles[r * columns + c]->setText(sk);
            }
    }
}

/**/
void Board::clickedOnTile( unsigned int r, unsigned int c )
{
    model->oneStep(r, c);
    updateLabels();
}

