//define the pin for push button and the LED (in this case, we are using built-in LED)
//we are declaring the pin numbers as contants with the data-type unsigned 8-bit integer
//using unsigned 8-bit integer ensures that the constant occupies only 1-byte of memory which is sufficient for pin number when resources are limited
//using unsigned 8-bit integer as data type ensures that the value is between 0 and 255
const uint8_t BTN_PIN = 2;
const uint8_t LED_PIN = 13;

//Declaring and intializing variables with the data type unsigned 8-bit integer
//the initial state of the button and the LED is LOW i.e. neither the push button nor the LED has been turned on
uint8_t buttonPrevState = LOW;
uint8_t ledState = LOW;

//using the setup function to perform tasks that need to be executed once at the beginning of the program
void setup()
{
  //configure the BTN_PIN as input pin with pullup resistor enabled which ensures that the button is in a high state until it is not driven LOW actively
  //INPUT_PULLUP mode overrides the default state of the pin (set as LOW) and configures it to HIGH by default
  pinMode(BTN_PIN, INPUT_PULLUP);
  //Configure the LED_PIN as an output pin
  pinMode(LED_PIN, OUTPUT);
  //initialize serial communication with a baud rate of 9600 bits per second 
  //sets up a serial communication channel allowing the micrcontroller to communicate with an external device (eg. laptop)
  Serial.begin(9600);
}

void loop()
{
  //record the state of the push button using the digitalRead function and store it in the buttonState variable
  uint8_t buttonState = digitalRead(BTN_PIN);
  
  //print the ASCII value of variables buttonState, buttonPrevState and ledState on the serial monitor
  //Serial.print() is used to send data from the microcontroller to the computer for monitoring or debugging purposes
  Serial.print(buttonState);
  Serial.print(buttonPrevState);
  Serial.print(ledState);
  Serial.println("");
  
  
  //if statement t toggle the LED based on the state of the button
  //if the current button state is not equal to the previous button state i.e. either the button has been turned OFF or ON, the if statement is executed
  if(buttonState != buttonPrevState)
  {
    //toggles the LED 
    //if the led was in a LOW state, it will be turned HIGH
    //if the led was in a HIGH state, it will be turned LOW
    ledState = !ledState;
    //write the value of the ledState to the LED_PIN to turn it ON or OFF according to the status of the ledState variable
    digitalWrite(LED_PIN, ledState);
  }
  
  buttonPrevState = buttonState;
    
  //add a delay of 500 milliseconds to debounce the input and reduce CPU load allowing it to rest for a brief while
  delay(500);
}
