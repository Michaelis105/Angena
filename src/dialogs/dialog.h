//===================================================
// Name        : dialog.h
// Author      : Michael Louie
// Description : Header for many dialog interactions.
//===================================================
#ifndef DIALOG_H
#define DIALOG_H
#include "dialogabout.h"
#include "dialogsaveconfirmation.h"

class Dialog
{
    public:
        Dialog();
        DialogAbout da;
        DialogSaveConfirmation dsc;
        void showAboutDialog();
        void showSaveConfirmationDialog();
};

#endif // DIALOG_H
