#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <form.h>

#include <QMainWindow>

extern "C" {
#include "s21_smart_calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  Form form;

 private slots:
  void input_char();
  void input_func();
  void delete_all();
  void equal();
  void get_graphic();
  void change_x();
  void change_xmin();
  void change_xmax();
  void change_ymin();
  void change_ymax();
  void clear();
};

#endif  // MAINWINDOW_H
