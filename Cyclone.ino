/***************************RULES*****************************/
//the light goes from right to left and the first player
//to press the button while the light on his side is on
//gets a point, first player to reach 5 points wins the game
/************************************************************/
int led[10] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};          //to intailaize the led to pin
int button1 = 2;                                          //button for first player
int button2 = 13;                                         //button for second player
int B1_state = 0;                                         //record the state of button for first player
int B2_state = 0;                                         //record the state of button for second player
int score1 = 0;                                           //counter for first player
int score2 = 0;                                           //counter for second player

void setup() {
  //incase of debugging but not used in the program
  Serial.begin(9600);
  for (int i = 0; i < 10; i++) {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], LOW);
  }
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  //delay(100);
  //the light goes from right to left
  for (int i = 0; i <= 9; i++) {
    digitalWrite(led[i], HIGH);
    for (int j = 1; j <= 30 ; j++) {
      B1_state = digitalRead(button1);
      B2_state = digitalRead(button2);
      //if statement to check if the button is pressed or not and RETURNED not STILL pressed
      if (B1_state == HIGH && i == 0) {
        score1++;
        //to check if the player reached the score limit
        if (score1 <= 5) {
          //two loop to make the light on the player's side blink about his score
          //Exp. if the player's score is 2, then the led will blink for two times
          for (int s = 1; s <= score1 ; s++) {
            for (int i = 0; i <= 4; i++) {
              digitalWrite(led[i], HIGH);
            }
            delay(1000);
            for (int i = 0; i <= 4; i++) {
              digitalWrite(led[i], LOW);
            }
            delay(1000);
          }
          //if one of the two player reached 5 points , then this player wins and the score
          //is reset for each player to 0 to start new game
        } else {
          score1 = 0;
          score2 = 0;
        }
      }
      else if (B2_state == HIGH && i == 9) {
        score2++;
        if (score2 <= 5) {
          for (int s = 1; s <= score2 ; s++) {
            for (int i = 5; i <= 9; i++) {
              digitalWrite(led[i], HIGH);
            }
            delay(1000);
            for (int i = 5; i <= 9; i++) {
              digitalWrite(led[i], LOW);
            }
            delay(1000);
          }
        } else {
          score1 = 0;
          score2 = 0;
        }
      }
      delay(1);
    }
    digitalWrite(led[i], LOW);
  }
  //light goes from left to right (returns)
  for (int i = 9; i >= 0; i--) {
    digitalWrite(led[i], HIGH);
    for (int j = 1; j <= 30 ; j++) {
      B1_state = digitalRead(button1);
      B2_state = digitalRead(button2);
      if (B1_state == HIGH && i == 0) {
        score1++;
        if (score1 <= 5) {
          for (int s = 1; s <= score1 ; s++) {
            for (int i = 0; i <= 4; i++) {
              digitalWrite(led[i], HIGH);
            }
            delay(1000);
            for (int i = 0; i <= 4; i++) {
              digitalWrite(led[i], LOW);
            }
            delay(1000);
          }
        } else {
          score1 = 0;
          score2 = 0;
        }
      }
      else if (B2_state == HIGH && i == 9) {
        score2++;
        if (score2 <= 5) {
          for (int s = 1; s <= score2 ; s++) {
            for (int i = 5; i <= 9; i++) {
              digitalWrite(led[i], HIGH);
            }
            delay(1000);
            for (int i = 5; i <= 9; i++) {
              digitalWrite(led[i], LOW);
            }
            delay(1000);
          }
        } else {
          score1 = 0;
          score2 = 0;
        }
      }
      delay(1);
    }
    digitalWrite(led[i], LOW);
  }
}
