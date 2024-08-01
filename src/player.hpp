class Player{
public:

    Player(int id, int money){
        this -> id = id;
        this -> money = money;
    }

    std::pair< Card, Card > getHand(){
        return {card1, card2};
    }

    int getMoney(){
        return money;
    }

    int getId(){
        return id;
    }

    void get_new_hand(Card c1, Card c2){
        card1 = c1;
        card2 = c2;
    }

private:
    int id;
    int money;
    Card card1, card2;
};