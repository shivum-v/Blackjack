# Blackjack

Initial game allows the following commands:
  1) 'game x' => Initializes a table with x chips. x is within the range (0, 1000]
  2) 'q' => Quits the program

Once entered into the game, the following commands are available:
  1) 'bet y' => Bets y chips into the following round. y is within the range (0, x]
  2) 'end' => Withdraws from the table

Each round allows the following actions:
  1) 'hit' => Draws one more card
  2) 'stick' => Human can not take any more cards
  3) 'ddown' => Short for double-down, dealer will draw one final card to human before turn is ended
  Note: 'split' and 'insurance' commands are currently being worked on

Dealer actions and round results are performed automatically after human turn
