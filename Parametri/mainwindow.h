#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_dugmeOtvori_clicked();

    void on_dugmeSacuvaj_clicked();

    void on_dugmePokreni_clicked();

    void on_objekatDuzina_editingFinished();

    void on_donjaAnkerPlocaSirina_editingFinished();

    void on_donjaAnkerPlocaDuzina_editingFinished();

    void on_donjaAnkerPlocaVisina_editingFinished();

    void on_stubSirina_editingFinished();

    void on_stubDuzina_editingFinished();

    void on_stubVisina_editingFinished();

    void on_gornjaAnkerPlocaSirina_editingFinished();

    void on_gornjaAnkerPlocaDuzina_editingFinished();

    void on_gornjaAnkerPlocaVisina_editingFinished();

    void on_binderDonjiLeviPojasSirina_editingFinished();

    void on_binderDonjiLeviPojasDuzina_editingFinished();

    void on_binderDonjiLeviPojasVisina_editingFinished();

    void on_binderDonjiDesniPojasSirina_editingFinished();

    void on_binderDonjiDesniPojasDuzina_editingFinished();

    void on_binderDonjiDesniPojasVisina_editingFinished();

    void on_binderGornjiLeviPojasSirina_editingFinished();

    void on_binderGornjiLeviPojasDuzina_editingFinished();

    void on_binderGornjiLeviPojasVisina_editingFinished();

    void on_binderGornjiDesniPojasSirina_editingFinished();

    void on_binderGornjiDesniPojasDuzina_editingFinished();

    void on_binderGornjiDesniPojasVisina_editingFinished();

    void on_strehaLevoDuzina_editingFinished();

    void on_strehaDesnoDuzina_editingFinished();

    void on_celoStreheSirina_editingFinished();

    void on_celoStreheDuzina_editingFinished();

    void on_celoStreheVisina_editingFinished();

    void on_roznjacaSirina_editingFinished();

    void on_roznjacaVisina_editingFinished();

    void on_ugaoKrova_editingFinished();

    void on_gredeSirina_editingFinished();

    void on_gredeDuzina_editingFinished();

    void on_koseGredeSirina_editingFinished();

    void on_koseGredeDuzina_editingFinished();

    void on_virenjeRoznjace_editingFinished();

    void on_IspunaIzmedjuStubova_editingFinished();

    void on_StuboviNapred_editingFinished();

    void on_StuboviNazad_editingFinished();

    void on_ispunaSirina_editingFinished();

    void on_ispunaVisina_editingFinished();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
