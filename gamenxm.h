#ifndef GAMENXM_H
#define GAMENXM_H

#include <QVector>

/* Խաղի տրամաբանությունը */
class GameNxM {
public:
    /** @brief Կոնստրուկտոր
     *
     * @param rw տողերի քանակը
     * @param cl սյուների քանակը
     */
    GameNxM( unsigned int rw, unsigned int cl );

    /** @brief Խաղի նախապատրաստում */
    void reset();

    /** @brief Մեկ քայլի կատարում
     *
     * @param rw տեղաշարժվող խաղաքարի տողի համարը
     * @param cl տեղաշարժվող խաղաքարի սյան համարը
     */
    void step( unsigned int rw, unsigned int cl );

    /** @brief Մատրիցի ծրված բջջի արժեքը
     *
     * @param ro տողի համարը
     * @param cl սյան համարը
     */
    int valueAt( unsigned int ro, unsigned int cl ) const;

private:
    /// @brief Տողերի քանակը
    unsigned int rows = 0;
    /// @brief Սյուների քանակը
    unsigned int columns = 0;
    /// @brief Թվերի մատրիցը
    QVector<QVector<int>> matrix;
};

#endif // GAMENXM_H
