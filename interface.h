#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class Interface;
}

class Interface : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = 0);
    void Raz();
    ~Interface();

private slots:
    void on_runeSauteeCombo_currentIndexChanged(int index);

    void on_razButton_clicked();

    void on_runes2Poids5Button_clicked();

    void on_runes2Poids5PaButton_clicked();

    void on_runes2Poids5RaButton_clicked();

    void on_runesPoids20Button_clicked();

    void on_runesPoids1Button_clicked();

    void on_runesPoids1PaButton_clicked();

    void on_runesPoids1RaButton_clicked();

    void on_runesPoids2Button_clicked();

    void on_runesPoids2PaButton_clicked();

    void on_runesPoids2RaButton_clicked();

    void on_runesPoids3SaButton_clicked();

    void on_runesPoids3SaPaButton_clicked();

    void on_runesPoids3SaRaButton_clicked();

    void on_rune3ProspeButton_clicked();

    void on_rune3ProspePaButton_clicked();

    void on_runesPoids4Button_clicked();

    void on_runesPoids4PaButton_clicked();

    void on_runesPoids5Button_clicked();

    void on_runesPoids5PaButton_clicked();

    void on_runesPoids6Button_clicked();

    void on_runesPoids7Button_clicked();

    void on_runesPoids7PaButton_clicked();

    void on_runesPoids10Button_clicked();

    void on_runesPoids30Button_clicked();

    void on_runesPoids51Button_clicked();

    void on_runesPoids90Button_clicked();

    void on_runesPoids100Button_clicked();

private:
    Ui::Interface *ui;
    QMessageBox preambule;
    QStringList listeRunes;
    QString sousTotal, totalFinal,prefixe,nomRune;
    QMessageBox testMessageTotal;
    int indexRunes = 0,test = -1;
};

#endif // INTERFACE_H
