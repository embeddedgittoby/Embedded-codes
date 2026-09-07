
int binary_buffer[8];
const int port_buffer[8]={ 2,3,4,5,6,7,8,9 }; /*This is const because it never change*/

void printBinaryAndPorts( const int portBuffer[8], int binaryBuffer[8] ) /*Just an ordinary function to display*/
{
    Serial.println("###########START##########");
    for( int i = 0; i < 8; i++ )
    {
      Serial.print("Port: ");
      Serial.print( portBuffer[i] );
      Serial.print(" | Value: ");
      Serial.println( binaryBuffer[i] );  
    }
    Serial.println("###########END##########");

}


void setup()
{

  for(int i=0; i < 8; i++ ) pinMode( port_buffer[i], OUTPUT ); /*setup all the ports*/
  Serial.begin( 9600 ); /*setup UART protocol*/

}

void loop() 
{

  if( Serial.available() ) /*It only do the code if something pass through UART*/
  {
    int number = Serial.parseInt(); 
    Serial.read();

    for( int i = 0 ; i < 8; i++  )
    {
      binary_buffer[i] = bitRead(number, i); /*Convert all the numbers to byte*/
    }    

    for( int i = 0; i < 8; i++ )
    {
      
        digitalWrite( port_buffer[i], binary_buffer[i] ); /*send to port HIGH or LOW state*/
    }
    printBinaryAndPorts( port_buffer, binary_buffer);
  }
}
