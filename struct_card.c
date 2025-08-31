#include <stdio.h>
#include <assert.h>
#define DECKSIZE 52

struct Card {
    char rank;    // достоинство
    char suit;    // масть
};

int valid_card(struct Card * card);

void print_cards(struct Card * hand)
{
    struct Card * p;    // указатель на одну карту
    for(p = hand; p->rank != 0; p++)
        printf("%c%c", p->rank, p->suit);
    printf("\n");
}

void read_cards(struct Card * hand)
{
    struct Card * p;    // указатель на одну карту
    int count = 0;
    for(p = hand; count <= DECKSIZE && 2 == scanf("%c%c", &p->rank, &p->suit); p++) {
        count += 2;
        if (!valid_card(p))
            break;
    }
    // в конец положим фальшивую карту
    p->rank = p->suit = 0;
}

int valid_card(struct Card * card)
{
    char * const suit = "cshd";        // в строках в конце тоже есть "фальшивый" символ '\0'
    char * const rank = "23456789TJQKA";
    int i;
    for (i = 0; suit[i] != '\0'; i++)
        if (suit[i] == card->suit)      // масть такая существует
            break;
    if (suit[i] == '\0')                // в card->suit была неправильная масть
        return 0;


    for (i = 0; rank[i] != '\0'; i++)
        if (rank[i] == card->rank)      // достоинство такое существует
            return 1;                   // масть и достоинство существуют, карта правильная


    return 0;                           // в card->rank было неправильное достоинство
}

int check(struct Card *hand) {
	int res = 0;
	struct Card queen_of_spades = {'Q', 's'};
	struct Card *p;
	for (p = hand; p->rank != 0; p++) {
		if (p->rank == queen_of_spades.rank && p->suit == queen_of_spades.suit) {
			res = 1;
			break;
		}
	}
	return res;
}

int main()
{
    struct Card hand1 [] = {{'Q', 's'}, {'A','h'}, {'9', 'd'}, {0, 0}};
    struct Card hand2 [] = {{'2', 's'}, {'A','h'}, {0, 0}};
    assert(1 == check(hand1));
    assert(0 == check(hand2));

    return 0;
}

