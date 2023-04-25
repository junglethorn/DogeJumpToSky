#-------------------------------------------------
#
# Project created by QtCreator 2022-06-26T17:14:49
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jump_zx
TEMPLATE = app


SOURCES += main.cpp\
        mainscene.cpp \
    acboard.cpp \
    herodoge.cpp \
    map.cpp \
    waboard.cpp \
    board.cpp \
    board_piece.cpp \
    pass_board.cpp \
    ce_board.cpp \
    main_menu.cpp \
    end_window.cpp \
    boss.cpp \
    barrier.cpp \
    monster.cpp \
    spring.cpp

HEADERS  += mainscene.h \
    config.h \
    herodoge.h \
    map.h \
    waboard.h \
    board.h \
    make_board.h \
    board_piece.h \
    pass_board.h \
    acboard.h \
    ce_board.h \
    main_menu.h \
    end_window.h \
    boss.h \
    barrier.h \
    fadein_animation.h \
    monster.h \
    make_monster.h \
    spring.h

FORMS    += mainscene.ui \
    main_menu.ui \
    end_window.ui

DISTFILES +=

RESOURCES += \
    res.qrc
