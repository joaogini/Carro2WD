//Permite usar outras portas como RX e TX.
#include <SoftwareSerial.h>
int pinoRX = 2; //Porta RX do Arduino
int pinoTX = 3; //Porta TX do Arduino
int led = 4;  //Porta LED1
int buzzer = 11;

int motor1f = 5;
int motor1t = 6;
int motor2f = 9;
int motor2t = 10;

int velocidade = 0;

char instrucao; //Variavel que vai receber as instruções

//Define pinos das variáveis como RX E TX
SoftwareSerial bluetooth(pinoRX, pinoTX);

void setup() {
  pinMode(led, OUTPUT); //Pino LED1 como saída
  pinMode(buzzer, OUTPUT); 
  pinMode(motor1f, OUTPUT);
  pinMode(motor1t, OUTPUT);
  pinMode(motor2f, OUTPUT);
  pinMode(motor2t, OUTPUT);
  
  bluetooth.begin(9600); //Velocidade de comunicação HC-05
  delay(100); //Aguarda 100ms para iniciar bluetooh
}

void loop() {
  if (bluetooth.available() > 0) { //Verifica se há atividade no bluetooth
    instrucao = bluetooth.read();  //Grava comando na var instrucao
  }
  
  //Função Velocidade
  if (instrucao == '0') {
  velocidade = 0;   
    velocidade = map(velocidade, 0, 10, 0, 255);
  }
  else if (instrucao == '1') {
    velocidade = 1;   
    velocidade = map(velocidade, 0, 10, 0, 255);
  }
  else if (instrucao == '2') {
    velocidade = 2;   
    velocidade = map(velocidade, 0, 10, 0, 255);
  }
  else if (instrucao == '3') {
    velocidade = 3;   
    velocidade = map(velocidade, 0, 10, 0, 255);
  }
  else if (instrucao == '4') {
    velocidade = 4;   
    velocidade = map(velocidade, 0, 10, 0, 255);
  }
  else if (instrucao == '5') {
    velocidade = 5;   
    velocidade = map(velocidade, 0, 10, 0, 255);
  }
  else if (instrucao == '6') {
    velocidade = 6;   
    velocidade = map(velocidade, 0, 10, 0, 255);
  }
  else if (instrucao == '7') {
    velocidade = 7;   
    velocidade = map(velocidade, 0, 10, 0, 255);
  }
  else if (instrucao == '8') {
    velocidade = 8;   
    velocidade = map(velocidade, 0, 10, 0, 255);
  }
  else if (instrucao == '9') {
    velocidade = 9;   
    velocidade = map(velocidade, 0, 10, 0, 255);
  }
  else if (instrucao == 'q') {
    velocidade = 10;    
    velocidade = map(velocidade, 0, 10, 0, 255);
  }

  //Funções de Movimentos 
  //Motor1 = Esquerda
  //Motor2 = Direita
  if (instrucao == 'F') { // Movimento para frente
    analogWrite(motor1f, velocidade);
    analogWrite(motor2f, velocidade);
    analogWrite(motor1t, 0);
    analogWrite(motor2t, 0);
  }
  else if (instrucao == 'B') { // Movimento para trás
    analogWrite(motor1f, 0);
    analogWrite(motor2f, 0);
    analogWrite(motor1t, velocidade);
    analogWrite(motor2t, velocidade);
  }
  else if (instrucao == 'L') { // Movimento para esquerda
  analogWrite(motor1f, 0);
    analogWrite(motor2f, velocidade);
    analogWrite(motor1t, velocidade);
    analogWrite(motor2t, 0);
  }
  else if (instrucao == 'R') { // Movimento para Direita
    analogWrite(motor1f, velocidade);
    analogWrite(motor2f, 0);
    analogWrite(motor1t, 0);
    analogWrite(motor2t, velocidade);
  }
  else if (instrucao == 'G') { // Movimento Frente Esquerda
    analogWrite(motor1f, 0);
    analogWrite(motor2f, velocidade);
    analogWrite(motor1t, 0);
    analogWrite(motor2t, 0);
  }
  else if (instrucao == 'I') { // Movimento Frente Direita
    analogWrite(motor1f, velocidade);
    analogWrite(motor2f, 0);
    analogWrite(motor1t, 0);
    analogWrite(motor2t, 0);
  }
  else if (instrucao == 'H') { // Movimento Trás Esquerda
    analogWrite(motor1f, 0);
    analogWrite(motor2f, 0);
    analogWrite(motor1t, 0);
    analogWrite(motor2t, velocidade);
  }
  else if (instrucao == 'J') { // Movimento Trás Direita
    analogWrite(motor1f, 0);
    analogWrite(motor2f, 0);
    analogWrite(motor1t, velocidade);
    analogWrite(motor2t, 0);
  }
  
  //Função para parar os movimentos
  if (instrucao == 'S') {    //Se for S
    digitalWrite(motor1f, LOW);
    digitalWrite(motor2f, LOW);
    digitalWrite(motor1t, LOW);
    digitalWrite(motor2t, LOW);
  }

  //Função Faróis
  if (instrucao == 'W') { //Acender faróis dianteiros
    digitalWrite(led, HIGH); //Liga LEDs
  }
  else if (instrucao == 'w') { //Apagar faróis dianteiros
    digitalWrite(led, LOW); //Desliga LEDs
  }

  //Função Buzina
  if (instrucao == 'V') {
    tone(buzzer, 1200); //liga buzina
  }
  else if (instrucao == 'v') {
    noTone(buzzer); //Desliga buzina
  }
  
}
