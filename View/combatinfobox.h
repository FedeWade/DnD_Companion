#ifndef COMBATINFOBOX_H
#define COMBATINFOBOX_H

#include "Model/modello.h"
#include <QDoubleSpinBox>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

class CombatInfoBox : public QWidget
{
    Q_OBJECT
public:
    CombatInfoBox(QWidget *parent = nullptr, Modello *model = nullptr);
    void update();
public slots:
    void editClicked();
    void saveClicked();
signals:
    void valuesChanged();

private:
    Modello *Model;

    QPushButton *Save;
    QPushButton *Edit;

    QSpinBox *Ispirazione;
    QSpinBox *Competenza;

    QSpinBox *CA;
    QSpinBox *Iniziativa;
    QDoubleSpinBox *Velocita;

    void setStyle();
};

#endif // COMBATINFOBOX_H
