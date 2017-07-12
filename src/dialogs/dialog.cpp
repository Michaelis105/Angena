//=========================================================
// Name        : dialog.cpp
// Author      : Michael Louie
// Description : Contains logic for all dialog-related UIs.
//=========================================================
#include "dialog.h"

Dialog::Dialog() { }

void Dialog::showAboutDialog()
{
    DialogAbout da;
    da.setModal(true);
    da.exec();
}

void Dialog::showSaveConfirmationDialog()
{
    DialogSaveConfirmation dsc;
    dsc.setModal(true);
    dsc.exec();
}

void Dialog::showNewFamilyTreeDialog()
{
    DialogNewFamily dnft;
    dnft.setModal(true);
    dnft.exec();
}

