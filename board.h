#ifndef BOARD_H
#define BOARD_H

#include <QVector>
#include <QWidget>

class Tile;
class GameNxM;

/** @brief Խաղադաշտը */
class Board : public QWidget {
    Q_OBJECT

public:
    Board( unsigned int, unsigned int, QWidget* = nullptr );

    void setModel( GameNxM* );

private:
	/** @brief Թարմացնել խաղաքարերի թվերը */
    void updateLabels();

private:
    /// @brief տողերի քանակը
    unsigned int rows = 0;
    /// @brief սյուների քանակը
    unsigned int columns = 0;
    /// @brief խաղաքարերի ցուցակ
    QVector<Tile*> tiles;

    /// @brief ցուցիչ խաղի մոդելին
    GameNxM* model = nullptr;

signals:
    void updateStatus();

private slots:
    /** @brief Խաղաքարի ընտրության մշակում */
    void clickedOnTile( unsigned int, unsigned int );
};

#endif // BOARD_H
