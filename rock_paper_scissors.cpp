#include "Rock_Paper_Scissors.h"
#include "ui_Rock_Paper_Scissors.h"
#include <QRandomGenerator>
#include <QString>

Rock_Paper_Scissors:: Rock_Paper_Scissors (QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Rock_Paper_Scissors)
    , numGames(0)
    , playerWins(0)
    , computerWins(0)
    , numTies(0)
{
    ui->setupUi(this);
}

Rock_Paper_Scissors::~ Rock_Paper_Scissors ()
{
    delete ui;
}

void Rock_Paper_Scissors::on_rockButton_clicked()
{
    playGame(ROCK);
}

void Rock_Paper_Scissors::on_paperButton_clicked()
{
    playGame(PAPER);
}

void Rock_Paper_Scissors::on_scissorsButton_clicked()
{
    playGame(SCISSORS);
}

void Rock_Paper_Scissors::on_playAgainButton_clicked()
{
    // Reset the result label for the next game
    ui->resultLabel->clear();
}

void Rock_Paper_Scissors::playGame(Choice playerChoice)
{
    Choice computerChoice = getComputerChoice();
    QString result = determineWinner(playerChoice, computerChoice);

    // Update the result label
    ui->resultLabel->setText("Computer chose: " + QString::number(computerChoice) + "\n" + result);

    // Update final results
    numGames++;
    if (result.contains("You win")) {
        playerWins++;
    } else if (result.contains("The computer wins")) {
        computerWins++;
    } else {
        numTies++;
    }

    // Display final results
    ui->finalResultsLabel->setText(
        "Games played: " + QString::number(numGames) + "\n"
                                                       "You won: " + QString::number(playerWins) + "\n"
                                        "Computer won: " + QString::number(computerWins) + "\n"
                                          "Ties: " + QString::number(numTies)
        );
}

Choice Rock_Paper_Scissors::getComputerChoice()
{
    int choice = QRandomGenerator::global()->bounded(3);
    return static_cast<Choice>(choice);
}

QString Rock_Paper_Scissors::determineWinner(Choice playerChoice, Choice computerChoice)
{
    if (playerChoice == computerChoice) {
        return "It's a tie!";
    } else if ((playerChoice == ROCK && computerChoice == SCISSORS) ||
               (playerChoice == PAPER && computerChoice == ROCK) ||
               (playerChoice == SCISSORS && computerChoice == PAPER)) {
        return "You win!";
    } else {
        return "The computer wins!";
    }
}
