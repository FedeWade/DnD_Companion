#ifndef DESCRIPTIONBOX_H
#define DESCRIPTIONBOX_H

#include "Model/modello.h"
#include <QGroupBox>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

class DescriptionBox : public QWidget
{
    Q_OBJECT
public:
    DescriptionBox(QWidget *parent = nullptr, Modello *model = nullptr);
    void update();

public slots:
    void applyDescriptionChanges();
    void applyTraitsChanges();

private:
    Modello *Model;

    QTextEdit *Description;
    QTextEdit *Traits;
};

#endif // DESCRIPTIONBOX_H
