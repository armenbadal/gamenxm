#ifndef GAMENXM_H
#define GAMENXM_H

#include <QVector>

/** @brief Խաղի տրամաբանությունը */
class GameNxM {
public:
    /** @brief Կոնստրուկտոր
     *
     * @param rw տողերի քանակը
     * @param cl սյուների քանակը
     */
    GameNxM( int rw, int cl );

    /** @brief Խաղի նախապատրաստում */
    void reset();

    /** @brief Մեկ քայլի կատարում
     *
     * @param rw տեղաշարժվող խաղաքարի տողի համարը
     * @param cl տեղաշարժվող խաղաքարի սյան համարը
     */
    void oneStep( int rw, int cl );

    /** @brief Խաղի ավարտված լինելը */
    bool gameOver() const;

    /** @brief Մատրիցի ծրված բջջի արժեքը
     *
     * @param ro տողի համարը
     * @param cl սյան համարը
     */
    int valueAt( int ro, int cl ) const;

private:
    /// @brief Տողերի քանակը
    int rows = 0;
    /// @brief Սյուների քանակը
    int columns = 0;
    /// @brief Թվերի մատրիցը
    QVector<QVector<int>> matrix;

    /// @brief Քայլերի քանակ
    int steps = 0;
};

#endif // GAMENXM_H
