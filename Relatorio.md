# Placar de Futsal feito para PICgenios com PIC18F4520 utilizando o simulador PicsimLab
O projeto consiste em um Placar Eletrônico para Futsal, onde o tempo é exibido em um display de 7 segmentos e todas as informações da partida exibidas no display LCD, e as funções do placar seriam controladas pelo teclado matricial da placa.

Neste projeto foram utilizados os softwares MPLAB X IDE v5.40, com o compilador XC8 v2.20 e o simulador da PICgenios, o PicsimLab v0.8.2 utilizando o PIC18F4520. O intuito desse projeto foi consolidar o conteúdo teórico da disciplina de Programação Embarcada da Universidade Federal de Itajubá (Unifei), utilizando a Linguagem C.

Todas as bibliotecas necessárias para replicar o projeto estão junto à pasta do projeto, a autoria das bibliotecas bem como os direitos autorais estão asseguradas ao professor Rodrigo Maximiano Antunes de Almeida e ao criador do PicsimLab, Luis Claudio Gambôa Lopes.

O conhecimento necessário para a realização do projeto está voltado para a programação em Linguagem C, os periféricos utilizados da placa PICgenios foram:
Barramento de Leds;
- Buzzer;
- Cooler;
- Display LCD 16x4;
- Display 7 Segmentos;
- Reles;
- RTC; 
- Timer;
- Teclado Matricial.

## Passo 1: Planejamento

Foi elaborado um escopo do projeto já pensando na função de cada periférico, onde foi definido desde o início os seguintes itens:
- Display LCD 16x4 – exibição de todas as informações referentes ao jogo, como local e data ao iniciar, placar com os times, e quaisquer informações relevantes da partida além das propagandas;
- Display 7 Segmentos – Exibição do tempo da partida, decrescendo de 20 minutos até 0 (como em uma partida de futsal);
- Cooler e buzzer – acionados ao haver gols;
- Barramento de Leds – acionados ao iniciar a partida e em gols.
- Reles – acionados em gols, e ao aplicar cartões (amarelo – 1 rele, vermelho – 2 reles);

## Passo 2: Estrutura do Projeto
Ao iniciar o desenvolvimento do código no MPLAB X IDE, foi adicionado todas as bibliotecas necessárias para realizar a implementação do código, e também foram declaras no arquivo `main.c` do projeto. Foi necessário realizar uma modificação pequena a fim de facilitar a utilização do display LCD 16x4, adicionando as linhas 37 e 38 ao arquivo `lcd.h`, para facilitar o acesso às linhas 3 e 4 do display LCD.

