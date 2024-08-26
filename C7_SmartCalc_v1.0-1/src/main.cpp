#include <QApplication>
#include <QLabel>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  setlocale(LC_NUMERIC, "C");
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("Calc");
  w.show();
  return a.exec();
}
