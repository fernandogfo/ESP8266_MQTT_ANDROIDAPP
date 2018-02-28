//  ____           _                               _     _
// |  _ \   _ __  | |      _   _   _ __     __ _  | |_  (_)   ___
// | | | | | '__| | |     | | | | | '_ \   / _` | | __| | |  / __|
// | |_| | | |    | |___  | |_| | | | | | | (_| | | |_  | | | (__
// |____/  |_|    |_____|  \__,_| |_| |_|  \__,_|  \__| |_|  \___|

//28/02/18
//https://github.com/DrLunatic
package com.example.ferna.mqtt;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;

import org.eclipse.paho.android.service.MqttAndroidClient;
import org.eclipse.paho.client.mqttv3.*;

import static android.content.ContentValues.TAG;

public class MainActivity extends Activity {

    Button btnLiga, btnDesliga;
    static String MQTTHOST = "tcp://SERVIDOR:PORTA"; //EXEMPLO - EXAMPLE: "tcp://m10.cloudmqtt.com:18888"
    static String USERNAME = "";//USUARIO MQTT - USER MQTT
    static String PASSWORD = "";//SENHA MQTT - PASSWORD MQTT
    String topicStr = "";//TOPICO MQTT - TOPIC MQTT

    MqttAndroidClient client;//Declara o client

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnLiga = findViewById(R.id.btnLiga); //Botão liga - turn on Button
        btnDesliga = findViewById(R.id.btnDesliga);//Botão desliga - turn off button
        String clientId = MqttClient.generateClientId();//Cria um id cliente - generate client ID
        client = new MqttAndroidClient(this.getApplicationContext(), MQTTHOST,
                clientId);

        MqttConnectOptions options = new MqttConnectOptions();//caso seu serviço MQTT tenha login e senha
        options.setUserName(USERNAME);                        //if your MQTT service needs a authentication
        options.setPassword(PASSWORD.toCharArray());

        try {
            IMqttToken token = client.connect(options);
            token.setActionCallback(new IMqttActionListener() {
                @Override
                public void onSuccess(IMqttToken asyncActionToken) {
                    // We are connected
                    Log.d(TAG, "conectado");
                }

                @Override
                public void onFailure(IMqttToken asyncActionToken, Throwable exception) {
                    // Something went wrong e.g. connection timeout or firewall problems
                    Log.d(TAG, "Nada conectado");

                }
            });
        } catch (MqttException e) {
            e.printStackTrace();
        }

    }
    //evento botão liga - event button on
    public void pub(View view){
        System.out.println("FUNCIONOU");
        String topic = topicStr;
        String message = "0";//mensagem a ser envia ao topico - message to be sent to the topic
        try {//publica no tópico escolhido - publishes on chosen topic
            client.publish(topic, message.getBytes(), 0, false);
        } catch (MqttException e) {
            e.printStackTrace();
        }
    }

    public void pub2(View view){
        System.out.println("FUNCIONOU");
        String topic = topicStr;
        String message = "1";//mensagem a ser envia ao topico - message to be sent to the topic
        try {//publica no tópico escolhido - publishes on chosen topic
            client.publish(topic, message.getBytes(), 0, false);
        } catch (MqttException e) {
            e.printStackTrace();
        }
    }

}