//=========================================================
// Name        : dialog.cpp
// Author      : Michael Louie
// Description : Contains logic for all dialog-related UIs.
//=========================================================
#include "dialog.h"

Dialog::Dialog() { }

void Dialog::showSaveConfirmationDialog()
{
    dsc.setModal(true);
    dsc.exec();
}

void Dialog::showAboutDialog()
{
    da.setModal(true);
    da.exec();
}

