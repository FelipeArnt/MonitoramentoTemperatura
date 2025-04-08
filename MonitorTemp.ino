#include <Arduino.h>  // Inclui a biblioteca principal do Arduino

#define TEMP_LIMITE 30 // Definição do valor limite da temperatura
#define LED_PIN 2

void setup() {
    pinMode(LED_PIN, OUTPUT);  // Configura o pino do LED como saída
    Serial.begin(9600);       // Inicializa a comunicação serial -> BaudRate
}

void loop() {
    int valorSensor = analogRead(A0);  // Lê o valor do sensor no pino A0
    float temperatura = (valorSensor * 5.0 / 1024.0) * 100.0;  // Converte para temperatura em Celsius

    Serial.print("Temperatura: ");
    Serial.println(temperatura);

    if (temperatura > TEMP_LIMITE) {
        digitalWrite(LED_PIN, HIGH);  // Liga o LED
    } else {
        digitalWrite(LED_PIN, LOW);  // Desliga o LED
    }

    delay(500);  // Aguarda 500ms
}
