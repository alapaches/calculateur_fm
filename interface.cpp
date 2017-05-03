#include "interface.h"
#include "ui_interface.h"



Interface::Interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface)
{
    preambule.setWindowTitle("Informations");
    preambule.setWindowIcon(QIcon(":/new/images/icon.png"));
    preambule.setIcon(QMessageBox::Information);
    preambule.setText("Cet outil n'est en aucun cas en collaboration avec Ankama ni Dofus.\nIl a seulement pour but d'aider les utilisateurs qui font du FM à calculer de manière extrêmement rapide les poids et les pui avec les runes.\nMerci à @kryphonTV, @Dapimp et @Frafra pour leurs connaissances précieuses.");
    preambule.show();
    ui->setupUi(this);
    QPixmap bkgnd(":/new/images/fm.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    this->setFixedSize(QSize (this->width(),this->height()));
    listeRunes.insert(0,"Selectionnez une rune");
    listeRunes.insert(1,"Rune Do ren");
    listeRunes.insert(2,"Rune Do");
    listeRunes.insert(3,"Rune Invo");
    listeRunes.insert(4,"Rune Po");
    listeRunes.insert(5,"Rune GaPM");
    listeRunes.insert(6,"Rune GaPa");
    ui->runeSauteeCombo->addItems(listeRunes);
    ui->runesAdditionnellesWidget->insertColumn(0);
    ui->runesAdditionnellesWidget->insertColumn(1);
    ui->runesAdditionnellesWidget->insertColumn(2);
    ui->runesAdditionnellesWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Type Rune"));
    ui->runesAdditionnellesWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Rune"));
    ui->runesAdditionnellesWidget->setColumnWidth(0,70);
    ui->runesAdditionnellesWidget->setColumnWidth(1,280);
    ui->runesAdditionnellesWidget->setColumnWidth(2,70);
    ui->runesAdditionnellesWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Poids Rune"));
}

Interface::~Interface()
{
    delete ui;
}

void Interface::on_runeSauteeCombo_currentIndexChanged(int index)
{
    QString typeRune = "Normale";
    indexRunes++;
    if(index == 1)
    {
        ui->poidsRuneSautee->setText("10");
    }
    else if(index == 2)
    {
        ui->poidsRuneSautee->setText("20");
    }
    else if(index == 3)
    {
        ui->poidsRuneSautee->setText("30");
    }
    else if(index == 4)
    {
        ui->poidsRuneSautee->setText("51");
    }
    else if(index == 5)
    {
        ui->poidsRuneSautee->setText("90");
    }
    else if(index == 6)
    {
        ui->poidsRuneSautee->setText("100");
    }
    else
    {
        ui->poidsRuneSautee->clear();
    }
    if(indexRunes == 2)
    {
        prefixe = "+ ";
        ui->runeSauteeCombo->setDisabled(true);
    }
    else
    {
        prefixe = "- ";
    }
    if(index != 0)
    {
        ui->runesAdditionnellesWidget->insertRow(0);
        QTableWidgetItem* col1 = new QTableWidgetItem;
        col1->setText(typeRune);
        ui->runesAdditionnellesWidget->setItem(0,0,col1);
        QString nomRuneSautee = ui->runeSauteeCombo->currentText();
        QTableWidgetItem* col2 = new QTableWidgetItem;
        col2->setText(nomRuneSautee);
        ui->runesAdditionnellesWidget->setItem(0,1,col2);
        QString poidsRuneSautee = ui->poidsRuneSautee->text();
        QTableWidgetItem* col3 = new QTableWidgetItem;
        col3->setText(prefixe + poidsRuneSautee);
        ui->runesAdditionnellesWidget->setItem(0,2,col3);
        ui->puissance->setText(ui->poidsRuneSautee->text());
    }
}

void Interface::Raz()
{
    QString razPoids = ui->poidsRuneSautee->text();
    if(ui->conserverRunesCheckbox->isChecked() == true)
    {
         ui->runesAdditionnellesWidget->setRowCount(1);
         ui->runeSauteeCombo->setDisabled(true);
         ui->puissance->setText(razPoids);
    }
}

void Interface::on_razButton_clicked()
{
    Raz();
}

void Interface::on_runes2Poids5Button_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runes2Poids5Button->text();
    QString typeRune = "Normale";
    QString poidsRune = "2.5";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runes2Poids5PaButton_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runes2Poids5Button->text();
    QString typeRune = "Pa";
    QString poidsRune = "7.5";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runes2Poids5RaButton_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runes2Poids5Button->text();
    QString typeRune = "Ra";
    QString poidsRune = "25";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids20Button_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids20Button->text();
    QString typeRune = "Normale";
    QString poidsRune = "20";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids1Button_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids1Button->text();
    QString typeRune = "Normale";
    QString poidsRune = "1";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids1PaButton_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids1Button->text();
    QString typeRune = "Pa";
    QString poidsRune = "3";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids1RaButton_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids1Button->text();
    QString typeRune = "Ra";
    QString poidsRune = "10";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids2Button_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids2Button->text();
    QString typeRune = "Normale";
    QString poidsRune = "2";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids2PaButton_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids2Button->text();
    QString typeRune = "Pa";
    QString poidsRune = "6";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids2RaButton_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids2Button->text();
    QString typeRune = "Ra";
    QString poidsRune = "20";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids3SaButton_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids3SaButton->text();
    QString typeRune = "Normale";
    QString poidsRune = "3";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids3SaPaButton_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids3SaButton->text();
    QString typeRune = "Pa";
    QString poidsRune = "9";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids3SaRaButton_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids3SaButton->text();
    QString typeRune = "Ra";
    QString poidsRune = "30";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_rune3ProspeButton_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->rune3ProspeButton->text();
    QString typeRune = "Normale";
    QString poidsRune = "3";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_rune3ProspePaButton_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->rune3ProspeButton->text();
    QString typeRune = "Pa";
    QString poidsRune = "9";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids4Button_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids4Button->text();
    QString typeRune = "Normale";
    QString poidsRune = "4";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids4PaButton_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids4Button->text();
    QString typeRune = "Pa";
    QString poidsRune = "12";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids5Button_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids5Button->text();
    QString typeRune = "Normale";
    QString poidsRune = "5";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids5PaButton_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids5Button->text();
    QString typeRune = "Pa";
    QString poidsRune = "15";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids6Button_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids6Button->text();
    QString typeRune = "Normale";
    QString poidsRune = "6";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids7Button_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids7Button->text();
    QString typeRune = "Normale";
    QString poidsRune = "7";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids7PaButton_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids7Button->text();
    QString typeRune = "Pa";
    QString poidsRune = "21";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids10Button_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids10Button->text();
    QString typeRune = "Normale";
    QString poidsRune = "10";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids30Button_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids30Button->text();
    QString typeRune = "Normale";
    QString poidsRune = "30";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids51Button_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids51Button->text();
    QString typeRune = "Normale";
    QString poidsRune = "51";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids90Button_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids90Button->text();
    QString typeRune = "Normale";
    QString poidsRune = "90";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}

void Interface::on_runesPoids100Button_clicked()
{
    const int currentRow = ui->runesAdditionnellesWidget->rowCount();
    prefixe ="- ";
    nomRune = ui->runesPoids100Button->text();
    QString typeRune = "Normale";
    QString poidsRune = "100";
    ui->runesAdditionnellesWidget->insertRow(currentRow);
    QTableWidgetItem* col1 = new QTableWidgetItem;
    col1->setText(typeRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,0,col1);
    QTableWidgetItem* col2 = new QTableWidgetItem;
    col2->setText("Rune " + nomRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,1,col2);
    QTableWidgetItem* col3 = new QTableWidgetItem;
    col3->setText(prefixe + poidsRune);
    ui->runesAdditionnellesWidget->setItem(currentRow,2,col3);
    float puissance = ui->puissance->text().toFloat();
    float puissanceRune = poidsRune.toFloat();
    float puissanceTotale = puissance - puissanceRune;
    QString puissanceMax = QString::number(puissanceTotale);
    ui->puissance->setText(puissanceMax);
}
