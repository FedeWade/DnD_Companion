#ifndef SKILL_H
#define SKILL_H

#include "Model/modello.h"
#include "exceptionmessage.h"
#include <QCheckBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

class Skill : public QWidget
{
    Q_OBJECT
public:
    Skill(QWidget *parent = nullptr, Modello *modello = nullptr, const std::string &name = "noname");

    std::string Name;
    QCheckBox *Check;
    QLabel *Value;

    void update();
    void makeCheckable();
    void makeUncheckable();
    Modello *Model;
};

#endif // SKILL_H
