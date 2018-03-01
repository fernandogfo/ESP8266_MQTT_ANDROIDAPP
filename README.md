```sh
  ____           _                               _     _
 |  _ \   _ __  | |      _   _   _ __     __ _  | |_  (_)   ___
 | | | | | '__| | |     | | | | | '_ \   / _` | | __| | |  / __|
 | |_| | | |    | |___  | |_| | | | | | | (_| | | |_  | | | (__
 |____/  |_|    |_____|  \__,_| |_| |_|  \__,_|  \__| |_|  \___|
```

# Controlando ESP8266 utilizando aplicativo android via MQTT / Control ESP8266 with android app via MQTT

### NODEMCU ESP8266 Circuit

 * [ESP8266 CIRCUIT](https://github.com/DrLunatic/ESP8266_MQTT_ANDROIDAPP/blob/master/NODEMCU%20ESP8266%20CIRCUIT.png)
 
### Código/Code ESP8266: "Needs to be commented in English"

* [ESP8266 CODE](https://github.com/DrLunatic/ESP8266_MQTT_ANDROIDAPP/blob/master/ESP8266_MQTT.ino)

### Código/Code Android APP:

* [Código Classe principal/Main Class Code](https://github.com/DrLunatic/ESP8266_MQTT_ANDROIDAPP/blob/master/AndroidAppMainClassCODE)

* [Aplicativo pronto/APP](https://github.com/DrLunatic/ESP8266_MQTT_ANDROIDAPP/tree/master/MQTT_AndroidApp)

### Lembre-se/Remember:

- Permissões de acesso e o Serviço Paho MqttService no Android Manifest.xml / User permission and Paho MqttService on AndroidManifest.xml:
```sh
        <uses-permission android:name="android.permission.WAKE_LOCK" />
        <uses-permission android:name="android.permission.INTERNET" />
        <uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
        <uses-permission android:name="android.permission.READ_PHONE_STATE" />
```
```sh
        <service android:name="org.eclipse.paho.android.service.MqttService" >
        </service>
```

- Repositório Maven e Dependencias no build gradle do app / Repositories Maven and Dependencies on build gradle of the app:
```sh
        repositories {
         maven {
             url "https://repo.eclipse.org/content/repositories/paho-releases/"
                    }
                    }
```
```sh
         dependencies {
             compile('org.eclipse.paho:org.eclipse.paho.android.service:1.0.2') {
                    exclude module: 'support-v4'
          }
          }
```

### License
### MIT
