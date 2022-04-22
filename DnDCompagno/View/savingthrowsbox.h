#ifndef SAVINGTHROWSBOX_H
#define SAVINGTHROWSBOX_H

#include "Model/modello.h"
#include "View/savingthrow.h"
#include "skill.h"
#include <QGroupBox>
#include <QPushButton>
#include <QWidget>

class SavingThrowsBox : public QWidget
{
    Q_OBJECT
public:
    SavingThrowsBox(QWidget *parent = nullptr, Modello *modello = nullptr);
    void setStyle();
    void update();

public slots:
    void editClicked();
    void saveClicked();

private:
    Modello *Model;

    QVBoxLayout *grouplayout;
    QPushButton *Edit;
    QPushButton *Save;

    SavingThrow *Forza;
    SavingThrow *Destrezza;
    SavingThrow *Costituzione;
    SavingThrow *Intelligenza;
    SavingThrow *Saggezza;
    SavingThrow *Carisma;
};

#endif // SAVINGTHROWSBOX_H
