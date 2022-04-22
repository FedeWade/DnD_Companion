#ifndef DND_H
#define DND_H

#include "Model/modello.h"
#include "View/skillsbox.h"
#include "View/statsbox.h"
#include "View/baseinfo.h"
#include "View/combatinfobox.h"
#include "View/descriptionbox.h"
#include "View/equipmentbox.h"
#include "View/healthbox.h"
#include "View/pgselectionbox.h"
#include "View/savingthrowsbox.h"
#include "View/spellsbox.h"
#include "View/spellsslotsbox.h"
#include <stdexcept>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class DND : public QWidget
{
    Q_OBJECT

public:
    DND(QWidget *parent = nullptr, Modello *modello = nullptr);
    ~DND();

public slots:
    void update();

private:
    Modello *Model;

    StatsBox *Stats;
    SkillsBox *Skills;
    SavingThrowsBox *SavingThrows;
    CombatInfoBox *CombatInfo;
    HealthBox *Health;
    EquipmentBox *Equipment;
    SpellsBox *Spells;
    SpellsSlotsBox *Slots;
    BaseInfo *Info;
    PGSelectionBox *PGSelection;
    DescriptionBox *Description;
};
#endif // DND_H
