#ifndef MAIN_WINDOW_DIALOG_HXX
#define MAIN_WINDOW_DIALOG_HXX

#include <QMainWindow>

#include "source/hotkey_recorder_widget.hpp"
#include "source/keyboard_modifier_list_widget.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

protected:
    Ui::MainWindow* ui;
    HotkeyRecorderWidget hotkeyRecorder;
    KbModifierListWidget kbModifierListWidgetRecordedHotkeyModifiers;

public:
    MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow() override;
};

#endif // MAIN_WINDOW_DIALOG_HXX
