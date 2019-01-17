void peep(unsigned int value, int duration){
  /*
   * Peep function:
   * Input: 
   *   - Value: Unsigned Integer 0 - inf (Delay)
   *   - Duration: Integer 0 - inf (Milliseconds)
   * Output
   *   - None
   * Makes the speaker sound
   */

   if (value == 0){
    CustomDelay(duration);
   } else {
     int milis = value / 1000;
     int times = duration / milis;
     for (int i=0; i<times; i++){
        CustomMicroDelay(value/2);
        analogWrite(2, 0);
        CustomMicroDelay(value/2);
        analogWrite(2, 255);
     }
   }
}

void drawNote(String songName){
  /*
   * Draw Note function:
   * Input:
   *   - Note: String (C, D, E, F, G, A, B)
   *   - Song Name: String
   * Output:
   *   - None
   * Draws the note on the OLED screen
   */
  display.drawRect(20, 8, display.width()-40, display.height()-2, WHITE);
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(30,0);
  display.println(songName);
  display.setTextSize(3);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(40,10);
  display.println("H&R");
  display.display();
}

void playSong(int frequencies[], int sequence[], int sequenceSize,  int noteDuration[], String title, String noteNames[], bool displayScreen){
  /*
   * Play Song function:
   * Input:
   *  - Integer Array Frequencies: array of all the frequencies that are used in the song
   *  - Integer Array Sequence: array of notes in the song order
   *  - Integer Sequence Size: size of the sequence array
   *  - Integer Array Note Duration: array of durations in the same order as the Sequence array
   *  - String Array Note Names: array of names of the notes in the same order as the Frequencies array
   *  - String Title: string which contains the title of the song. This title will bes displayed on the screen is desplayScreen == true
   *  - Boolean Display Screen: boolean to indicate wether the notes have to be displayed on the screen
   * Plays a song. If you want pauses use standrad frequency named "PAUSE"
   */

   if(displayScreen){
     drawNote(title);
   }
   
   for (int i=0; i < sequenceSize; i++){
//      if(lightSensorThread.shouldRun()){
//        lightSensorThread.run();
//      }
//        tone(2, frequencies[sequence[i]], noteDuration[i]); 
      peep(frequencies[sequence[i]], noteDuration[i]);
      if(displayScreen){
        display.clearDisplay();
      }
      refreshMotors();
//      checkLightSensors();
   }
}