![lcd h-foto](https://user-images.githubusercontent.com/73919181/101433494-386af080-38e9-11eb-94fe-0a96c5cdb7dd.png)

A partir daí, no código principal foram inicializados todos os periféricos e iniciou-se a modelagem da aparência do Placar, onde há uma animação no início com o símbolo da Unifei e é exibido informações do local da partida, a data e os times participantes.

![LCD-inicio](https://user-images.githubusercontent.com/73919181/101433265-25f0b700-38e9-11eb-9e9e-7c66faedbcab.png)

Durante o andamento da partida é exibida a mensagem de “Em andamento” e a etapa em que o jogo se encontra (1º ou 2º tempo) e o display de 7 segmentos exibe o tempo.

![lcd-andamento](https://user-images.githubusercontent.com/73919181/101433197-0e193300-38e9-11eb-83ea-a0c40282201e.png)
 
A última exibição diferente do LCD é o menu de faltas, onde pode-se marcar quantos cartões amarelos e vermelhos cada time possui.

![lcd-faltas](https://user-images.githubusercontent.com/73919181/101433154-ffcb1700-38e8-11eb-9d63-5337b81f3d07.png)
 
Foi criada uma imagem com legendas para o teclado matricial para melhor orientar sobre os comandos.

![Legenda-teclado](https://user-images.githubusercontent.com/73919181/101433137-f346be80-38e8-11eb-8b8b-1ce6e655cc41.png)

## Passo 3: Desenhando no LCD
Para desenhar no LCD uma informação muito importante é o fato de que os desenhos não podem ultrapassar 64 bytes, ou seja, 8 caracteres do display, e essa informação foi crucial na elaboração e na mudança das propagandas presentes no projeto. 

Para elaborar os desenhos das propagandas foram utilizados dois sites, todos com serviços gratuitos. O primeiro site é o https://www.pixilart.com/, e foi utilizado para desenhar as imagens pixel a pixel, já o segundo site é o https://maxpromer.github.io/LCD-Character-Creator/, utilizado para transformar cada pixel de um display LCD com caracteres de 8x5 pixels em um código hexadecimal referente a cada linha de cada caractere. 

O código exemplo a seguir mostra como as imagens foram exibidas no LCD, o vetor `chevrolet_logo[]` possui o código linha a linha de cada caractere, é então configurado o LCD para a primeira posição de memória e então é enviado com o comando `lcd_dat(chevrolet_logo[i])` dentro do for de mesmo tamanho do vetor, todas as linhas em sequência para que a imagem seja exibida corretamente.

![chevrolet-codi](https://user-images.githubusercontent.com/73919181/101433075-cf837880-38e8-11eb-9bb5-14ee4a2bf708.png)

## Passo 4: Dificuldades e Soluções
Como dito no passo 3, o display LCD é limitado a desenhos de até 64 bytes, e isso fez com que algumas propagandas fossem alteradas ao decorrer do projeto, para adequar ao tamanho máximo. Assim, utilizando o símbolo das propagandas sendo enviados para o LCD da forma exibida no passo 3, com o comando `lcd_str(“string”)`, foi adicionado algumas informações a mais às propagandas.

Outra dificuldade foi a contagem do tempo durante a exibição das propagandas, pois no tempo exibição das propagandas, o contador de tempo do jogo era pausado, dentre muitas formas de resolver o problema, foi calculado o tempo médio de duração das propagandas e então subtraído do tempo de partida.

O flicker do display de 7 segmentos por conta da utilização do timer também ocasionou problemas com o decremento de tempo, mas baseado no valor do timer, foi utilizado uma variável inteira t que servia para definir de quanto em quanto tempo seria decrementada, onde um cálculo aproximado seria de que, para o timer com 5ms, a variável `t` incrementando até 200 o tempo decresceria em aproximadamente 1s a cada 1s real.

![tempo-cod](https://user-images.githubusercontent.com/73919181/101432982-a19e3400-38e8-11eb-91c6-e563603b8e14.png)
 
Alguns problemas de organização do código surgiram e com algumas dicas dos professores @Otávio e @rmaalmeida (responsáveis pela disciplinas) o código foi aprimorado para ficar menos repetitivo, ter menos loops infinitos do que o necessário, apenas um `kpDebounce()` (função de debounce do teclado) por loop (há dois loops `for(;;);` pelo fato que o primeiro mantém a placa em um estado de pré inicialização). Com essa melhor organização também foi possível utilizar uma flag para verificar quantas vezes os botões foram apertados, para melhor funcionamento das funções.

## Passo 5: Funcionamento do Placar
Ao iniciar a placa haverá uma animação e ao terminar para iniciar a contagem de tempo todas as outras funções basta apertar o botão #, e toda vez que o tempo for pausado esse mesmo botão reinicia a contagem do tempo. Com a placa em funcionamento os botões 1 e 2 contabilizam gols, o botão 4 indica bola fora e pausa o tempo, o botão 5 entra no menu de faltas (nele é apresentado a quantidade de cartões de cada time, os botões 1 e 4 são para contabilizar cartões amarelos pro time A e B respectivamente, e os botões 3 e 6, cartões vermelhos para A e B, respectivamente), os botões 7, 8 e 9 são utilizados para as propagandas.


