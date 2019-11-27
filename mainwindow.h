#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "patient.h"
#include "convention.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouterpatient_clicked();


    void on_supprimerpatient_clicked();

    void on_ajouterconvention_clicked();

    void on_supprimerconvention_clicked();


    void on_modifierpatient_clicked();

    void on_modifierconvention_clicked();

    void on_trierpatient_clicked();

    void on_trierconvention_clicked();

    void on_chercher_convention_clicked();



    void on_cherch_cin_2_cursorPositionChanged(int arg1, int arg2);


    void on_cherch_code_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    patient tmppatient;
    convention tmpconvention;
};
#endif // MAINWINDOW_H
