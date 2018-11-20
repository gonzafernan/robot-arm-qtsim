#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QtDebug>

#include "ui_filemanager.h"
#include "conjuntointerfaz.h"

namespace Ui {
    class FileManager;
}

class FileManager : public QMainWindow, public ConjuntoInterfaz {

    Q_OBJECT

    public:
        explicit FileManager(QWidget *parent = nullptr);
        ~FileManager();

    public slots:
        void on_action_Open_File_triggered();
        void on_AceptarF_clicked();
        void on_CancelarF_clicked();

    private:
        Ui::FileManager *ui;
        QString program;
        QString Direcc;

};

#endif // FILEMANAGER_H
