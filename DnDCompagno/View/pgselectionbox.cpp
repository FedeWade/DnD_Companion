#include "pgselectionbox.h"

PGSelectionBox::PGSelectionBox(QWidget *parent, Modello *model) : QWidget(parent), Model(model)
{
    QHBoxLayout *mainlayout = new QHBoxLayout();
    mainlayout->setAlignment(Qt::AlignTop);
    mainlayout->setContentsMargins(0, 0, 0, 0);
    mainlayout->setSpacing(0);

    Delete = new QPushButton("Cancella", this);
    ComboPG = new QComboBox(this);
    Load = new QPushButton("Carica", this);
    Create = new QPushButton("Crea Personaggio", this);

    ComboPG->setView(new QListView());

    Delete->setObjectName("delete");
    ComboPG->setObjectName("combo");
    Load->setObjectName("load");
    Create->setObjectName("create");

    mainlayout->addWidget(Create);
    mainlayout->addWidget(ComboPG);
    mainlayout->addWidget(Load);
    mainlayout->addWidget(Delete);

    CreationDialog = new PGCreationDialog(this, Model);

    DeleteDialog = new QMessageBox(this);
    DeleteDialog->setModal(true);
    DeleteDialog->setText("Vuoi davvero cancellare definitivamente il personaggio selezionato?");
    DeleteDialog->addButton("Annulla", QMessageBox::RejectRole);
    DeleteDialog->addButton("Conferma", QMessageBox::AcceptRole);

    QGraphicsColorizeEffect *eEffect = new QGraphicsColorizeEffect(Create);
    Create->setGraphicsEffect(eEffect);
    CreateAnimation = new QPropertyAnimation(eEffect, "color");
    CreateAnimation->setStartValue(QColor(0, 200, 0));
    CreateAnimation->setEndValue(QColor(Qt::black));
    CreateAnimation->setDuration(2000);
    CreateAnimation->start();

    setObjectName("bar");
    setStyle();

    setLayout(mainlayout);
    connect(Load, SIGNAL(clicked()), this, SLOT(loadClicked()));
    connect(Delete, SIGNAL(clicked()), this, SLOT(showDeleteDialog()));
    connect(DeleteDialog, SIGNAL(accepted()), this, SLOT(deleteClicked()));
    connect(Create, SIGNAL(clicked()), this, SLOT(showCreationDialog()));
    connect(CreationDialog, SIGNAL(PGCreated()), this, SLOT(updatePGs()));
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

    mainlayout->setStretchFactor(Create, 4);
    mainlayout->setStretchFactor(ComboPG, 5);
    mainlayout->setStretchFactor(Load, 3);
    mainlayout->setStretchFactor(Delete, 3);
}

void PGSelectionBox::loadClicked()
{
    try {
        if (!Model->getPGsNumber()) {
            ExceptionMessage *errmsg
                = new ExceptionMessage(this,
                                       "Attenzione! Nessun personaggio è ancora stato creato, "
                                       "premi 'Crea personaggio' per crearne uno.");
            errmsg->show();
            return;
        }
        if (Model->getSelectedPG() && Model->getselectedPGIndex() == ComboPG->currentIndex())
            return;

        Model->setSelectedPG(ComboPG->currentIndex());
        emit(pgChanged());

    } catch (std::exception *exc) {
        ExceptionMessage *errmsg = new ExceptionMessage(this, exc->what());
        errmsg->show();
    }
}

void PGSelectionBox::deleteClicked()
{
    if (Model->getPGsNumber()) {
        Model->removePG(ComboPG->currentIndex());
        emit(pgChanged());
        return;
    }
    ExceptionMessage *errmsg
        = new ExceptionMessage(this,
                               "Attenzione! Nessun personaggio è ancora stato creato, premi 'Crea "
                               "personaggio' per crearne uno.");
    errmsg->show();
}

void PGSelectionBox::updatePGs()
{
    update();
}

void PGSelectionBox::showCreationDialog()
{
    CreationDialog->update();
    CreationDialog->show();
}

void PGSelectionBox::showDeleteDialog()
{
    if (!Model->getPGsNumber())
        deleteClicked();
    else
        DeleteDialog->show();
}

void PGSelectionBox::setStyle()
{
    Create->setMinimumHeight(65);
    ComboPG->setMinimumHeight(65);
    Load->setMinimumHeight(65);
    Delete->setMinimumHeight(65);

    setStyleSheet(
        " #delete, #combo, #load, #create {font-size:25px; background-color: rgb(50,50,50); "
        "color:white; border: 2px solid white; border-width: 0px 0px 5px 5px; } "
        " #delete::hover, #combo::hover, #create::hover, #load::hover { background-color: "
        "rgb(35,35,35); color:#15DB95; } "
        "QComboBox QAbstractItemView {background-color: rgb(50,50,50); color:white; border: 3px "
        "solid white; selection-background-color: #15DB95; selection-color:black;}"
        "");
    ComboPG->setStyleSheet(
        "*{font-size:23px;} QComboBox QAbstractItemView::item { min-height: 45px; border-bottom: "
        "1px solid white;} QListView::item{font-size:30px;} QListView::item:selected "
        "{background-color: #15DB95; color:black;}");
}

void PGSelectionBox::update()
{
    ComboPG->clear();

    if (Model->empty())
        CreateAnimation->QPropertyAnimation::setLoopCount(-1);
    else
        CreateAnimation->QPropertyAnimation::setLoopCount(0);

    for (int i = 0; i < Model->getPGsNumber(); i++) {
        ComboPG->addItem(" " + QString::fromStdString(Model->getPG(i)->getNome()) + " - "
                         + QString::fromStdString(Model->getPG(i)->getClasse()));
    }
    if (Model->getSelectedPG())
        ComboPG->setCurrentIndex(Model->getselectedPGIndex());
}
