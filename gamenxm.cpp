
#include <algorithm>
#include <numeric>
#include <random>

#include "gamenxm.h"

/**/
GameNxM::GameNxM( int rw, int cl )
    : rows{rw}, columns{cl}
{
    reset();
}

/**/
void GameNxM::reset()
{
    // ամբողջ մատրիցի նախապատրաստում
    matrix.clear();
    for( int r = 0; r < rows + 2; ++r )
        matrix.push_back( QVector<int>(columns + 2, -1) );

    // rows x columns հատ թվեր
    int count = rows * columns - 1;
    QVector<int> rnums(count);
    std::iota(rnums.begin(), rnums.end(), 1);

    // թվերի խառնում
    std::random_device rd{};
    auto re = std::default_random_engine{rd()};
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
    for( int r = 1; r <= rows; ++r )
        for( int c = 1; c <= columns; ++c )
            matrix[r][c] = rnums[nx++];

    // ոայլերի քանակը զրո է
    steps = 0;
}

/**/
void GameNxM::oneStep( int rw , int cl )
{
    if( matrix[rw-1][cl] == 0 ) {
        qSwap(matrix[rw][cl], matrix[rw-1][cl]);
        ++steps;
    }
    else if( matrix[rw+1][cl] == 0 ) {
        qSwap(matrix[rw][cl], matrix[rw+1][cl]);
        ++steps;
    }
    else if( matrix[rw][cl-1] == 0 ) {
        qSwap(matrix[rw][cl], matrix[rw][cl-1]);
        ++steps;
    }
    else if( matrix[rw][cl+1] == 0 ) {
        qSwap(matrix[rw][cl], matrix[rw][cl+1]);
        ++steps;
    }
}

/**/
bool GameNxM::isOver() const
{
    for( int i = 1; i < rows * columns; ++i ) {
        auto r = (i - 1) / columns + 1;
        auto c = (i - 1) % columns + 1;
        if( matrix[r][c] != i ) return false;
    }
    return true;
}

/**/
int GameNxM::valueAt( int ro, int cl ) const
{
    return matrix.at(ro+1).at(cl+1);
}

