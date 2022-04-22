#ifndef SPELLSBOX_H
#define SPELLSBOX_H

#include "Model/modello.h"
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

class SpellsBox : public QWidget
{
    Q_OBJECT
public:
    SpellsBox(QWidget *parent = nullptr, Modello *model = nullptr);
    void update();

private:
    Modello *Model;

    QLineEdit *Stat;
    QSpinBox *CD;
    QSpinBox *SpellAttackBonus;

    void setStyle();

signals:
};

#endif // SPELLSBOX_H
