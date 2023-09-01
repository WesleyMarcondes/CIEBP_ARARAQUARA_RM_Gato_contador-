//Programa: Gato contador CIEBP
//data: 01/09/2023
//Autor: CIEBP Araraquara
 
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h> // LCD biblioteca
#include <Ultrasonic.h> // ultrasoom bibilioteca
#include <VarSpeedServo.h> //servo biblioteca

VarSpeedServo myservo;    // cria o servo objeto para controlar o servo  
Ultrasonic ultrasonic(7, 6); // portas pino echo e trig
int distance; // variavel que armazena distancia do que ultrasoom lê
int contpessoas = 0; // variavel que armazena a contagem
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup(){
  Serial.begin(9600); //INICIALIZAÇÃO DA SERIAL               
  lcd.begin(16, 2);  //Define o número de colunas e linhas do LCD
  myservo.attach(9); // sedine porta dp objeto servo
}
 
void loop(){
 distance = ultrasonic.read(); // leitura do ultrassom na variavel distance
 Serial.print("Distance in CM: "); // printa no monitor serial
  Serial.println(distance); // mostra a variavel distancia no monitor serial
  
  if (distance <= 30){ // se a variavel distancia for menor que 30
      servo(); // chama a função servo
      cont(); //chama a função contagem
      } 
  LCD(); // chama a função LCD
 }

void servo(){ // função servo motor, defino posição e velocidade de ovimento
  
      myservo.write(100, 30, true);// inicio
      myservo.write(3, 30, true);  // meio
      myservo.write(100, 30, true); // fim do movimento do motor      
  }
  
void LCD(){ // funçao do LCD - oq vai ser mostrado e em qual sequencia 
  
  //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("Bem vindo");
  lcd.setCursor(0, 1);
  lcd.print("CIEBP Araraquara");
  //delay(2000);  
       
    } 
     
void cont(){ //função cont, é a contagem de pessoas

  contpessoas = contpessoas + 1; //adiciona mais um a variavel contpessoas//Limpa a tela
  //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(1, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("Contagem-CIEBP");
  lcd.setCursor(6, 1); 
  lcd.print(contpessoas,1);// mostras na tela o vaalor da variavel contpessoas
  delay(1000);
  
  }
