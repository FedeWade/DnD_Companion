#include "pgcreationdialog.h"

PGCreationDialog::PGCreationDialog(QWidget *parent, Modello *model) : QDialog(parent), Model(model)
{
    QVBoxLayout *mainlayout = new QVBoxLayout();
    QHBoxLayout *row1 = new QHBoxLayout();
    QHBoxLayout *row2 = new QHBoxLayout();
    QHBoxLayout *row3 = new QHBoxLayout();
    mainlayout->setSpacing(15);

    Esperienza = new QSpinBox(this);
    Razza = new QComboBox(this);
    Forza = new QSpinBox(this);
    Destrezza = new QSpinBox(this);
    Costituzione = new QSpinBox(this);
    Intelligenza = new QSpinBox(this);
    Saggezza = new QSpinBox(this);
    Carisma = new QSpinBox(this);
    Nome = new QLineEdit(this);
    Allineamento = new QComboBox(this);
    Classe = new QComboBox(this);

    Delete = new QPushButton("Cancella", this);
    Create = new QPushButton("Crea\nPersonaggio", this);

    popolateClasse();
    popolateAllineamento();
    popolateRazza();

    Forza->setMaximum(20);
    Destrezza->setMaximum(20);
    Costituzione->setMaximum(20);
    Intelligenza->setMaximum(20);
    Saggezza->setMaximum(20);
    Carisma->setMaximum(20);
    Esperienza->setMaximum(999999);

    QLabel *esperienzalabel = new QLabel("Esperienza", this);
    QLabel *razzalabel = new QLabel("Razza", this);
    QLabel *forzalabel = new QLabel("For", this);
    QLabel *destrezzalabel = new QLabel("Des", this);
    QLabel *costituzionelabel = new QLabel("Cos", this);
    QLabel *intelligenzalabel = new QLabel("Int", this);
    QLabel *saggezzalabel = new QLabel("Sag", this);
    QLabel *carismalabel = new QLabel("Car", this);
    QLabel *nomelabel = new QLabel("Nome", this);
    QLabel *allineamentolabel = new QLabel("Allineamento", this);
    QLabel *classelabel = new QLabel("Classe", this);

    QVBoxLayout *esperienzalo = new QVBoxLayout();
    esperienzalo->addWidget(esperienzalabel);
    esperienzalo->addWidget(Esperienza);

    QVBoxLayout *razzalo = new QVBoxLayout();
    razzalo->addWidget(razzalabel);
    razzalo->addWidget(Razza);

    QVBoxLayout *forzalo = new QVBoxLayout();
    forzalo->addWidget(forzalabel);
    forzalo->addWidget(Forza);

    QVBoxLayout *destrezzalo = new QVBoxLayout();
    destrezzalo->addWidget(destrezzalabel);
    destrezzalo->addWidget(Destrezza);

    QVBoxLayout *costituzionelo = new QVBoxLayout();
    costituzionelo->addWidget(costituzionelabel);
    costituzionelo->addWidget(Costituzione);

    QVBoxLayout *intelligenzalo = new QVBoxLayout();
    intelligenzalo->addWidget(intelligenzalabel);
    intelligenzalo->addWidget(Intelligenza);

    QVBoxLayout *saggezzalo = new QVBoxLayout();
    saggezzalo->addWidget(saggezzalabel);
    saggezzalo->addWidget(Saggezza);

    QVBoxLayout *carismalo = new QVBoxLayout();
    carismalo->addWidget(carismalabel);
    carismalo->addWidget(Carisma);

    QVBoxLayout *nomelo = new QVBoxLayout();
    nomelo->addWidget(nomelabel);
    nomelo->addWidget(Nome);

    QVBoxLayout *allineamentolo = new QVBoxLayout();
    allineamentolo->addWidget(allineamentolabel);
    allineamentolo->addWidget(Allineamento);

    QVBoxLayout *classelo = new QVBoxLayout();
    classelo->addWidget(classelabel);
    classelo->addWidget(Classe);

    row1->addLayout(nomelo);
    row1->addLayout(classelo);
    row1->addLayout(razzalo);
    row1->addLayout(allineamentolo);
    row1->addLayout(esperienzalo);
    row2->addLayout(forzalo);
    row2->addLayout(destrezzalo);
    row2->addLayout(costituzionelo);
    row2->addLayout(intelligenzalo);
    row2->addLayout(saggezzalo);
    row2->addLayout(carismalo);
    row3->addWidget(Delete);
    row3->addWidget(Create);

    mainlayout->addLayout(row1);
    mainlayout->addLayout(row2);
    mainlayout->addLayout(row3);

    setLayout(mainlayout);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

    setObjectName("dialog");
    setWindowTitle("Crea personaggio");
    setStyle();

    connect(Delete, SIGNAL(clicked()), this, SLOT(reject()));
    connect(Create, SIGNAL(clicked()), this, SLOT(createClicked()));
}

