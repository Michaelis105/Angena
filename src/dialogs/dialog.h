//===================================================
// Name        : dialog.h
// Author      : Michael Louie
// Description : Header for many dialog interactions.
//===================================================
#ifndef DIALOG_H
#define DIALOG_H
#include "dialogabout.h"
#include "dialognewfamily.h"
#include "dialogsaveconfirmation.h"

class Dialog
{
    private:
        DialogAbout da;
    public:
        Dialog();
        void showAboutDialog();
        void showSaveConfirmationDialog();
        void showNewFamilyTreeDialog();
};

#endif // DIALOG_H
