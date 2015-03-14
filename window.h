#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>

class QAction;
class QMenuBar;
class QMenu;
class QStatusBar;
class QToolBar;

class Board;
class GameNxM;

/** @brief Ծրագրի գլխավոր պատուհանը */
class Window : public QMainWindow {
    Q_OBJECT

public:
    explicit Window( QWidget* parent = nullptr );

private:
    /** @brief Գործողությունների ստեղծումը */
    void createActions();
    /** @brief Մենյուների ստեղծումը */
    void createMenu();
    /** @brief Գործիքների տողի ստեղծումը */
    void createToolBar();
    /** @brief Ստատուսի տողի ստեղծումը */
    void createStatusBar();

private slots:
    /** @brief Նոր խաղ */
    void newGame();
    /** @brief Տեղեկություն ծրագրի մասին */
    void aboutGame();
    /** @brief Քայլերի քանակը և խաղի ավարտը */
    void showStatus();

private:
    /// @brief Խաղատախտակը
    Board* board = nullptr;
    /// @brief Խաղի տրամաբանությունը
    GameNxM* engine = nullptr;

    /// @brief Մենյուների տողը
    QMenuBar* mainMenu = nullptr;
    /// @brief "Խաղ" մենյուն
    QMenu* mnuGame = nullptr;
    /// @brief "Հուշում" մենյուն
    QMenu* mnuHelp = nullptr;

    /// @brief Գործիքների տողը
    QToolBar* mainToolBar = nullptr;

    /// @brief Ստատուսի տողը
    QStatusBar* statusBar = nullptr;

    /// @brief "նոր խաղ" գործողությունը
    QAction* actNew = nullptr;
    /// @brief "ծրագրի ավարտ" գործողությունը
    QAction* actEnd = nullptr;
    /// @brief "տեղեկություն" գործողությունը
    QAction* actAbout = nullptr;
};

#endif // WINDOW_H
