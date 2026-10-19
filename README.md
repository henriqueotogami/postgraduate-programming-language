# Programação Avançada de Microcontroladores e Arquitetura de Sistemas Embarcados

## 📌 Sobre o Repositório

Este repositório contém as implementações práticas, exercícios e estudos de arquitetura focados na disciplina de **Linguagem de Programação para Sistemas Embarcados**. Desenvolvido como parte do programa de pós-graduação, este módulo explora técnicas de projeto de software para microcontroladores (especificamente a plataforma ATmega32 / AVR), abordando desde designs do tipo *Super Loop* e máquinas de estado até interrupções de hardware e Sistemas Operacionais em Tempo Real (RTOS).

## 📚 Sumário

* [Visão Geral & Arquiteturas](#-visão-geral--arquiteturas)
* [Principais Tópicos Abordados](#-principais-tópicos-abordados)
* [Evolução da Arquitetura do Sistema](#-evolução-da-arquitetura-do-sistema)
* [Projetos Práticos](#-projetos-práticos)
* [Estrutura do Repositório](#-estrutura-do-repositório)
* [Ferramentas & Ambiente de Desenvolvimento](#-ferramentas--ambiente-de-desenvolvimento)
* [Autor & Créditos](#-autor--créditos)

## 🧠 Visão Geral & Arquiteturas

Ao projetar softwares embarcados para microcontroladores, a otimização do tempo de processamento, da latência e do uso de recursos é essencial. Este repositório cobre 4 estratégias fundamentais para melhorar o desempenho e a capacidade de resposta dos programas:

1. **Super Loop (Sequencial)**: Loop básico `while(true)` para polling simples de tarefas não críticas.
2. **Máquinas de Estado (FSM)**: Divisão de tarefas longas em estados pequenos e não bloqueantes para reduzir drasticamente o tempo total do loop principal.
3. **Interrupções de Hardware (ISR)**: Transferência do tratamento de eventos periódicos ou temporizados (como amostragem de ADC ou varredura de displays) para interrupções do CPU/periféricos.
4. **Sistemas Operacionais em Tempo Real (RTOS)**: Uso de estruturas de kernel preemptivo (ex: OSA RTOS) para isolar tarefas em *threads* dedicadas, gerenciar prioridades e sincronizar recursos de hardware compartilhados (UART, SPI, I2C, etc.).

## 🎯 Principais Tópicos Abordados

* **Arquitetura de Código em C Embarcado**: Modularização em camadas de Aplicação (`App`), drivers de periféricos (`bsp`, `uart`, `rfid`, `wifi`) e abstração de tempo (`ticks`).
* **Máquinas de Estados Finitos (FSM)**: Execução de tarefas sem bloqueio de CPU (*non-blocking*).
* **Periféricos de Microcontroladores**:
  * Timers e Interrupções de Hardware
  * Conversor Analógico-Digital (ADC)
  * Interfaces de Comunicação UART
* **Sistemas de Displays Multiplexados**: Acionamento de displays de 7 segmentos (Catodo Comum / Anodo Comum) via técnicas de varredura (*scanning*) para economia de pinos do microcontrolador e redução de consumo.
* **Conceitos de RTOS**: Preempção, tratamento de inversão de prioridade, *delays* bloqueantes vs. não-bloqueantes e bloqueio de recursos (*mutex/semáforos*).

## 📈 Evolução da Arquitetura do Sistema

```
[1. Super Loop]          [2. FSM]                [3. FSM + Interrupções]     [4. RTOS Preemptivo]
 ┌──────────────┐         ┌──────────────┐         ┌───────────────────┐        ┌───────────────────┐
 │ main()       │  ───►   │ FSM Task 1   │  ───►   │ Super Loop (Main) │ ───►   │ Task A (Thread)   │
 │ - Read ADC   │         │ FSM Task 2   │         │        +          │        │ Task B (Thread)   │
 │ - Update LCD │         └──────────────┘         │ ISRs de Hardware  │        │ Escalonador RTOS  │
 └──────────────┘                                  └───────────────────┘        └───────────────────┘
```

## 🛠 Projetos Práticos

### 1. Voltímetro com Display de 7 Segmentos Multiplexado (4 Dígitos)

* **Hardware**: Kit de desenvolvimento EasyAVR v7 / MCU ATmega32.
* **Técnicas Aplicadas**:
  * Leitura e conversão de tensão via ADC.
  * Multiplexação dos dígitos (`DIS0` - `DIS3`) orientada a Timer/FSM com tempo de acendimento de ~2ms por segmento.
  * Chaveamento via transistores de disparo na base para otimizar a contagem de pinos e picos de corrente.

### 2. Template Modular de Firmware para MCU

* **Estrutura de Módulos**:
  * `main.c` / `main.h`: Lógica de aplicação principal.
  * `bsp.c` / `bsp.h`: Board Support Package (Suporte a Hardware).
  * `ticks.c` / `ticks.h`: Temporização base da CPU / sistema.
  * `uart.c` / `uart.h`: Driver de comunicação serial.
  * `wifi.c` / `wifi_at.c`: Driver de comunicação Wi-Fi e comandos AT.

## 📂 Estrutura do Repositório

```
postgraduate-programming-language/
│
├── docs/                      # Slides, diagramas e materiais teóricos do curso
├── modules/                   # Drivers e arquivos de cabeçalho reutilizáveis (bsp, uart, ticks, etc.)
├── projects/
│   ├── 01_super_loop_adc/     # Leitura ADC sequencial (código base)
│   ├── 02_fsm_display7/       # Driver do display baseado em máquina de estados
│   ├── 03_isr_voltmeter/      # Voltímetro acionado por interrupções de Timer
│   └── 04_rtos_threads/       # Exemplo de implementação multitarefa com RTOS
└── README.md                  # Documentação do repositório
```

## 🛠 Ferramentas & Ambiente de Desenvolvimento

* **Microcontrolador Alvo**: Microchip / Atmel ATmega32
* **IDE**: Atmel Studio 7 / Microchip Studio
* **Compilador**: WinAVR (GCC Toolchain)
* **Compilador Alternativo**: mikroC PRO for AVR
* **Referência de RTOS**: OSA RTOS para microcontroladores
