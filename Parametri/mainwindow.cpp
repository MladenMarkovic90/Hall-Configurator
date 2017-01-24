#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
#include <fstream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_dugmeOtvori_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(this, "Otvorite podatke", QDir::homePath());

    std::fstream file(fileName.toLocal8Bit().data(),std::fstream::in);

    if(!file)
    {
        std::cout << "Greska pri otvaranju fajla: " << fileName.toLocal8Bit().data() << std::endl;
        return;
    }

    std::string text;

    file >> text; ui->objekatDuzina->setText(text.c_str());

    file >> text; ui->donjaAnkerPlocaSirina->setText(text.c_str());
    file >> text; ui->donjaAnkerPlocaDuzina->setText(text.c_str());
    file >> text; ui->donjaAnkerPlocaVisina->setText(text.c_str());

    file >> text; ui->stubSirina->setText(text.c_str());
    file >> text; ui->stubDuzina->setText(text.c_str());
    file >> text; ui->stubVisina->setText(text.c_str());

    file >> text; ui->gornjaAnkerPlocaSirina->setText(text.c_str());
    file >> text; ui->gornjaAnkerPlocaDuzina->setText(text.c_str());
    file >> text; ui->gornjaAnkerPlocaVisina->setText(text.c_str());

    file >> text; ui->binderDonjiLeviPojasSirina->setText(text.c_str());
    file >> text; ui->binderDonjiLeviPojasDuzina->setText(text.c_str());
    file >> text; ui->binderDonjiLeviPojasVisina->setText(text.c_str());

    file >> text; ui->binderDonjiDesniPojasSirina->setText(text.c_str());
    file >> text; ui->binderDonjiDesniPojasDuzina->setText(text.c_str());
    file >> text; ui->binderDonjiDesniPojasVisina->setText(text.c_str());

    file >> text; ui->binderGornjiLeviPojasSirina->setText(text.c_str());
    file >> text; ui->binderGornjiLeviPojasDuzina->setText(text.c_str());
    file >> text; ui->binderGornjiLeviPojasVisina->setText(text.c_str());

    file >> text; ui->binderGornjiDesniPojasSirina->setText(text.c_str());
    file >> text; ui->binderGornjiDesniPojasDuzina->setText(text.c_str());
    file >> text; ui->binderGornjiDesniPojasVisina->setText(text.c_str());

    file >> text; ui->strehaLevoDuzina->setText(text.c_str());
    file >> text; ui->strehaDesnoDuzina->setText(text.c_str());

    file >> text; ui->celoStreheSirina->setText(text.c_str());
    file >> text; ui->celoStreheDuzina->setText(text.c_str());
    file >> text; ui->celoStreheVisina->setText(text.c_str());

    file >> text; ui->roznjacaSirina->setText(text.c_str());
    file >> text; ui->roznjacaVisina->setText(text.c_str());

    file >> text; ui->gredeSirina->setText(text.c_str());
    file >> text; ui->gredeDuzina->setText(text.c_str());

    file >> text; ui->koseGredeSirina->setText(text.c_str());
    file >> text; ui->koseGredeDuzina->setText(text.c_str());

    file >> text; ui->ispunaSirina->setText(text.c_str());
    file >> text; ui->ispunaVisina->setText(text.c_str());

    file >> text; ui->virenjeRoznjace->setText(text.c_str());
    file >> text; ui->IspunaIzmedjuStubova->setText(text.c_str());
    file >> text; ui->ugaoKrova->setText(text.c_str());

    file >> text; ui->StuboviNapred->setText(text.c_str());
    file >> text; ui->StuboviNazad->setText(text.c_str());

    file.close();
}


