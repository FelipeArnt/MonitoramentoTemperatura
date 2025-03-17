![Badge em Desenvolvimento](http://img.shields.io/static/v1?label=STATUS&message=EM%20DESENVOLVIMENTO&color=GREEN&style=for-the-badge)


# Projeto: Monitoramento de Temperatura com Arduino

Este projeto é um sistema simples de monitoramento de temperatura usando um Arduino. Ele lê a temperatura de um sensor conectado ao pino analógico A0 e aciona um LED se a temperatura ultrapassar um limite pré-definido. O valor da temperatura é exibido no monitor serial.

---

## 🛠️ Componentes Necessários
- **Arduino Uno** (ou qualquer outro modelo compatível)
- **Sensor de temperatura** (ex: LM35, TMP36 ou termistor)
- **LED** (para o alerta de temperatura alta)
- **Resistor** (220Ω para o LED)
- **Jumpers e protoboard** (para conexões)

---

## 📋 Esquema de Conexões
1. Conecte o sensor de temperatura ao pino analógico **A0** do Arduino.
2. Conecte o **LED** ao pino digital **2** do Arduino (com um resistor de 220Ω em série).
3. Alimente o circuito com o Arduino.

---

## 🚀 Como Usar
1. Conecte o Arduino ao computador via USB.
2. Abra o código no Arduino IDE.
3. Selecione a placa correta (`Arduino Uno`) e a porta serial.
4. Carregue o código no Arduino.
5. Abra o **Monitor Serial** (Ctrl+Shift+M) para visualizar a temperatura em tempo real.

---
