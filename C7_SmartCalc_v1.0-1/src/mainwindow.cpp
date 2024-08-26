#include "mainwindow.h"

#include "./ui_mainwindow.h"

int flag_input = 0;
int flag_change_x = 0;
int flag_change_xmin = 0;
int flag_change_xmax = 0;
int flag_change_ymin = 0;
int flag_change_ymax = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_point, SIGNAL(clicked()), this, SLOT(input_char()));

  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_sum, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(input_char()));

  connect(ui->pushButton_open_bracket, SIGNAL(clicked()), this,
          SLOT(input_char()));
  connect(ui->pushButton_close_bracket, SIGNAL(clicked()), this,
          SLOT(input_char()));

  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(input_char()));

  connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(delete_all()));
  connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(equal()));
  connect(ui->pushButton_graphic, SIGNAL(clicked()), this, SLOT(get_graphic()));

  // connect(ui->line_edit, SIGNAL(textChanged(QString)), this,
  // SLOT(change_x())); connect(ui->line_edit_xmin,
  // SIGNAL(textChanged(QString)), this, SLOT(change_xmin()));
  // connect(ui->line_edit_xmax, SIGNAL(textChanged(QString)), this,
  // SLOT(change_xmax())); connect(ui->line_edit_ymin,
  // SIGNAL(textChanged(QString)), this, SLOT(change_ymin()));
  // connect(ui->line_edit_ymax, SIGNAL(textChanged(QString)), this,
  // SLOT(change_ymax()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::input_char() {
  if (flag_input == 0) clear();
  flag_input = 1;
  QPushButton *button =
      (QPushButton *)sender();  // получить ту кнопку, на которую нажали
  QString new_label = ui->result_show->text() + button->text();
  ui->result_show->setText(new_label);
}

void MainWindow::input_func() {
  if (flag_input == 0) clear();
  flag_input = 1;
  QPushButton *button = (QPushButton *)sender();
  QString new_label = ui->result_show->text() + button->text() + '(';
  ui->result_show->setText(new_label);
}

void MainWindow::equal() {
  flag_input = 0;
  flag_change_x = 0;
  double result = 0;
  char str[3000] = {0};
  QPushButton *button = (QPushButton *)sender();
  QString label = ui->result_show->text() + button->text();
  QByteArray arr = label.toLocal8Bit();
  memcpy(str, arr.data(), arr.size());
  QString x = ui->line_edit->text();
  QByteArray arr_x = x.toLocal8Bit();
  if (arr_x.size() == 0) {
    ui->result_show->setText("Enter value x");
    flag_input = 0;
  } else {
    char x_value[3000] = {0};
    memcpy(x_value, arr_x.data(), arr_x.size());
    if (s21_smart_calc(str, &result, x_value) == 0) {
      QString res = QString::number(result, 'g', 11);
      ui->result_show->setText(res);
    } else {
      if (isnan(result)) {
        ui->result_show->setText("nan");
        flag_input = 0;
      } else {
        ui->result_show->setText("Invalid input");
        flag_input = 0;
      }
    }
  }
}

void MainWindow::get_graphic() {
  double x_min = ui->line_edit_xmin->text().toDouble();
  double x_max = ui->line_edit_xmax->text().toDouble();
  double y_min = ui->line_edit_ymin->text().toDouble();
  double y_max = ui->line_edit_ymax->text().toDouble();
  char str[3000] = {0};
  char x_value[3000] = "0";
  QString label = ui->result_show->text() + '=';
  QByteArray arr = label.toLocal8Bit();
  memcpy(str, arr.data(), arr.size());
  char tmp_str[3000] = {0};
  memcpy(tmp_str, str, 3000);
  char output_string[255][3000] = {0};
  int count = 0;
  if (x_min < -1000000 || x_max > 1000000 || y_min < -1000000 ||
      y_max > 1000000 || x_min >= x_max || y_min >= y_max ||
      s21_check_string(tmp_str, x_value) == 1 ||
      s21_reverse_polish_notation(tmp_str, output_string, &count) == 1) {
    ui->result_show->setText("Invalid input");
  } else {
    form.Graph(str, x_min, x_max, y_min, y_max);
    form.setWindowTitle("Graphic");
    form.show();
  }
  flag_change_xmin = 0;
  flag_change_xmax = 0;
  flag_change_ymin = 0;
  flag_change_ymax = 0;
  flag_input = 0;
}

void MainWindow::change_x() {
  if (flag_change_x == 0) {
    QString newLabel;
    ui->line_edit->setText(newLabel);
  }
  flag_change_x = 1;
}

void MainWindow::change_xmin() {
  if (flag_change_xmin == 0) {
    QString newLabel;
    ui->line_edit_xmin->setText(newLabel);
  }
  flag_change_xmin = 1;
}

void MainWindow::change_xmax() {
  if (flag_change_xmax == 0) {
    QString newLabel;
    ui->line_edit_xmax->setText(newLabel);
  }
  flag_change_xmax = 1;
}

void MainWindow::change_ymin() {
  if (flag_change_ymin == 0) {
    QString newLabel;
    ui->line_edit_ymin->setText(newLabel);
  }
  flag_change_ymin = 1;
}

void MainWindow::change_ymax() {
  if (flag_change_ymax == 0) {
    QString newLabel;
    ui->line_edit_ymax->setText(newLabel);
  }
  flag_change_ymax = 1;
}

void MainWindow::delete_all() {
  QString newLabel = "0";
  ui->result_show->setText(newLabel);
  flag_input = 0;
}

void MainWindow::clear() {
  QString newLabel;
  ui->result_show->setText(newLabel);
}