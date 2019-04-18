#define CODE_WAITING 00
#define ACK_CONNECTED 01
#define CODE_READY 02
#define CODE_WARNING 03
#define CODE_DATA 10
#define 

int ID = 00;
int waiting = 00;
int upd_freq = 098;

bool started = false;

void beep(int code){
  //beep
}

void release_cargo(){
  //сбросить полезную нагрузку
}
void release_parachute(){
  //сбросить парашют
}

void sendRadio(String command):{
  //send_command
}

float[] get_telemetry(){
  //sfdgfdg
}

int get_code(){
  //sdf
}

String get_command(){
  //daed
}

void checkpoints(){
  //мише
}



void setup() {
  //подключение к периферии
  //выбор канала по умолчанию
  

}

void loop() {
  command = get_command();
  if (!started){
    while (get_code(command) != ACK_CONNECTED){
      beep(BEEP_WAITING);
      sendRadio(CODE_WAITING)}
    //while not datchiki norm
    //beep(warning);
    //sendRadio(warning)
    beep(BEEP_READY);
    sendRadio(CODE_READY)
    started = true
  if (started){
      
      else{
        sendRadio(get_telemetry());
        delay(upd_freq);
        if (get_code(command) == CODE_RELEASE_CARGO){
           release_cargo();   
        }
        if (get_code(command == CODE_RELEASE_PARACHUTE){
          release_parachute();
        }
      }
  }
  }

  
  // если не старт{
  // ожидаем подключения к ЦУПу
  // мигаем
  // если подключились{
  // конфигурируем канал
  // мигаем,пищим, но по другому
  // start = true}
  //}
  // если выста изменяется и start{
  //передаем телеметрию
  //принимаем данные
  //обрабатываем команды}
  // иначеесли пищим, передаем код приземления

}
