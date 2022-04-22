#include "exceptionmessage.h"

ExceptionMessage::ExceptionMessage(QWidget *parent, const QString &msg) : QMessageBox(parent)
{
    setText(msg);
    setWindowIcon(QIcon(":/Resources/Warning.svg"));
    setWindowTitle("Attenzione!");
}
