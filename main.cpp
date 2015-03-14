
#include <QApplication>
#include <QTranslator>

#include "window.h"

/**/
int main( int argc, char* argv[] )
{
    QApplication app(argc, argv);

    QTranslator translator;
    translator.load( "gamenxm_hy" );
    app.installTranslator( &translator );

    Window win;
    win.show();

    return app.exec();
}
