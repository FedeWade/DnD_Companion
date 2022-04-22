#ifndef SLOT_H
#define SLOT_H

#include "Model/modello.h"
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

class Slot : public QWidget
{
    Q_OBJECT
public:
    Slot(QWidget *parent = nullptr, Modello *model = nullptr, unsigned int lvl = 1);
    void update();
    void makeEditable();
    void makeUneditable();
    void applyChanges();

private:
    Modello *Model;
    unsigned int Lvl;
    QSpinBox *Spells;
};

#endif // SLOT_H
