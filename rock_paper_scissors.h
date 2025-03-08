#ifndef ROCK_PAPER_SCISSORS_H
#define ROCK_PAPER_SCISSORS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Rock_Paper_Scissors;
}
QT_END_NAMESPACE

enum Choice { ROCK, PAPER, SCISSORS };

class Rock_Paper_Scissors : public QMainWindow
{
    Q_OBJECT

public:
    Rock_Paper_Scissors (QWidget *parent = nullptr);
    ~Rock_Paper_Scissors ();

private slots:
    void on_rockButton_clicked();
    void on_paperButton_clicked();
    void on_scissorsButton_clicked();
    void on_playAgainButton_clicked();

private:
    Ui:: Rock_Paper_Scissors *ui;
    void playGame(Choice playerChoice);
    Choice getComputerChoice();
    QString determineWinner(Choice playerChoice, Choice computerChoice);

    int numGames;
    int playerWins;
    int computerWins;
    int numTies;
};

#endif // ROCK_PAPER_SCISSORS_H
