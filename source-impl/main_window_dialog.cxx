#include "main_window_dialog.hxx"
#include "ui_main_window_dialog.h"

MainWindow::MainWindow(QWidget* parent)
    :
      QMainWindow                                 { parent },
      ui 						                  { new Ui::MainWindow },
      kbModifierListWidgetRecordedHotkeyModifiers { this }
{
    ui->setupUi(this);

    setWindowFlags(
                Qt::Dialog
                | Qt::CustomizeWindowHint
                | Qt::WindowTitleHint
                | Qt::WindowCloseButtonHint
                );

    kbModifierListWidgetRecordedHotkeyModifiers.setMinimumWidth(90);
    kbModifierListWidgetRecordedHotkeyModifiers.addItem("Modifiers");
    kbModifierListWidgetRecordedHotkeyModifiers.AddItemsFromBitmask(WINMOD_ALT | WINMOD_CONTROL | WINMOD_SHIFT | WINMOD_WIN);
    ui->horizontalLayoutHotkeyRecorderRecordedHotkey->insertWidget(0, &kbModifierListWidgetRecordedHotkeyModifiers);

    ui->verticalLayoutHotkeyRecorder->addWidget(&hotkeyRecorder);
    hotkeyRecorder.StartRecording();

    connect(&hotkeyRecorder, &HotkeyRecorderWidget::HotkeyRecorded, [this](HotkeyRecorderWidget::Hotkey hotkey) -> void {
        ui->lineEditRecordedHotkeyVkid->setText(QString::number(hotkey.Vkid));
        kbModifierListWidgetRecordedHotkeyModifiers.SetModifierCheckStateFromBitmask(hotkey.Modifiers);
    });
}

MainWindow::~MainWindow() {
    hotkeyRecorder.StopRecording();
    delete ui;
}

