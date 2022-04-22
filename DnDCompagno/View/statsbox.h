#ifndef STATSBOX_H
#define STATSBOX_H

#include "Model/modello.h"
#include "stat.h"
#include <QGroupBox>
#include <QHBoxLayout>
#include <QIcon>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class StatsBox : public QWidget
{
    Q_OBJECT
public:
    StatsBox(QWidget *parent = nullptr, Modello *modello = nullptr);
    void update();

public slots:
    void editClicked();
    void saveClicked();

signals:
    void valuesChanged();

private:
    Modello *Model;

    QPushButton *Edit;
    QPushButton *Save;

    Stat *Forza;
    Stat *Destrezza;
    Stat *Costituzione;
    Stat *Intelligenza;
    Stat *Saggezza;
    Stat *Carisma;

    void setStyle() const;
};

#endif // STATSBOX_H
