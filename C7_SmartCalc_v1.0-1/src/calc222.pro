QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    form.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    s21_check_string.c \
    s21_reverse_polish_notation.c \
    s21_calculation_expressions.c \
    s21_operation_priority.c \
    s21_stack_string.c \
    s21_is_char_in_str.c \
    s21_smart_calc.c \
    s21_stack_number.c \

HEADERS += \
    form.h \
    mainwindow.h \
    qcustomplot.h \
    s21_smart_calc.h

FORMS += \
    form.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