void PGCreationDialog::update()
{
    Nome->setText("");
    Esperienza->setValue(0);
    Forza->setValue(8);
    Destrezza->setValue(8);
    Costituzione->setValue(8);
    Intelligenza->setValue(8);
    Saggezza->setValue(8);
    Carisma->setValue(8);
    Classe->setCurrentIndex(0);
    Razza->setCurrentIndex(0);
    Allineamento->setCurrentIndex(0);
}

void PGCreationDialog::createClicked()
{
    Model->addNewPG(static_cast<Classi>(Classe->currentIndex()),
                    Esperienza->value(),
                    static_cast<Razze>(Razza->currentIndex()),
                    Forza->value(),
                    Destrezza->value(),
                    Costituzione->value(),
                    Intelligenza->value(),
                    Saggezza->value(),
                    Carisma->value(),
                    (Nome->text()).toStdString(),
                    static_cast<Allineamenti>(Allineamento->currentIndex()));
    emit(PGCreated());
    close();
}

void PGCreationDialog::popolateRazza()
{
    Razza->addItems(QStringList({"Elfo",
                                 "Halfling",
                                 "Nano",
                                 "Umano",
                                 "Dragonide",
                                 "Gnomo",
                                 "Mezzelfo",
                                 "Mezzorco",
                                 "Tiefling"}));
}

void PGCreationDialog::popolateAllineamento()
{
    Allineamento->addItems(QStringList({"LegaleBuono",
                                        "NeutraleBuono",
                                        "CaoticoBuono",
                                        "LegaleNeutrale",
                                        "Neutrale",
                                        "CaoticoNeutrale",
                                        "LegaleMalvagio",
                                        "NeutraleMalvagio",
                                        "CaoticoMalvagio"}));
}

void PGCreationDialog::popolateClasse()
{
    Classe->addItems(QStringList({"Barbaro", "Chierico", "Guerriero", "Mago"}));
}

void PGCreationDialog::setStyle()
{
    Create->setObjectName("create");
    Delete->setObjectName("delete");
    Create->setFixedSize(300, 65);
    Delete->setFixedSize(150, 45);

    Esperienza->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Nome->setFixedSize(190, 35);
    Esperienza->setFixedSize(80, 35);
    Forza->setFixedSize(55, 35);
    Destrezza->setFixedSize(55, 35);
    Costituzione->setFixedSize(55, 35);
    Intelligenza->setFixedSize(55, 35);
    Saggezza->setFixedSize(55, 35);
    Carisma->setFixedSize(55, 35);

    Esperienza->setAlignment(Qt::AlignCenter);
    Forza->setAlignment(Qt::AlignCenter);
    Intelligenza->setAlignment(Qt::AlignCenter);
    Destrezza->setAlignment(Qt::AlignCenter);
    Costituzione->setAlignment(Qt::AlignCenter);
    Saggezza->setAlignment(Qt::AlignCenter);
    Carisma->setAlignment(Qt::AlignCenter);

    setStyleSheet(" #dialog{background-color:rgb(45,45,45); border:3px solid #15DB95;}"
                  " QSpinBox, QComboBox, QLineEdit, QPushButton {font-size:20px; height: 31px;}"
                  " QSpinBox { width:70px; height: 28px; text-align:center; } "
                  " #create, #delete { border-width: 3px; border-color:black; color:black; "
                  "background-color:white} "
                  " #create { border-color: #15DB95; } "
                  " #create::hover, #delete::hover { background-color:rgb(200,200,200); } ");
}
