#include <esp-ai.h>
ESP_AI esp_ai;

void setup() {
  Serial.begin(115200);

  // [必  填] 是否调试模式， 会输出更多信息
  bool debug = true;

  // wifi 配置： { wifi 账号， wifi 密码 }  注意：要用双引号！
  // 不填则需要打开配网页面进行配网。填写则会自动连接wifi。
  ESP_AI_wifi_config wifi_config = { "网", "密码", "ESP-AI"  };

  // 或者直接秘钥配置上，这样就不用在配网页面配置了
  // 注意：设备需要和开放平台进行绑定，参见设备绑定： https://gitee.com/xm124/esp-ai-business-arduino 代码中的 esp_ai.onBindDevice 函数
  ESP_AI_server_config server_config = {"http", "node.espai.fun", 80, "api_key=5ad09a241c9f4edbae67e736ba3fd657"};

  // [必  填] 唤醒方案： { 方案, 语音唤醒用的阈值(本方案忽略即可), 引脚IO }
  //ESP_AI_wake_up_config wake_up_config = { "pin_high", 1, 10 };  // 如果按钮按下是低电平，那使用 pin_low 即可
  ESP_AI_wake_up_config wake_up_config = {};
  strcpy(wake_up_config.wake_up_scheme, "asrpro");  // 唤醒方案
  strcpy(wake_up_config.str, "start");  
  // 开始运行 ESP-AI
  esp_ai.begin({debug, wifi_config, server_config, wake_up_config });
}

void loop() {
  esp_ai.loop();
}
