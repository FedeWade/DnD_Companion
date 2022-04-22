#include "equipmentbox.h"

EquipmentBox::EquipmentBox(QWidget *parent, Modello *model) : QWidget(parent), Model(model)
{
    QVBoxLayout *mainlayout = new QVBoxLayout();
    QHBoxLayout *grouplayout = new QHBoxLayout();
    QVBoxLayout *moneylayout = new QVBoxLayout();
    QGroupBox *group = new QGroupBox("Equipaggiamento", this);
    group->setAlignment(Qt::AlignCenter);
    grouplayout->setContentsMargins(15, 25, 15, 15);

    Rame = new QSpinBox(this);
    Rame->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Rame->setObjectName("rame");
    Rame->setMaximum(99999);
    Argento = new QSpinBox(this);
    Argento->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Argento->setObjectName("argento");
    Argento->setMaximum(99999);
    Electrum = new QSpinBox(this);
    Electrum->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Electrum->setObjectName("electrum");
    Electrum->setMaximum(99999);
    Oro = new QSpinBox(this);
    Oro->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Oro->setObjectName("oro");
    Oro->setMaximum(99999);
    Platino = new QSpinBox(this);
    Platino->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Platino->setObjectName("platino");
    Platino->setMaximum(99999);

    QHBoxLayout *ramel = new QHBoxLayout();
    QHBoxLayout *argentol = new QHBoxLayout();
    QHBoxLayout *electruml = new QHBoxLayout();
    QHBoxLayout *orol = new QHBoxLayout();
    QHBoxLayout *platinol = new QHBoxLayout();

    QLabel *ramelabel = new QLabel("MR", this);
    QLabel *argentolabel = new QLabel("MA", this);
    QLabel *electrumlabel = new QLabel("ME", this);
    QLabel *orolabel = new QLabel("MO", this);
    QLabel *platinolabel = new QLabel("MP", this);

    ramel->addWidget(ramelabel);
    ramel->addWidget(Rame);
    argentol->addWidget(argentolabel);
    argentol->addWidget(Argento);
    electruml->addWidget(electrumlabel);
    electruml->addWidget(Electrum);
    orol->addWidget(orolabel);
    orol->addWidget(Oro);
    platinol->addWidget(platinolabel);
    platinol->addWidget(Platino);

    moneylayout->addLayout(ramel);
    moneylayout->addLayout(argentol);
    moneylayout->addLayout(electruml);
    moneylayout->addLayout(orol);
    moneylayout->addLayout(platinol);

    grouplayout->addLayout(moneylayout);

    Inventory = new QTextEdit(this);
    Inventory->setObjectName("inventario");
    grouplayout->addWidget(Inventory);

    group->setLayout(grouplayout);
    mainlayout->addWidget(group);

    setLayout(mainlayout);
    setStyle();

    connect(Rame, SIGNAL(valueChanged(int)), this, SLOT(applyRameChanges(int)));
    connect(Argento, SIGNAL(valueChanged(int)), this, SLOT(applyArgentoChanges(int)));
    connect(Electrum, SIGNAL(valueChanged(int)), this, SLOT(applyElectrumChanges(int)));
    connect(Oro, SIGNAL(valueChanged(int)), this, SLOT(applyOroChanges(int)));
    connect(Platino, SIGNAL(valueChanged(int)), this, SLOT(applyPlatinoChanges(int)));
    connect(Inventory, SIGNAL(textChanged()), this, SLOT(applyInventoryChanges()));

    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
}

void EquipmentBox::update()
{
    if (!Model->getSelectedPG()) {
        disableAll();
        Rame->setValue(0);
        Argento->setValue(0);
        Electrum->setValue(0);
        Oro->setValue(0);
        Platino->setValue(0);
        Inventory->setPlainText("");
    } else {
        enableAll();
        Rame->setValue(Model->getSelectedPG()->Inventario.getRame());
        Argento->setValue(Model->getSelectedPG()->Inventario.getArgento());
        Electrum->setValue(Model->getSelectedPG()->Inventario.getElectrum());
        Oro->setValue(Model->getSelectedPG()->Inventario.getOro());
        Platino->setValue(Model->getSelectedPG()->Inventario.getPlatino());
        Inventory->setPlainText(
            QString::fromStdString((Model->getSelectedPG())->getDescInventario()));
    }
}

void EquipmentBox::disableAll()
{
    Rame->setReadOnly(true);
    Argento->setReadOnly(true);
    Electrum->setReadOnly(true);
    Oro->setReadOnly(true);
    Platino->setReadOnly(true);
    Inventory->setReadOnly(true);
}

void EquipmentBox::enableAll()
{
    Rame->setReadOnly(false);
    Argento->setReadOnly(false);
    Electrum->setReadOnly(false);
    Oro->setReadOnly(false);
    Platino->setReadOnly(false);
    Inventory->setReadOnly(false);
}

void EquipmentBox::applyRameChanges(int newvalue)
{
    if (Model->getSelectedPG())
        Model->getSelectedPG()->Inventario.setRame(newvalue);
}

void EquipmentBox::applyArgentoChanges(int newvalue)
{
    if (Model->getSelectedPG())
        Model->getSelectedPG()->Inventario.setArgento(newvalue);
}

void EquipmentBox::applyElectrumChanges(int newvalue)
{
    if (Model->getSelectedPG())
        Model->getSelectedPG()->Inventario.setElectrum(newvalue);
}

void EquipmentBox::applyOroChanges(int newvalue)
{
    if (Model->getSelectedPG())
        Model->getSelectedPG()->Inventario.setOro(newvalue);
}

void EquipmentBox::applyPlatinoChanges(int newvalue)
{
    if (Model->getSelectedPG())
        Model->getSelectedPG()->Inventario.setPlatino(newvalue);
}

void EquipmentBox::applyInventoryChanges()
{
    if (Model->getSelectedPG())
        (Model->getSelectedPG())->setDescInventario((Inventory->toPlainText()).toStdString());
}

void EquipmentBox::setStyle()
{
    Rame->setFixedSize(52, 30);
    Argento->setFixedSize(52, 30);
    Electrum->setFixedSize(52, 30);
    Oro->setFixedSize(52, 30);
    Platino->setFixedSize(52, 30);

    Rame->setAlignment(Qt::AlignCenter);
    Argento->setAlignment(Qt::AlignCenter);
    Electrum->setAlignment(Qt::AlignCenter);
    Oro->setAlignment(Qt::AlignCenter);
    Platino->setAlignment(Qt::AlignCenter);

    setStyleSheet(" #rame, #argento, #electrum, #oro, #platino { font-size: 17px; } ");
}