void MainWindow::on_dugmeSacuvaj_clicked()
{
    QString fileName=QFileDialog::getSaveFileName(this,"Sacuvajte podatke",QDir::homePath());

    std::fstream file(fileName.toLocal8Bit().data(),std::fstream::out);

    if(!file)
    {
        std::cout << "Greska pri sacuvanju fajla: " << fileName.toLocal8Bit().data() << std::endl;
        return;
    }

    file << ui->objekatDuzina->text().toLocal8Bit().data() << std::endl;

    file << ui->donjaAnkerPlocaSirina->text().toLocal8Bit().data() << std::endl;
    file << ui->donjaAnkerPlocaDuzina->text().toLocal8Bit().data() << std::endl;
    file << ui->donjaAnkerPlocaVisina->text().toLocal8Bit().data() << std::endl;

    file << ui->stubSirina->text().toLocal8Bit().data() << std::endl;
    file << ui->stubDuzina->text().toLocal8Bit().data() << std::endl;
    file << ui->stubVisina->text().toLocal8Bit().data() << std::endl;

    file << ui->gornjaAnkerPlocaSirina->text().toLocal8Bit().data() << std::endl;
    file << ui->gornjaAnkerPlocaDuzina->text().toLocal8Bit().data() << std::endl;
    file << ui->gornjaAnkerPlocaVisina->text().toLocal8Bit().data() << std::endl;

    file << ui->binderDonjiLeviPojasSirina->text().toLocal8Bit().data() << std::endl;
    file << ui->binderDonjiLeviPojasDuzina->text().toLocal8Bit().data() << std::endl;
    file << ui->binderDonjiLeviPojasVisina->text().toLocal8Bit().data() << std::endl;

    file << ui->binderDonjiDesniPojasSirina->text().toLocal8Bit().data() << std::endl;
    file << ui->binderDonjiDesniPojasDuzina->text().toLocal8Bit().data() << std::endl;
    file << ui->binderDonjiDesniPojasVisina->text().toLocal8Bit().data() << std::endl;

    file << ui->binderGornjiLeviPojasSirina->text().toLocal8Bit().data() << std::endl;
    file << ui->binderGornjiLeviPojasDuzina->text().toLocal8Bit().data() << std::endl;
    file << ui->binderGornjiLeviPojasVisina->text().toLocal8Bit().data() << std::endl;

    file << ui->binderGornjiDesniPojasSirina->text().toLocal8Bit().data() << std::endl;
    file << ui->binderGornjiDesniPojasDuzina->text().toLocal8Bit().data() << std::endl;
    file << ui->binderGornjiDesniPojasVisina->text().toLocal8Bit().data() << std::endl;

    file << ui->strehaLevoDuzina->text().toLocal8Bit().data() << std::endl;
    file << ui->strehaDesnoDuzina->text().toLocal8Bit().data() << std::endl;

    file << ui->celoStreheSirina->text().toLocal8Bit().data() << std::endl;
    file << ui->celoStreheDuzina->text().toLocal8Bit().data() << std::endl;
    file << ui->celoStreheVisina->text().toLocal8Bit().data() << std::endl;

    file << ui->roznjacaSirina->text().toLocal8Bit().data() << std::endl;
    file << ui->roznjacaVisina->text().toLocal8Bit().data() << std::endl;

    file << ui->gredeSirina->text().toLocal8Bit().data() << std::endl;
    file << ui->gredeDuzina->text().toLocal8Bit().data() << std::endl;

    file << ui->koseGredeSirina->text().toLocal8Bit().data() << std::endl;
    file << ui->koseGredeDuzina->text().toLocal8Bit().data() << std::endl;

    file << ui->ispunaSirina->text().toLocal8Bit().data() << std::endl;
    file << ui->ispunaVisina->text().toLocal8Bit().data() << std::endl;

    file << ui->virenjeRoznjace->text().toLocal8Bit().data() << std::endl;
    file << ui->IspunaIzmedjuStubova->text().toLocal8Bit().data() << std::endl;
    file << ui->ugaoKrova->text().toLocal8Bit().data() << std::endl;

    file << ui->StuboviNapred->text().toLocal8Bit().data() << std::endl;
    file << ui->StuboviNazad->text().toLocal8Bit().data() << std::endl;

    file.close();

    return;
}


