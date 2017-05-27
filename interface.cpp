#include "interface.h"
#include "ui_interface.h"
#include "qpainter.h"



Interface::Interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface)
{
    preambule.setWindowTitle("Informations");
    preambule.setWindowIcon(QIcon(":/new/images/icon.png"));
    preambule.setIcon(QMessageBox::Information);
    preambule.setText("Cet outil n'est en aucun cas en collaboration avec Ankama ni Dofus.\nIl a seulement pour but d'aider les utilisateurs qui font du FM à calculer de manière extrêmement rapide les poids et les pui avec les runes.\nMerci à @Tarym, @kryphonTV, @Dapimp et @Frafra pour leurs connaissances précieuses.");
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
    ui->runesAdditionnellesWidget->setColumnWidth(1,325);
    ui->runesAdditionnellesWidget->setColumnWidth(2,70);
    ui->runesAdditionnellesWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Poids Rune"));
    int w = ui->runesPoids1Button->size().width()-4;
    int h = ui->runesPoids1Button->size().height()-4;
    QPixmap runes1Png(":/new/images/runes1.png");
    QIcon runes1ButtonIcon(runes1Png);
    ui->runesPoids1Button->setIcon(runes1ButtonIcon);
    ui->runesPoids1Button->setIconSize(QSize(w,h));

    QPixmap runes2Png(":/new/images/runes2.png");
    QIcon runes2ButtonIcon(runes2Png);
    ui->runesPoids2Button->setIcon(runes2ButtonIcon);
    ui->runesPoids2Button->setIconSize(QSize(w,h));

    QPixmap runes2Poids5Png(":/new/images/runes2,5.png");
    QIcon runes2Poids5ButtonIcon(runes2Poids5Png);
    ui->runes2Poids5Button->setIcon(runes2Poids5ButtonIcon);
    ui->runes2Poids5Button->setIconSize(QSize(w,h));

    QPixmap runes3SaPng(":/new/images/runes3Sa.png");
    QIcon runes3SaButtonIcon(runes3SaPng);
    ui->runesPoids3SaButton->setIcon(runes3SaButtonIcon);
    ui->runesPoids3SaButton->setIconSize(QSize(w,h));

    QPixmap runes3ProspePng(":/new/images/runes3Prospe.png");
    QIcon runes3ProspeButtonIcon(runes3ProspePng);
    ui->rune3ProspeButton->setIcon(runes3ProspeButtonIcon);
    ui->rune3ProspeButton->setIconSize(QSize(w,h));

    QPixmap runes4Png(":/new/images/runes4.png");
    QIcon runes4ButtonIcon(runes4Png);
    ui->runesPoids4Button->setIcon(runes4ButtonIcon);
    ui->runesPoids4Button->setIconSize(QSize(w,h));

    QPixmap runes5Png(":/new/images/runes5.png");
    QIcon runes5ButtonIcon(runes5Png);
    ui->runesPoids5Button->setIcon(runes5ButtonIcon);
    ui->runesPoids5Button->setIconSize(QSize(w,h));

    QPixmap runes6Png(":/new/images/runes6.png");
    QIcon runes6ButtonIcon(runes6Png);
    ui->runesPoids6Button->setIcon(runes6ButtonIcon);
    ui->runesPoids6Button->setIconSize(QSize(w,h));

    QPixmap runes7Png(":/new/images/runes7.png");
    QIcon runes7ButtonIcon(runes7Png);
    ui->runesPoids7Button->setIcon(runes7ButtonIcon);
    ui->runesPoids7Button->setIconSize(QSize(w,h));

    QPixmap runes10Png(":/new/images/runes10.png");
    QIcon runes10ButtonIcon(runes10Png);
    ui->runesPoids10Button->setIcon(runes10ButtonIcon);
    ui->runesPoids10Button->setIconSize(QSize(w,h));

    QPixmap runes20Png(":/new/images/runes20.png");
    QIcon runes20ButtonIcon(runes20Png);
    ui->runesPoids20Button->setIcon(runes20ButtonIcon);
    ui->runesPoids20Button->setIconSize(QSize(w,h));

    QPixmap runes30Png(":/new/images/runes30.png");
    QIcon runes30ButtonIcon(runes30Png);
    ui->runesPoids30Button->setIcon(runes30ButtonIcon);
    ui->runesPoids30Button->setIconSize(QSize(w,h));

    QPixmap runes51Png(":/new/images/runes51.png");
    QIcon runes51ButtonIcon(runes51Png);
    ui->runesPoids51Button->setIcon(runes51ButtonIcon);
    ui->runesPoids51Button->setIconSize(QSize(w,h));

    QPixmap runes90Png(":/new/images/runes90.png");
    QIcon runes90ButtonIcon(runes90Png);
    ui->runesPoids90Button->setIcon(runes90ButtonIcon);
    ui->runesPoids90Button->setIconSize(QSize(w,h));

    QPixmap runes100Png(":/new/images/runes100.png");
    QIcon runes100ButtonIcon(runes100Png);
    ui->runesPoids100Button->setIcon(runes100ButtonIcon);
    ui->runesPoids100Button->setIconSize(QSize(w,h));

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
    nomRune = "Pod";
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
    nomRune = "Pod";
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
    nomRune = "Pod";
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
    nomRune = "Do";
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
    nomRune = "Fo/Ine/Cha/Age/Vi/Ini";
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
    nomRune = "Fo/Ine/Cha/Age/Vi/Ini";
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
    nomRune = "Fo/Ine/Cha/Age/Vi/Ini";
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
    nomRune = "Pui Re Terre/Feu/Eau/Air/Neutre";
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
    nomRune = "Pui Re Terre/Feu/Eau/Air/Neutre";
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
    nomRune = "Pui Re Terre/Feu/Eau/Air/Neutre";
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
    nomRune = "Sa";
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
    nomRune = "Sa";
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
    nomRune = "Sa";
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
    nomRune = "Prospe";
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
    nomRune = "Prospe";
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
    nomRune = "Tacle/Fuite";
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
    nomRune = "Tacle/Fuite";
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
    nomRune = "Re Pou/Cri/Do Terre/Neutre/Feu/Air/Eau/Pou/Cri/Pi";
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
    nomRune = "Re Pou/Cri/Do Terre/Neutre/Feu/Air/Eau/Pou/Cri/Pi";
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
    nomRune = "Re Per Air/Terre/Feu/Eau/Neutre";
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
    nomRune = "Re Pa / Re Pm / Ret Pa / Ret Pm";
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
    nomRune = "Re Pa / Re Pm / Ret Pa / Ret Pm";
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
    nomRune = "So / Cri / Do Ren";
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
