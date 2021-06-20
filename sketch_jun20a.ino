/*Interface criada para simular o laboratorio onde os leds simular a 
 * lampada e a contatora(liga a bancada de trabalho),e dois botoes 
 * simulam o sensor da porta e da janela interface criada com o 
 * arduino uno e dois leds e duas chaves normalmente fechada do 
 * resistor de pull up.
 * Ctriado pro Maurici Baron 20-06-2021
 */


int lampada = 13;         // Liga a lampada do laboratorio digital 13
int contatora = 12;      // Liga a bancada do laboratorio digital 13
int porta = 11;         // sensor da porta pino digital 7
int janela = 10;       // sensor da janela pino digital 13

void setup() {
  pinMode(lampada, OUTPUT);    // configura o pino digital 13 como saída
  pinMode(contatora, OUTPUT); // configura o pino digital 12 como saída
  pinMode(porta, INPUT);     // configura o pino digital 11 como entrada
  pinMode(janela, INPUT);   // configura o pino digital 10 como entrada
  Serial.begin(9600);      // inicia a porta serial, configura a taxa de dados para 9600 bps
}

void loop() {
 if (Serial.available())        //verifica se tem dados diponível para leitura
  { 
    switch (Serial.read()) {  //le serial mais recente no buffer da serial
      case 'l':
        digitalWrite(lampada,HIGH); //aciona a lampada
      break;
      case 'c':
        digitalWrite(contatora,HIGH);  // aciona a contadora
       break;
      case 'a':
        digitalWrite(contatora,LOW);  // desliga a contatora
       break;
       case 'b':
        digitalWrite(lampada,LOW);  // desliga a lampada
       break;
      }    
  }
  delay(100);
  if(digitalRead(porta)!=LOW){ //verifica se a porta esta aberta
    delay(100);
    //Serial.write("Porta aberta");   //reenvia para o computador o dado 1
     Serial.println('1');
  }
   delay(100);
  if(digitalRead(janela)!=LOW){ // verifica se a janela esta aberta
    delay(100);
    Serial.println('2'); //reenvia para o computador o dado 2
  }
}
