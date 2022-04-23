#ifndef EQUIPMENTBOX_H
#define EQUIPMENTBOX_H

#include "Model/modello.h"
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

class EquipmentBox : public QWidget
{
    Q_OBJECT
public:
    EquipmentBox(QWidget *parent = nullptr, Modello *model = nullptr);
    void update();
    void disableAll();
    void enableAll();

public slots:
    void applyRameChanges(int);
    void applyArgentoChanges(int);
    void applyElectrumChanges(int);
    void applyOroChanges(int);
    void applyPlatinoChanges(int);

    void applyInventoryChanges();

private:
    Modello *Model;

    QSpinBox *Rame;
    QSpinBox *Argento;
    QSpinBox *Electrum;
    QSpinBox *Oro;
    QSpinBox *Platino;

    QTextEdit *Inventory;

    void setStyle();

signals:
};

#endif // EQUIPMENTBOX_H
