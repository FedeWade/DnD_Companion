#ifndef SAVINGTHROW_H
#define SAVINGTHROW_H

#include "View/skill.h"
#include <QWidget>

class SavingThrow : public Skill
{ //eredito da Skill è uguale, cambio solo la funzione update
public:
    SavingThrow(QWidget *parent = nullptr, Modello *modello = nullptr, const std::string &name = "noname");

    void update(); //overloading di Skill::update()
};

#endif // SAVINGTHROW_H
