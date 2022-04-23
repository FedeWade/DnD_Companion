#ifndef SKILLSBOX_H
#define SKILLSBOX_H

#include "Model/modello.h"
#include "exceptionmessage.h"
#include "skill.h"
#include <QGroupBox>
#include <QIcon>
#include <QPushButton>
#include <QWidget>

class SkillsBox : public QWidget
{
    Q_OBJECT
public:
    SkillsBox(QWidget *parent = nullptr, Modello *modello = nullptr);
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

    Skill *Acrobazia;
    Skill *AddestrareAnimali;
    Skill *Arcano;
    Skill *Atletica;
    Skill *Furtivita;
    Skill *Indagare;
    Skill *Inganno;
    Skill *Intimidire;
    Skill *Intrattenere;
    Skill *Intuizione;
    Skill *Medicina;
    Skill *Natura;
    Skill *Percezione;
    Skill *Persuasione;
    Skill *RapiditaDiMano;
    Skill *Religione;
    Skill *Sopravvivenza;
    Skill *Storia;
};

#endif // SKILLSBOX_H
