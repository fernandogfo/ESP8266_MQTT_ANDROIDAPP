//  ____           _                               _     _        
// |  _ \   _ __  | |      _   _   _ __     __ _  | |_  (_)   ___ 
// | | | | | '__| | |     | | | | | '_ \   / _` | | __| | |  / __|
// | |_| | | |    | |___  | |_| | | | | | | (_| | | |_  | | | (__ 
// |____/  |_|    |_____|  \__,_| |_| |_|  \__,_|  \__| |_|  \___|
                                                                
//28/02/18
//https://github.com/DrLunatic
 
#include <ESP8266WiFi.h>//=============================================Wifi
#include <PubSubClient.h>//=========================Instale essa biblioteca
 
#define DEBUG
 
 
//informações da rede WIFI
const char* ssid = "****";//==========================Insira o SSID da rede
const char* password =  "***********";//=========================Senha WIFI
 
//Crie sua conta no CloudMQTT e coloque as informações de acesso abaixo
const char* mqttServer = "m13.cloudmqtt.com";//=====================server
const char* mqttUser = "********";//==================================user
const char* mqttPassword = "************";//======================password
const int mqttPort = *****;//=========================================port
const char* mqttTopicSub ="*******";//=================tópico do websocket

#define LED 5
 
WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {
 
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    #ifdef DEBUG
    Serial.println("WiFi, Conectando...");
    #endif
  }
  #ifdef DEBUG
  Serial.println("WiFi, Conectado!");
  #endif
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    #ifdef DEBUG
    Serial.println("Iniciando Broker MQTT...");
    #endif
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
      #ifdef DEBUG
      Serial.println("Conectado");  
      #endif
 
    } else {
      #ifdef DEBUG 
      Serial.print("Não conectado: ");
      Serial.print(client.state());
      #endif
      delay(2000);
 
    }
  }
 
  //subscreve no tópico
  client.subscribe(mqttTopicSub);
 
}
 
void callback(char* topic, byte* payload, unsigned int length) {
 
  //armazena msg recebida na mensagem
  payload[length] = '\0';
  String mensagem = String((char*)payload);
 
  #ifdef DEBUG
  Serial.print("Mensagem do tópico: ");
  Serial.println(topic);
  Serial.print("Conteúdo: ");
  Serial.print(mensagem);
  Serial.println();
  Serial.println("******************************");
  #endif
 
  if (mensagem == "1"){         //se for 1
     digitalWrite(LED, LOW);  //Muda led para low
  }else if (mensagem == "0"){   //se for 0
     digitalWrite(LED, HIGH);   //Muda led para high
  }
 
}
 
//função pra reconectar servidor MQTT
void reconect() {
  while (!client.connected()) {
    #ifdef DEBUG
    Serial.print("Conectando ao servidor MQTT");
    #endif
     
    bool conectado = strlen(mqttUser) > 0 ?
                     client.connect("ESP8266Client", mqttUser, mqttPassword) :
                     client.connect("ESP8266Client");
 
    if(conectado) {
      #ifdef DEBUG
      Serial.println("Conectado!");
      #endif
      //subscreve no tópico
      client.subscribe(mqttTopicSub, 1); //nivel de qualidade: QoS 1
    } else {
      #ifdef DEBUG
      Serial.println("Falha durante a conexão.Code: ");
      Serial.println( String(client.state()).c_str());
      Serial.println("Tentando novamente em 10 s");
      #endif
      //Aguarda 10 segundos 
      delay(10000);
    }
  }
}
 
void loop() {
  if (!client.connected()) {
    reconect();
  }
  client.loop();
}

//Código original criado por Fábio Souza e reescrito por DrLunatic
