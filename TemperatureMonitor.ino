#include <Arduino.h>  // Inclui a biblioteca principal do Arduino

#define TEMP_THRESHOLD 30
#define LED_PIN 2

void setup() {
    pinMode(LED_PIN, OUTPUT);  // Configura o pino do LED como saída
    Serial.begin(9600);  // Inicializa a comunicação serial
}

void loop() {
    int sensorValue = analogRead(A0);  // Lê o valor do sensor no pino A0
    float temperature = (sensorValue * 5.0 / 1024.0) * 100.0;  // Converte para temperatura

    Serial.print("Temperatura: ");
    Serial.println(temperature);

    if (temperature > TEMP_THRESHOLD) {
        digitalWrite(LED_PIN, HIGH);  // Liga o LED
    } else {
        digitalWrite(LED_PIN, LOW);  // Desliga o LED
    }

    delay(500);  // Aguarda 500ms
}
