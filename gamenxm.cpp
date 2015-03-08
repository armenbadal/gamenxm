
#include <algorithm>
#include <numeric>
#include <random>

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
    matrix.clear();
    for( uint r = 0; r < rows + 2; ++r )
        matrix.push_back( QVector<int>(columns + 2, -1) );

    // rows x columns հատ թվեր
    int count = rows * columns - 1;
    QVector<int> rnums(count);
    std::iota(rnums.begin(), rnums.end(), 1);

    // թվերի խառնում
    auto re = std::default_random_engine{};
    std::shuffle(rnums.begin(), rnums.end(), re);

    // ինվերսիաների քանակի ստուգում
    int inv = 0;
    for( int i = 0; i < count - 1; ++i )
        for( int j = i + 1; j < count; ++ j )
            if( rnums[i] > rnums[j] ) ++inv;

    // եթե կենտ է, ապա ևս մի տրանսպոզիցիա
    if( inv % 2 == 1 ) qSwap(rnums[0], rnums[1]);

    // վերջին զրոն
    rnums.push_back(0);

    // խաղադաշտի արժեքավորում պատահական դասավորությամբ
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
bool GameNxM::gameOver() const
{
    for( int i = 0; i < rows * columns; ++i ) {
        auto r = i / rows + 1;
        auto c = i % rows;
        if( matrix[r][c] != i ) return false; // TODO: Check this
    }
    return true;
}

/**/
int GameNxM::valueAt( unsigned int ro, unsigned int cl ) const
{
    return matrix.at(ro+1).at(cl+1);
}

