#ifndef HEALTHBOX_H
#define HEALTHBOX_H

#include "Model/modello.h"
#include <QCheckBox>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QWidget>

class HealthBox : public QWidget
{
    Q_OBJECT
public:
    HealthBox(QWidget *parent = nullptr, Modello *modello = nullptr);

    void update();
public slots:
    void editClicked();
    void saveClicked();

    void add1hp();
    void add5hp();
    void remove1hp();
    void remove5hp();
    void applyCurrentHPChanges(int);

private:
    Modello *Model;

    QPushButton *Edit;
    QPushButton *Save;

    QPushButton *Plus1;
    QPushButton *Plus5;
    QPushButton *Minus1;
    QPushButton *Minus5;

    QSpinBox *CurrentHP;
    QSpinBox *MaxHP;

    QSpinBox *HitDice;

    void setStyle();
};

#endif // HEALTHBOX_H
