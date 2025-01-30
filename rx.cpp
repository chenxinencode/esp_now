//接收端程序 
#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>


// 创建一个结构体接收数据
typedef struct struct_message {
//   int key_a_state;
//   int key_b_state;
//   int key_c_state;
  int left_joystickx_value;
  int left_joysticky_value;
//   int right_joystickx_value;
//   int right_joysticky_value;
} struct_message;


// 创建一个结构体变量
struct_message myData;

// 回调函数,当收到消息时会调佣该函数
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Char: ");
  Serial.println(myData.left_joystickx_value);
  Serial.print("Int: ");
  Serial.println(myData.left_joysticky_value);
 
  Serial.println();
}
 
void setup() {
  // 初始化串口波特率
  Serial.begin(115200);
  
  // 设置wifi模式 即无线终端
  WiFi.mode(WIFI_STA);

  // 初始化esp-now
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  //注册接收信息的回调函数
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {

}
