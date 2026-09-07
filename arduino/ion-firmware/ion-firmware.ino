#define MOTOR_A 9
#define MOTOR_B 10
#define SELECTOR 7
#define LED_SPA 12
#define LED_POOL 13
#define LED_INVERSION 4


bool invert = false;
unsigned long stateSec = 0; 
const long stop = 5000; 

void setup() 
{
  for( int i = 7; i <= 13; i++ )
  {
      pinMode(i, OUTPUT);
  }

  pinMode( SELECTOR, INPUT_PULLUP );
  pinMode( LED_SPA, OUTPUT );
  pinMode( LED_POOL, OUTPUT );
  pinMode( LED_INVERSION, OUTPUT );
}

void loop() 
{
  unsigned long timer = millis();

  
  if (timer - stateSec >= stop) {
    stateSec = timer;
    invert = !invert; // Correção da inversão booleana
  }

  // LÓGICA DO SELETOR 0
  if( digitalRead( SELECTOR ) == 0 )
  {
    digitalWrite( LED_POOL, HIGH );
    digitalWrite( LED_SPA,  LOW );

    if( invert == false )
    {
       digitalWrite( MOTOR_A, LOW );
       digitalWrite( MOTOR_B, HIGH );
       digitalWrite( LED_INVERSION, HIGH );
    }
    else
    {
       digitalWrite( MOTOR_A, HIGH );
       digitalWrite( MOTOR_B, LOW );
       digitalWrite( LED_INVERSION, LOW );
    }
  }
  else 
  {
    digitalWrite( LED_POOL, LOW );
    digitalWrite( LED_SPA,  HIGH );

    if( invert == false )
    {
       analogWrite( MOTOR_A, 255 );
       digitalWrite( MOTOR_B, LOW );
       digitalWrite( LED_INVERSION, HIGH );
    }
    else
    {
       digitalWrite( MOTOR_A, LOW );
       analogWrite( MOTOR_B, 255 );
       digitalWrite( LED_INVERSION, LOW );
    }
  }
}
