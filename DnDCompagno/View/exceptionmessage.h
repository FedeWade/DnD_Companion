#ifndef EXCEPTIONMESSAGE_H
#define EXCEPTIONMESSAGE_H
#include <QIcon>
#include <QMessageBox>
#include <QWidget>

class ExceptionMessage : public QMessageBox
{
public:
    ExceptionMessage(QWidget * = nullptr, const QString & = "Nessun messaggio da mostrare");
};

#endif // EXCEPTIONMESSAGE_H
