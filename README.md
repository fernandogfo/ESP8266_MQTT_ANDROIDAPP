Controlando ESP8266 utilizando aplicativo android via MQTT / Control ESP8266 with android app via MQTT
-----------------------------------------------------------
Código/Code ESP8266
-----------------------------------------------------------
- ESP8266 - https://github.com/DrLunatic/ESP8266_MQTT_ANDROIDAPP/blob/master/ESP8266_MQTT.ino

Código/Code Android APP
----------------------------------------------------------
- Classe principal/Main Class - https://github.com/DrLunatic/ESP8266_MQTT_ANDROIDAPP/blob/master/AndroidAppMainClassCODE
- Aplicativo/APP - https://github.com/DrLunatic/ESP8266_MQTT_ANDROIDAPP/tree/master/MQTT_AndroidApp

Lembre-se/Remember
----------------------------------------------------------
- Permissões e o Serviço Paho MqttService no Android Manifest.xml / User permission and Paho MqttService on AndroidManifest.xml:

<uses-permission android:name="android.permission.WAKE_LOCK" />
<uses-permission android:name="android.permission.INTERNET" />
<uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
<uses-permission android:name="android.permission.READ_PHONE_STATE" />

  <service android:name="org.eclipse.paho.android.service.MqttService" >
  </service>

- Repositório Maven e Dependencias no build gradle do app / Repositories Maven and Dependencies on build gradle of the app:
    repositories {
    maven {
        url "https://repo.eclipse.org/content/repositories/paho-releases/"
    }

    dependencies {
        compile('org.eclipse.paho:org.eclipse.paho.android.service:1.0.2') {
            exclude module: 'support-v4'
    }
