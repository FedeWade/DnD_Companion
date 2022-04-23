#ifndef SPELLSSLOTSBOX_H
#define SPELLSSLOTSBOX_H

#include "Model/modello.h"
#include "View/slot.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

class SpellsSlotsBox : public QWidget
{
    Q_OBJECT
public:
    SpellsSlotsBox(QWidget *parent = nullptr, Modello *model = nullptr);
    void update();

public slots:
    void editClicked();
    void saveClicked();
    void applySpellsListChanges();

private:
    Modello *Model;

    QPushButton *Edit;
    QPushButton *Save;

    QGridLayout *Grid;
    QTextEdit *SpellsDesc;

    Slot *Lvl1;
    Slot *Lvl2;
    Slot *Lvl3;
    Slot *Lvl4;
    Slot *Lvl5;
    Slot *Lvl6;
    Slot *Lvl7;
    Slot *Lvl8;
    Slot *Lvl9;

    void setStyle();
};

#endif // SPELLSSLOTSBOX_H