void MainWindow::on_dugmePokreni_clicked()
{
    this->hide();

    std::string command("Metalna_Konstrukcija");

    command=command + " " + ui->objekatDuzina->text().toLocal8Bit().data();

    command=command + " " + ui->donjaAnkerPlocaSirina->text().toLocal8Bit().data();
    command=command + " " + ui->donjaAnkerPlocaDuzina->text().toLocal8Bit().data();
    command=command + " " + ui->donjaAnkerPlocaVisina->text().toLocal8Bit().data();

    command=command + " " + ui->stubSirina->text().toLocal8Bit().data();
    command=command + " " + ui->stubDuzina->text().toLocal8Bit().data();
    command=command + " " + ui->stubVisina->text().toLocal8Bit().data();

    command=command + " " + ui->gornjaAnkerPlocaSirina->text().toLocal8Bit().data();
    command=command + " " + ui->gornjaAnkerPlocaDuzina->text().toLocal8Bit().data();
    command=command + " " + ui->gornjaAnkerPlocaVisina->text().toLocal8Bit().data();

    command=command + " " + ui->binderDonjiLeviPojasSirina->text().toLocal8Bit().data();
    command=command + " " + ui->binderDonjiLeviPojasDuzina->text().toLocal8Bit().data();
    command=command + " " + ui->binderDonjiLeviPojasVisina->text().toLocal8Bit().data();

    command=command + " " + ui->binderDonjiDesniPojasSirina->text().toLocal8Bit().data();
    command=command + " " + ui->binderDonjiDesniPojasDuzina->text().toLocal8Bit().data();
    command=command + " " + ui->binderDonjiDesniPojasVisina->text().toLocal8Bit().data();

    command=command + " " + ui->binderGornjiLeviPojasSirina->text().toLocal8Bit().data();
    command=command + " " + ui->binderGornjiLeviPojasDuzina->text().toLocal8Bit().data();
    command=command + " " + ui->binderGornjiLeviPojasVisina->text().toLocal8Bit().data();

    command=command + " " + ui->binderGornjiDesniPojasSirina->text().toLocal8Bit().data();
    command=command + " " + ui->binderGornjiDesniPojasDuzina->text().toLocal8Bit().data();
    command=command + " " + ui->binderGornjiDesniPojasVisina->text().toLocal8Bit().data();

    command=command + " " + ui->strehaLevoDuzina->text().toLocal8Bit().data();
    command=command + " " + ui->strehaDesnoDuzina->text().toLocal8Bit().data();

    command=command + " " + ui->celoStreheSirina->text().toLocal8Bit().data();
    command=command + " " + ui->celoStreheDuzina->text().toLocal8Bit().data();
    command=command + " " + ui->celoStreheVisina->text().toLocal8Bit().data();

    command=command + " " + ui->roznjacaSirina->text().toLocal8Bit().data();
    command=command + " " + ui->roznjacaVisina->text().toLocal8Bit().data();

    command=command + " " + ui->gredeSirina->text().toLocal8Bit().data();
    command=command + " " + ui->gredeDuzina->text().toLocal8Bit().data();

    command=command + " " + ui->koseGredeSirina->text().toLocal8Bit().data();
    command=command + " " + ui->koseGredeDuzina->text().toLocal8Bit().data();

    command=command + " " + ui->ugaoKrova->text().toLocal8Bit().data();

    command=command + " " + ui->virenjeRoznjace->text().toLocal8Bit().data();
    command=command + " " + ui->IspunaIzmedjuStubova->text().toLocal8Bit().data();

    command=command + " " + ui->StuboviNapred->text().toLocal8Bit().data();
    command=command + " " + ui->StuboviNazad->text().toLocal8Bit().data();

    command=command + " " + ui->ispunaSirina->text().toLocal8Bit().data();
    command=command + " " + ui->ispunaVisina->text().toLocal8Bit().data();


    while(!this->isHidden()); // ????

    if(system(command.c_str()) != 0)
        std::cout << "Greska u pokretanju programa" << std::endl;

    this->show();

    return;
}
