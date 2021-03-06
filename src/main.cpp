#include "stopwatchviewer.h"

#include <iostream>
#include <string>

#include <QtGui>
#include <QApplication>

#include "ncurses_ui.h"

int main(int argc, char *argv[])
{
    bool useCurses = false;
    if (argc >= 2) {
        for (int i = 0; i < argc; ++i) {
            std::string arg(argv[i]);
            if (arg.compare("-n")) {
                useCurses = true;
                break;
            }
        }
    }

    if (useCurses) {
        return NCursesStopwatchViewer::run();
    } else {
        QApplication a(argc, argv);
        StopwatchViewer w;
        w.show();
        return a.exec();
    }
}
