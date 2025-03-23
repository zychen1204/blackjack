# Rules and Gameplay:

## 1. Human Players:
First, I will ask how many human players are participating:

- **How many humans?** (>=0)

For example, if the answer is 2, I will then ask:
1. **What's the human's name?** (Enter the person's name)
2. **What's the human's bankroll?** (Enter their bankroll)

## 2. Meek Computers:
- **How many Meek computers?** (Ask how many Meek computers are there)
  - **What's the Meek computer's name?** (Enter their name)
  - **What's the Meek computer's bankroll?** (Enter their bankroll)

## 3. Random Computers:
- **How many Random computers?** (>=0)
  - **What's the Random computer's name?** (Enter their name)
  - **What's the Random computer's bankroll?** (Enter their bankroll)

For example:

| **Player Type**     | **Name**   | **Bankroll**  |
|---------------------|------------|---------------|
| **Human**           | Bob        | 100           |
| **Meek computer**   | Mike       | 300           |
| **Random computer** | Rob        | 400           |
| **Dealer**          | Dealer     | 10000         |

## 4. Betting Phase:
Now, the game starts, and I will print:

**Okay, time for betting!**
--------------------------------

Then I will ask each human player how much they would like to bet. For example, for Bob:

- **Bob, how much would you like to bet?** (>=1)

As for the computers, their betting is determined by the rules:
- **Meek computers**: After winning 3 rounds consecutively, they double their bet.
- **Random computers**: The bet is randomly chosen to be between 1 and half of their bankroll.

## 5. Initial Cards:
After everyone has confirmed their bets, the initial cards are printed. The first card is hidden ([??]), and the second is visible (where JQK are displayed with their suit).
- **D:diamond**
- **S:spade**
- **C:club**
- **H:heart**

**The initial starting cards are:**
-----------------------------------------
Then it will display:


- **Bob's current hand: [??] [QD]**  
- **Mike's current hand: [??] [10H]**  
- **Rob's current hand: [??] [5C]**  
- **Dealer's current hand: [??] [6C]**

## 6. Human Player's Turn:
Since Bob is a human player, I will ask whether to continue drawing cards. For example, for Bob:

- **Bob's current hand: [AS] [QD]** (11 points)  
- **Would you like to draw another card? (Y or N)**

If the response is 'Y', the following will be printed:
- **Bob chooses to draw.**  
Then the updated hand is displayed:
- **Bob's current hand: [AS] [QD] [KD]** (21 points)

I will ask again:
- **Would you like to draw another card? (Y or N)**

If the answer is 'N', the output will be:
- **Bob chooses to stay.**

If the player busts, for example:
- **Bob's current hand: [QS] [QD] [KD]** (30 points)  
The output will be:
- **Bob busted at 23!**

## 7. Computer Players' Turns:
After the human player’s turn, the computers draw cards based on these rules:

- **Meek**: Draws if the total points are even; does not draw if the total is odd.
- **Random**:
  - If total points <= 12: 80% chance to draw
  - If total points >= 13 and <= 15: 70% chance to draw
  - If total points >= 16 and <= 18: 50% chance to draw
  - If total points >= 19: Does not draw
- **Dealer**:
  - If total points <= 16: Draws
  - If total points >= 17: Does not draw

## 8. Determining the Winner:
After all players have played their turns, I will determine the winner based on the highest points. If more than one player has the highest points, all of them lose, and only the dealer wins.

For example:

- **Bob**: 21 points (bet $50) – Bankroll: $100
- **Mike**: 15 points (bet $2) – Bankroll: $300
- **Rob**: 17 points (bet $11) – Bankroll: $400
- **Dealer**: Busted – Bankroll: $10,000

In this round, Bob wins because he has the highest points. The output will be:

**Yowzah! Bob wins $50**

The two computers lose:

- **Ouch! Mike loses $2**  
- **Ouch! Rob loses $11**

The dealer loses 37 (since 50 - 2 - 11 = 37), and after updating the standings:

**The standings so far:**
------------------------------  
**Bob** $150  
**Mike** $298  
**Rob** $389  
**Dealer** $9963

## 9. Another Round?
Finally, I will ask:

**Another round? (Y or N)**

- If the answer is 'Y', the game continues with the same bankroll.  
- If the answer is 'N', the game ends.
