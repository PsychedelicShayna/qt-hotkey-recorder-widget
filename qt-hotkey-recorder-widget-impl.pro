QT += core gui widgets
CONFIG += c++17

LIBS += -lUser32

SOURCES += \
    source-impl/main.cpp \
    source-impl/main_window_dialog.cxx \
    source/hotkey_recorder_widget.cpp \
    source/keyboard_modifier_list_widget.cpp

HEADERS += \
    source-impl/main_window_dialog.hxx \
    source/hotkey_recorder_widget.hpp \
    source/keyboard_modifier_list_widget.hpp

FORMS += \
    source-impl/main_window_dialog.ui
