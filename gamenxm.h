#ifndef GAMENXM_H
#define GAMENXM_H

#include <QVector>

/**/
class GameNxM {
public:
    GameNxM( unsigned int rw, unsigned int cl );
    ~GameNxM();

    void step( unsigned int, unsigned int );
    int at( unsigned int, unsigned int ) const;

private:
    unsigned int rows = 0;
    unsigned int columns = 0;
    QVector<QVector<int>> matrix;
};

#endif // GAMENXM_H
