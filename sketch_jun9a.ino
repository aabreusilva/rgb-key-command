/*

<< INICIO - INFORMAÇÕES IMPORTANTES >>

TODOS OS NOSSOS PROJETOS SÃO BÁSICOS PARA INICIANTES COM ARDUINO.

!!! ATENÇÃO !!!
PARA O CORRETO FUNCIONAMENTO DESTE PROGRAMA, SIGA TODAS AS ORIENTAÇÕES QUE ESTÃO CONTIDAS NO EBOOK.

PROJETO 3
CONTROLE LEDS PELO TECLADO DO COMPUTADOR
NESTE PROJETO CONSTRUIREMOS UM CIRCUITO COM LEDS QUE SERÃO ACIONADOS POR COMANDOS DO TECLADO DO COMPUTADOR.
O EXEMPLO SERÁ COM LEDS, MAS VOCÊ PODE ACIONAR UMA LÂMPADA OU QUALQUER OUTRO DISPOSITIVO SEGUINDO ESTA LÓGICA.
AS LEITURAS SERÃO FEITAS NO SERIAL MONITOR (SIMBOLIZADO POR ESTA LUPA QUE FICA NA PARTE SUPERIOR DIREITA).

<< FIM - INFORMAÇÕES IMPORTANTES >>

*/

// << INÍCIO DO PROGRAMA >>

// A linha de código abaixo informa que o pino(porta) 9 do Arduino será utilizado para acender o LED, e armazena essa informação para usá-la ao longo do programa.
int led_amarelo = 9; // variável de nome <<led_amarelo>> do tipo inteiro <<int>> atribuída à porta digital <<9>> da placa

// A linha de código abaixo informa que o pino(porta) 11 do Arduino será utilizado para acender o LED, e armazena essa informação para usá-la ao longo do programa.
int led_verde = 11; // variável de nome <<led_verde>> do tipo inteiro <<int>> atribuída à porta digital <<11>> da placa

// A linha de código abaixo informa que o pino(porta) 13 do Arduino será utilizado para acender o LED, e armazena essa informação para usá-la ao longo do programa.
int led_vermelho = 13; // variável de nome <<led_vermelho>> do tipo inteiro <<int>> atribuída à porta digital <<13>> da placa

void setup() { // Nesta função são declarados todos os comandos de configuração do programa. Ela é executada uma única vez assim que a placa é ligada ou reiniciada.
  
  Serial.begin(9600); // Inicialização da comunicação serial, com velocidade de comunicação de 9600
  
  // pinMode --> seta o modo do pino (porta) como INPUT (entrada) ou OUTPUT (saída)
  pinMode(led_amarelo, OUTPUT); // variável de nome <<led_amarelo>> definida como modo <<OUTPUT>> (saída)
  pinMode(led_verde, OUTPUT); // variável de nome <<led_verde>> definida como modo <<OUTPUT>> (saída)
  pinMode(led_vermelho, OUTPUT); // variável de nome <<led_vermelho>> definida como modo <<OUTPUT>> (saída)
}

void loop() { // nesta função são declarados todos os comandos que rodarão em loop
  if(Serial.available()) // se(if) existe comunicação serial(serial.available), continue
  {
    char comando  = Serial.read(); // é criada uma variável de nome <<comando>> do tipo <<char>> (caracter) que armazenará
                                   // o caracter que será digitado
    
    switch (comando) { // o conteúdo da variável de nome <<comando>> é testado e será executado caso
                       // algumas das alternativas abaixo forem verdadeiras
    
      case 'y': // caso(case) a letra digitada for y o led amarelo será ligado

      /* digitalWrite --> esta função aciona um valor na porta digital. Existem 2 tipos de valores
                  --> HIGH(alto - ligado) ou LOW (baixo - desligado)
      */
      digitalWrite(led_amarelo, HIGH);  // escreve na porta digital da variável <<led_amarelo>> (porta digital 9) e define como <<HIGH>> (alto - ligado)
            
      // serial.println -->  esta função imprime os dados na tela e pula de linha         
      Serial.println("LED AMARELO LIGADO"); // imprime na tela as informações que constam entre aspas duplas
      Serial.println("EM 3 SEGUNDOS SERÁ DESLIGADO"); // imprime na tela as informações que constam entre aspas duplas
      delay(1000); // pausa por 1 segundo
      Serial.println("... 3 "); // aguarda 1 segundo e exibe a mensagem no serial monitor
      delay(1000); // pausa por 1 segundo
      Serial.println(".. 2 "); // aguarda 1 segundo e exibe a mensagem no serial monitor
      delay(1000); // pausa por 1 segundo
      Serial.println(". 1 "); // aguarda 1 segundo e exibe a mensagem no serial monitor
      delay(1000); // pausa por 1 segundo
      digitalWrite(led_amarelo, LOW); // aciona a porta digital da variável <<led_amarelo>> (porta digital 9) e define como <<LOW>> (baixo - desligado)
      delay(100); // pausa por 100 milisegundos
      Serial.println("LED AMARELO DESLIGADO"); // imprime na tela as informações que constam entre aspas duplas
      break; 

      /*
      Comando break
      Utilizamos este comando para especificar a última linha de código a ser executada dentro da condição. 
      Caso não seja não declarado, os códigos dentro dos cases posteriores serão executados. 
      */
      
      case 'g': // caso(case) a letra digitada for g o led verde será ligado
      digitalWrite(led_verde, HIGH); // aciona a porta digital da variável <<led_verde>> (porta digital 11) e define como <<HIGH>> (alto - ligado) 
      Serial.println("LED VERDE LIGADO"); // imprime na tela as informações que constam entre aspas duplas
      delay(2000); // pausa por 2 segundos
      digitalWrite(led_verde, LOW); // aciona a porta digital da variável <<led_verde>> (porta digital 11) e define como <<LOW>> (baixo - desligado)
      Serial.println("LED VERDE DESLIGADO"); // imprime na tela as informações que constam entre aspas duplas
      break;

      case 'r': // caso(case) a letra digitada for r o led vermelho será ligado
      digitalWrite(led_vermelho, HIGH); // aciona a porta digital da variável <<led_vermelho>> (porta digital 13) e define como <<HIGH>> (alto - ligado) 
      Serial.println("LED VERMELHO LIGADO"); // imprime na tela as informações que constam entre aspas duplas 
      delay(2000); // pausa por 2 segundos
      digitalWrite(led_vermelho, LOW); // aciona a porta digital da variável <<led_vermelho>> (porta digital 13) e define como <<LOW>> (baixo - desligado) 
      Serial.println("LED VERMELHO DESLIGADO"); // imprime na tela as informações que constam entre aspas duplas
      break;
      
    }
  }
}

// << FIM DO PROGRAMA >>
