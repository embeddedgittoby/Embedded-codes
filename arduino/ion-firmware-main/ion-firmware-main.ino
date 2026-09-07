#define PORT_OUT_A 9
#define PORT_OUT_B 10

#define LED_ION 11


void setup() {
  // put your setup code here, to run once:

  pinMode( PORT_OUT_A, OUTPUT );
  pinMode( PORT_OUT_B, OUTPUT );
  pinMode( LED_ION, OUTPUT );
  
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite( PORT_OUT_A, HIGH );
  digitalWrite( PORT_OUT_B, LOW );
  digitalWrite( LED_ION, HIGH );
  delay(300000);
  digitalWrite( PORT_OUT_A, LOW );
  digitalWrite( PORT_OUT_B, HIGH );
  digitalWrite( LED_ION, LOW );
  delay(300000);
}
