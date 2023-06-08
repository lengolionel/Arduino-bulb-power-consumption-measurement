int bulb = 2;
int bulb_watts = 5;
int state;
unsigned long start_time = 0;
unsigned long end_time = 0;
unsigned long elapsed = 0;
float consumed = 0;

void setup() {
  pinMode(bulb,OUTPUT);
  Serial.begin(9600);
  digitalWrite(bulb, 1);
}

void loop() {
  if(Serial.available() > 0){
      state = Serial.read();
      if(state == '1'){
        digitalWrite(bulb, 0);
        start_time = millis();
        }
       else if(state == '2'){
        digitalWrite(bulb, 1);
        end_time = millis(); 
        elapsed = end_time -start_time;
        consumed = (elapsed / 1000) * bulb_watts;
        Serial.println("Power consumption:");
        Serial.println("--------------------");
        Serial.print(consumed);
        Serial.println("Watts");
        Serial.print(elapsed / 1000);
        Serial.println("Seconds");
        }
      
    }

}
