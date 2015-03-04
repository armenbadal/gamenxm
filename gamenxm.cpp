#include "gamenxm.h"

/**/
GameNxM::GameNxM( unsigned int rw, unsigned int cl )
    : rows{rw}, columns{cl}
{
    reset();
}

/**/
void GameNxM::reset()
{
    // ամբողջ մատրիցի նախապատրաստում
    for( uint r = 0; r < rows + 2; ++r )
        matrix.push_back( QVector<int>(columns + 2, -1) );

    // rows x columns հատ թվեր
    int count = rows * columns;
    QVector<int> rnums;
    for( int i = 1; i < count; ++i )
        rnums.push_back(i);
    // թվերի խառնում
    --count;
    for( int i = 0; i < count; ++i ) {
        auto p0 = qrand() % count;
        auto p1 = qrand() % count;
        qSwap(rnums[p0], rnums[p1]);
    }
    // ինվերսիաների քանակի ստուգում
    int inv = 0;
    for( int i = 0; i < count - 1; ++i )
        for( int j = i + 1; j < count; ++ j )
            if( rnums[i] > rnums[j] ) ++inv;
    // եթե կենտ է, ապա ևս մի տրանսպոզիցիա
    if( inv % 2 == 1 ) {
        auto p0 = qrand() % count;
        auto p1 = qrand() % count;
        qSwap(rnums[p0], rnums[p1]);
    }
    rnums.push_back(0);

    // խաղադաշտի արժեքավորում
    int nx = 0;
    for( unsigned int r = 1; r <= rows; ++r )
        for( unsigned int c = 1; c <= columns; ++c )
            matrix[r][c] = rnums[nx++];

}

/**/
void GameNxM::step( unsigned int rw , unsigned int cl )
{
    if( matrix[rw-1][cl] == 0 )
        qSwap(matrix[rw][cl], matrix[rw-1][cl]);
    else if( matrix[rw+1][cl] == 0 )
        qSwap(matrix[rw][cl], matrix[rw+1][cl]);
    else if( matrix[rw][cl-1] == 0 )
        qSwap(matrix[rw][cl], matrix[rw][cl-1]);
    else if( matrix[rw][cl+1] == 0 )
        qSwap(matrix[rw][cl], matrix[rw][cl+1]);
}

/**/
int GameNxM::valueAt( unsigned int ro, unsigned int cl ) const
{
    return matrix.at(ro+1).at(cl+1);
}

