#include <avr/io.h>       // Inclui a biblioteca para acesso aos registradores do microcontrolador AVR
#include <util/delay.h>   // Inclui a biblioteca para funções de delay
#include "lcd.h"          // Inclui a biblioteca para controlar o LCD (assumindo que ela existe)

#define TEMP_THRESHOLD 30 // Define um limite de temperatura para acionar o alerta
#define LED_PIN PB0       // Define o pino onde o LED está conectado (pino PB0)

// Função para inicializar o ADC (Conversor Analógico-Digital)
void init_adc() {
    ADMUX = (1 << REFS0);  // Configura o ADC para usar AVCC como referência (tensão de 5V)
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);  // Habilita o ADC e configura o prescaler para 128
}

// Função para ler o valor do ADC em um canal específico
uint16_t read_adc(uint8_t channel) {
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);  // Configura o canal do ADC (0 a 7)
    ADCSRA |= (1 << ADSC);  // Inicia a conversão do ADC
    while (ADCSRA & (1 << ADSC));  // Espera a conversão ser concluída
    return ADC;  // Retorna o valor convertido (10 bits)
}

// Função principal
int main() {
    init_adc();  // Inicializa o ADC
    lcd_init();  // Inicializa o LCD
    DDRB |= (1 << LED_PIN);  // Configura o pino do LED como saída

    while (1) {  // Loop infinito
        uint16_t adc_value = read_adc(0);  // Lê o valor do ADC no canal 0 (onde o sensor está conectado)
        float temperature = (adc_value * 5.0 / 1024.0) * 100.0;  // Converte o valor do ADC para temperatura em Celsius

        lcd_clear();  // Limpa o LCD
        lcd_set_cursor(0, 0);  // Posiciona o cursor na primeira linha do LCD
        lcd_print("Temp: ");  // Exibe "Temp: " no LCD
        lcd_print_float(temperature);  // Exibe o valor da temperatura no LCD

        // Verifica se a temperatura ultrapassou o limite
        if (temperature > TEMP_THRESHOLD) {
            PORTB |= (1 << LED_PIN);  // Liga o LED (alerta de temperatura alta)
        } else {
            PORTB &= ~(1 << LED_PIN);  // Desliga o LED
        }

        _delay_ms(500);  // Aguarda 500ms antes de repetir o loop
    }
}
