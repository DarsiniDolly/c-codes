#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define deck_size 52
#define hand_size 7

enum Color {
    red,
    blue,
    green,
    yellow
};

enum Value {
    zero,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    skip,
    reverse,
    taketwo,
    wild,
    wild_takefour
};

struct Card {
    enum Color color;
    enum Value value;
};

struct Player {
    struct Card hand[hand_size];
    int numCards;
};

struct Card deck[deck_size];
struct Card discardPile[deck_size];
int deckIndex = 0;
int discardPileIndex = 0;
struct Player players[2];
int currentPlayer = 0;

void initializeDeck() {
    int cardIndex = 0;
    for (int color = red; color <= yellow; color++) {
        for (int value = zero; value <= wild_takefour; value++) {
            deck[cardIndex].color = color;
            deck[cardIndex].value = value;
            cardIndex++;
        }
    }
}

void shuffleDeck() {
    srand(time(NULL));
    for (int i = 0; i < deck_size - 1; i++) {
        int j = i + rand() / (RAND_MAX / (deck_size - i) + 1);
        struct Card temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

void dealInitialCards() {
    for (int i = 0; i < hand_size; i++) {
        players[0].hand[i] = deck[deckIndex++];
        players[1].hand[i] = deck[deckIndex++];
    }
    players[0].numCards = hand_size;
    players[1].numCards = hand_size;
}

void printCard(struct Card card) {
    const char* colorStr;
    switch (card.color) {
        case red:
            colorStr = "Red";
            break;
        case yellow:
            colorStr = "Yellow";
            break;
        case green:
            colorStr = "Green";
            break;
        case blue:
            colorStr = "Blue";
            break;
    }

    const char* valueStr;
    switch (card.value) {
        case zero:
            valueStr = "0";
            break;
        case one:
            valueStr = "1";
            break;
        case two:
            valueStr = "2";
            break;
        case three:
            valueStr = "3";
            break;
        case four:
            valueStr = "4";
            break;
        case five:
            valueStr = "5";
            break;
        case six:
            valueStr = "6";
            break;
        case seven:
            valueStr = "7";
            break;
        case eight:
            valueStr = "8";
            break;
        case nine:
            valueStr = "9";
            break;
        case skip:
            valueStr = "Skip";
            break;
        case reverse:
            valueStr = "Reverse";
            break;
        case taketwo:
            valueStr = "Take two";
            break;
        case wild:
            valueStr = "Wild";
            break;
        case wild_takefour:
            valueStr = "Wild take Four";
            break;
    }
    printf("Color: %s, Value: %s\n", colorStr, valueStr);
}

int main() {
    initializeDeck();
    shuffleDeck();
    dealInitialCards();
    // Example to print the cards in each player's hand
    for (int i = 0; i < 2; i++) {
        printf("Player %d's Hand:\n", i + 1);
        for (int j = 0; j < players[i].numCards; j++) {
            printf("Card %d: ", j + 1);
            printCard(players[i].hand[j]);
        }
        printf("\n");
    }
    return 0;
}
