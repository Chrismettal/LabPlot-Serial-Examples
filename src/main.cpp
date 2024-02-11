// ----------------------------------------------------------------------------
//  Inclusions
// ----------------------------------------------------------------------------
#include <Arduino.h>

// ----------------------------------------------------------------------------
//  Parameters
// ----------------------------------------------------------------------------
#define BAUDRATE  9600  // Serial baudrate
#define SEPERATOR ","   // Seperator between multiple ASCII values in multiASCII mode
#define INTERVAL  1000  // Send interval in milliseconds

// Mode, choose one.
const uint8_t mode = singleASCII;
enum mode {
  singleASCII,  // --> One ASCII value every INTERVAL. No Newline or seperator. 9 decimals.
  multiASCII,   // --> ASCII CSV of several values every INTERVAL. separated by SEPERATOR. 9 decimals.
  singleBinay,  // --> One binary value every INTERVAL. Formatted TODO
  multiBinary   // --> Several binary values every INTERVAL. Formatted TODO
};

// ----------------------------------------------------------------------------
//  Declarations
// ----------------------------------------------------------------------------
uint16_t counter = 0;
uint16_t value_1 = 0;
uint16_t value_2 = 0;
uint16_t value_3 = 0;
uint16_t value_4 = 0;

const float sinePeriod = 20;  // sine period for value_2 and value_3 in seconds
const float phaseShift = 2;   // phaseShift for value_3 in seconds

// ----------------------------------------------------------------------------
//  Function prototypes
// ----------------------------------------------------------------------------
void send_singleASCII();
void send_multiASCII();
void send_singleBinary();
void send_multiBinary();

// ----------------------------------------------------------------------------
//  Setup
// ----------------------------------------------------------------------------
void setup() {
  //Initialize serial:
  Serial.begin(BAUDRATE);
}

// ----------------------------------------------------------------------------
//  Loop
// ----------------------------------------------------------------------------
void loop() {

  // Increment counter
  counter++;

  // Calculate some fake values
  value_1 = counter * INTERVAL / 1000;
  value_2 = sin((2 * PI /sinePeriod) *  value_1);
  value_3 = sin((2 * PI /sinePeriod) * (value_1 + phaseShift));
  value_4 = value_2 * -0.5;

  // Send value(s) with mode chosen at compile time
  switch (mode) {
    case singleASCII:
      send_singleASCII();
      break;

    case multiASCII:
      send_multiASCII();
      break;

    case singleBinay:
      send_singleBinary();
      break;

    case multiBinary:
      send_multiBinary();
      break;
  }


  // Wait a second before dumping next line
  delay(INTERVAL);
}

// ----------------------------------------------------------------------------
//  Function definitions
// ----------------------------------------------------------------------------
void send_singleASCII() {
  // Print out value_2 as ASCII string
  // Example:
  // "0.1234567890\r\n"
  Serial.println(value_2, 9);
}

void send_multiASCII() {
  // Print out value_1 through 4 as CSV like ASCII string 
  // Example:
  // "0.1234567890,0.1234567890,0.1234567890,0.1234567890\r\n"
  Serial.print(value_1, 9);
  Serial.print(SEPERATOR);
  Serial.print(value_2, 9);
  Serial.print(SEPERATOR);
  Serial.print(value_3, 9);
  Serial.print(SEPERATOR);
  Serial.print(value_4, 9);
  Serial.print(SEPERATOR);
  Serial.println();
}

void send_singleBinary() {
  ; // TODO
}

void send_multiBinary() {
  ; // TODO
}